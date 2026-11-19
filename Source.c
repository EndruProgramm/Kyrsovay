#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() 
{
    setlocale(LC_ALL, "Russian");

    int M, N;
    int choice1, choice2, choice3;
    int c, d;
    printf("*******************************************************************************\n");
    printf("* Курсовой проект по дисциплине: \"Основы программирования и алгоритмизации\"   *\n");
    printf("* Тема: \"Реализация динамического многомерного массива\"                       *\n");
    printf("* Выполнил: Радченко А.И., группа боти-262                                    *\n");
    printf("*******************************************************************************\n\n");
    do {
        do {
            printf("Введите количество строк M (M: ");
            scanf("%d", &M);
            printf("Введите количество столбцов N: ");
            scanf("%d", &N);
            }
            while (M <= 0 || N <= 0);

        int* R = (int*)calloc(M * N, sizeof(int));
        if (R == NULL) {
            printf("Ошибка выделения памяти!\n");
            return 1;
        }
        printf("\nВыберите способ заполнения массива:\n");
        printf("1 - Ввод с консоли\n");
        printf("2 - Рандомный выбор\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice1);

        if (choice1 == 1) {
            printf("Введите элементы матрицы R[%d][%d]:\n", M, N);
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    printf("R[%d][%d] = ", i + 1, j + 1);
                    scanf("%d", &R[i * N + j]);
                }
            }
        }
        else {
            int min_val, max_val;
            printf("Введите нижнюю границу случайных чисел: ");
            scanf("%d", &min_val);
            printf("Введите верхнюю границу случайных чисел: ");
            scanf("%d", &max_val);
            if (min_val > max_val) {
                int p = min_val;
                min_val = max_val;
                max_val = p;
            }
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    R[i * N + j] = min_val + rand() % (max_val - min_val + 1);
                }
            }
        }
        printf("\nВведите искомое значение c: ");
        scanf("%d", &c);
        printf("Введите множитель на что надо будет умножить всю строку d: ");
        scanf("%d", &d);

        printf("\nВывести исходный массив на экран? (1 - Да, 0 - Нет): ");
        scanf("%d", &choice2);
        if (choice2 == 1) {
            printf("\nИсходная матрица R:\n");
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    printf("%5d ", R[i * N + j]);
                }
                printf("\n");
            }
        }

        int found_any = 0;
        printf("\nРезультат поиска:\n");
        printf("Номера строк, содержащих элемент %d: ", c);

        for (int i = 0; i < M; i++) {
            int c1 = 0;
            for (int j = 0; j < N; j++) {
                if (R[i * N + j] == c) {
                    c1 = 1;
                    break;
                }
            }
            if (c1) {
                printf("%d ", i + 1);
                found_any = 1;
                for (int j = 0; j < N; j++) {
                    R[i * N + j] *= d;
                }
            }
        }

        if (!found_any) {
            printf("таких строк не найдено.");
        }
        printf("\n");
        printf("\nВывести готовый массив на экран? (1 - Да, 0 - Нет): ");
        scanf("%d", &choice2);
        if (choice2 == 1) {
            printf("\nПреобразованная матрица R (подходящие строки умножены на %d):\n", d);
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    printf("%5d ", R[i * N + j]);
                }
                printf("\n");
            }
        }
        free(R);

        printf("\nЖелаете продолжить работу с программой? (1 - Да, 0 - Выход): ");
        scanf("%d", &choice3);
        printf("\n");
    } while (choice3 == 1);

    printf("Работа программы завершена.\n");
    return 0;
}