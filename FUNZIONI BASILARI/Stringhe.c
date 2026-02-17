#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 256
#define MAX_TEXT 10000

// === PROTOTIPI DI FUNZIONE ===
void to_uppercase(char *str);
int count_word_occurrences(const char *text, const char *word);
void replace_word(char *text, const char *oldWord, const char *newWord);

// === DEFINIZIONE FUNZIONI ===

// Funzione per convertire una stringa in maiuscolo
void to_uppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

// Funzione per contare le occorrenze di una parola
int count_word_occurrences(const char *text, const char *word) {
    int count = 0;
    const char *pos = text;
    size_t len = strlen(word);

    while ((pos = strstr(pos, word)) != NULL) {
        count++;
        pos += len;
    }
    return count;
}

// Funzione per sostituire una parola con un'altra
void replace_word(char *text, const char *oldWord, const char *newWord) {
    char buffer[MAX_TEXT];
    char *insert_point = buffer;
    const char *tmp = text;
    size_t oldLen = strlen(oldWord);
    size_t newLen = strlen(newWord);

    if (oldLen == 0) { // evita loop infinito
        return;
    }

    while (1) {
        const char *p = strstr(tmp, oldWord);
        if (p == NULL) {
            // copia il resto
            size_t tailLen = strlen(tmp);
            if ((insert_point - buffer) + tailLen >= MAX_TEXT) {
                // tronchiamo per evitare overflow
                tailLen = MAX_TEXT - 1 - (insert_point - buffer);
            }
            memcpy(insert_point, tmp, tailLen);
            insert_point += tailLen;
            break;
        }

        // copia il segmento prima della occorrenza
        size_t chunkLen = p - tmp;
        if ((insert_point - buffer) + chunkLen >= MAX_TEXT) {
            chunkLen = MAX_TEXT - 1 - (insert_point - buffer);
            memcpy(insert_point, tmp, chunkLen);
            insert_point += chunkLen;
            break;
        }
        memcpy(insert_point, tmp, chunkLen);
        insert_point += chunkLen;

        // copia la newWord
        if ((insert_point - buffer) + newLen >= MAX_TEXT) {
            // se non c'è spazio sufficiente, copia quanto possibile e termina
            size_t canCopy = MAX_TEXT - 1 - (insert_point - buffer);
            memcpy(insert_point, newWord, canCopy);
            insert_point += canCopy;
            break;
        }
        memcpy(insert_point, newWord, newLen);
        insert_point += newLen;

        // avanza oltre la oldWord nell'input
        tmp = p + oldLen;
    }

    *insert_point = '\0';
    // copia risultato nella stringa originale
    strncpy(text, buffer, MAX_TEXT - 1);
    text[MAX_TEXT - 1] = '\0';
}

// === FUNZIONE PRINCIPALE ===
int main() {
    char filename[50];
    FILE *fin;
    char line[MAX_LINE];
    char text[MAX_TEXT] = "";
    int lineCount = 0, wordCount = 0, charCount = 0;
    int inWord = 0;

    printf("Inserisci il nome del file da leggere: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    fin = fopen(filename, "r");
    if (!fin) {
        printf("Errore: impossibile aprire il file %s\n", filename);
        return 1;
    }

    // Lettura e analisi del testo
    while (fgets(line, sizeof(line), fin)) {
        strcat(text, line);
        lineCount++;

        for (int i = 0; line[i] != '\0'; i++) {
            if (isalpha((unsigned char)line[i])) {
                charCount++;
                if (!inWord) {
                    inWord = 1;
                    wordCount++;
                }
            } else {
                inWord = 0;
            }
        }
    }
    fclose(fin);

    double avgLength = (wordCount > 0) ? (double)charCount / wordCount : 0.0;

    int scelta;
    char searchWord[30], oldWord[30], newWord[30];

    do {
        printf("\n=== MENU OPERAZIONI ===\n");
        printf("1. Visualizza testo originale\n");
        printf("2. Converti tutto in maiuscolo\n");
        printf("3. Conta occorrenze di una parola\n");
        printf("4. Sostituisci una parola\n");
        printf("5. Salva report e testo modificato\n");
        printf("0. Esci\n");
        printf("Seleziona un'opzione: ");
        scanf("%d", &scelta);
        getchar(); // per consumare il carattere '\n'

        switch (scelta) {
            case 1:
                printf("\n--- Testo originale ---\n%s\n", text);
                break;

            case 2:
                to_uppercase(text);
                printf("\nTesto convertito in maiuscolo.\n");
                break;

            case 3:
                printf("Inserisci la parola da cercare: ");
                fgets(searchWord, sizeof(searchWord), stdin);
                searchWord[strcspn(searchWord, "\n")] = '\0';
                printf("Occorrenze trovate: %d\n", count_word_occurrences(text, searchWord));
                break;

            case 4:
                printf("Inserisci la parola da sostituire: ");
                fgets(oldWord, sizeof(oldWord), stdin);
                oldWord[strcspn(oldWord, "\n")] = '\0';
                printf("Inserisci la nuova parola: ");
                fgets(newWord, sizeof(newWord), stdin);
                newWord[strcspn(newWord, "\n")] = '\0';
                replace_word(text, oldWord, newWord);
                printf("Sostituzione completata.\n");
                break;

            case 5: {
                FILE *fout = fopen("report.txt", "w");
                fprintf(fout, "=== Report Analisi File ===\n");
                fprintf(fout, "File analizzato: %s\n", filename);
                fprintf(fout, "Numero di righe: %d\n", lineCount);
                fprintf(fout, "Numero di parole: %d\n", wordCount);
                fprintf(fout, "Lunghezza media parole: %.2f\n", avgLength);
                fclose(fout);

                fout = fopen("output.txt", "w");
                fprintf(fout, "%s", text);
                fclose(fout);

                printf("Report salvato in 'report.txt' e testo in 'output.txt'\n");
                break;
            }

            case 0:
                printf("Uscita dal programma...\n");
                break;

            default:
                printf("Scelta non valida!\n");
                break;
        }
    } while (scelta != 0);

    return 0;