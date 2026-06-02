#include <stdio.h>
#include <ctype.h>
#include "../include/lab_3.h"

// Проверяет, все ли буквы в слове уникальные
int all_unique(const char word[]) {
    int i, j;
    for (i = 0; word[i] != '\0'; i++) {
        for (j = i + 1; word[j] != '\0'; j++) {
            if (word[i] == word[j]) {
                return 0; // есть повтор букв
            }
        }
    }
    return 1; // все буквы разные
}

// Проверяет, является ли символ латинской буквой
int is_latin_letter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Копирует строку
void copy_word(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Основное задание
void lab_3_main(void) {
    char c;
    char word[100];
    int i = 0;      // сколько букв уже записано в слово
    int count = 0;  // количество слов с уникальными буквами

    printf("\n=== lab 3 (main) ===\n");
    printf("enter text. when finish click '#':\n");

    while ((c = getchar()) != '#') {
        if (isalpha((unsigned char)c)) {
            if (i < 99) {
                word[i++] = c;
            }
        } else {
            if (i > 0) {
                word[i] = '\0';
                if (all_unique(word)) {
                    count++;
                }
                i = 0;
            }
        }
    }

    // Проверяем последнее слово (если текст закончился без разделителя)
    if (i > 0) {
        word[i] = '\0';
        if (all_unique(word)) {
            count++;
        }
    }

    printf("amount of words: %d\n", count);
}

// Дополнительное задание
void lab_3_extra(void) {
    int c;
    char word[100];
    char longest[100] = "";
    int i = 0;              // сколько букв уже записано в слово
    int count = 0;          // количество слов с уникальными буквами
    int longest_len = 0;    // длина самого длинного подходящего слова

    printf("\n=== lab 3 (additional) ===\n");
    printf("enter text. when finish click Ctrl+Z (Windows) или Ctrl+D (Linux):\n");

    while ((c = getchar()) != EOF) {
        if (is_latin_letter((char)c)) {
            if (i < 99) {
                word[i++] = (char)c;
            }
        } else {
            if (i > 0) {
                word[i] = '\0';
                if (all_unique(word)) {
                    count++;
                    if (i > longest_len) {
                        longest_len = i;
                        copy_word(longest, word);
                    }
                }
                i = 0;
            }
        }
    }

    // Проверяем последнее слово
    if (i > 0) {
        word[i] = '\0';
        if (all_unique(word)) {
            count++;
            if (i > longest_len) {
                longest_len = i;
                copy_word(longest, word);
            }
        }
    }

    printf("amount of words %d\n", count);
    if (longest_len > 0) {
        printf("longest word: %s (длина: %d)\n", longest, longest_len);
    } else {
        printf("no words.\n");
    }
}
