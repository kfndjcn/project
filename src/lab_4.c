#include <stdio.h>
#include "../include/lab_4.h"

// Обработка строки для основного задания (без записи в файл)
void process_line(char buffer[]) {
    char allowed_chars[] = "abcdefghijklmnopqrstuvwxyz";
    char c;
    int flag;
    int word_valid;
    int i;
    int pos;
    int start;
    int j;
    int k;

    flag = NO;
    word_valid = YES;
    start = 0;
    i = 0;
    pos = 0;

    do {
        c = buffer[i];
        if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0') {
            if (flag == YES) {
                if (word_valid == YES) {
                    for (j = start; j < i; j++) {
                        buffer[pos++] = buffer[j];
                    }
                }
                flag = NO;
                word_valid = YES;
            }
            if (c != '\0') {
                buffer[pos++] = c;
            }
        } else {
            if (flag == NO) {
                start = i;
                word_valid = YES;
                flag = YES;
            }
            if (word_valid == YES) {
                int char_allowed = NO;
                for (k = 0; allowed_chars[k] != '\0'; k++) {
                    if (c == allowed_chars[k]) {
                        char_allowed = YES;
                        break;
                    }
                }
                if (char_allowed == NO) {
                    word_valid = NO;
                }
            }
        }
        i++;
    } while (c != '\0');

    buffer[pos] = '\0';
}

// Обработка строки для дополнительного задания (с записью удалённых слов в файл)
void process_line_with_file(char buffer[]) {
    char allowed_chars[] = "abcdefghijklmnopqrstuvwxyz";
    char c;
    int flag;
    int word_valid;
    int i;
    int pos;
    int start;
    int j;
    int k;

    FILE *removed_file = fopen("removed_words.txt", "w");
    if (removed_file == NULL) {
        printf("Ошибка открытия файла!\n");
        return;
    }

    fprintf(removed_file, "Удалённые слова:\n");
    fprintf(removed_file, "==================\n");

    flag = NO;
    word_valid = YES;
    start = 0;
    i = 0;
    pos = 0;

    do {
        c = buffer[i];
        if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0') {
            if (flag == YES) {
                if (word_valid == YES) {
                    // Копируем подходящее слово в результат
                    for (j = start; j < i; j++) {
                        buffer[pos++] = buffer[j];
                    }
                } else {
                    // Записываем неподходящее слово в файл
                    fprintf(removed_file, "Удалено: ");
                    for (j = start; j < i; j++) {
                        fprintf(removed_file, "%c", buffer[j]);
                    }
                    fprintf(removed_file, "\n");
                }
                flag = NO;
                word_valid = YES;
            }
            if (c != '\0') {
                buffer[pos++] = c;
            }
        } else {
            if (flag == NO) {
                start = i;
                word_valid = YES;
                flag = YES;
            }
            if (word_valid == YES) {
                int char_allowed = NO;
                for (k = 0; allowed_chars[k] != '\0'; k++) {
                    if (c == allowed_chars[k]) {
                        char_allowed = YES;
                        break;
                    }
                }
                if (char_allowed == NO) {
                    word_valid = NO;
                }
            }
        }
        i++;
    } while (c != '\0');

    buffer[pos] = '\0';

    fprintf(removed_file, "==================\n");
    fprintf(removed_file, "Результат: %s\n", buffer);

    fclose(removed_file);
    printf("Удалённые слова сохранены в файл 'removed_words.txt'\n");
}

// Основное задание
void lab_4_main(void) {
    char line[MAXLINE];

    printf("\n=== lab 4 (main) ===\n");
    printf("enter a line: ");
    fgets(line, MAXLINE, stdin);

    // Удаляем cимвол новой строки
    for (int i = 0; i < MAXLINE; i++) {
        if (line[i] == '\n') {
            line[i] = '\0';
            break;
        }
    }

    process_line(line);
    printf("Результат: %s\n", line);
}

// Дополнительное задание
void lab_4_extra(void) {
    char line[MAXLINE];

    printf("\n=== lab 4 (extra) ===\n");
    printf("enter a line: ");
    fgets(line, MAXLINE, stdin);

    // Удаляем символ новой строки
    for (int i = 0; i < MAXLINE; i++) {
        if (line[i] == '\n') {
            line[i] = '\0';
            break;
        }
    }

    process_line_with_file(line);
    printf("result: %s\n", line);
}
