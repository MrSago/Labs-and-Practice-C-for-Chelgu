
#include <stdint.h>

#include "Header.h"

void FunctionsExample() {
    int a;
    int p;
    char* num = (char*)NULL;

    printf("Пример функции my_atoi\n");

    printf("Введите число(char*): ");
    num = ScanString();

    printf("Введите систему счистления: ");
    p = ScanINT();

    printf("Пример использования функции my_atoi: (char*)%s -> (int)%d\n\n\n",
           num, my_atoi(num, p));
    if (num != (char*)NULL) {
        free(num);
        num = (char*)NULL;
    }

    printf("Пример функции my_itoa\n");

    printf("Введите число(int): ");
    a = ScanINT();

    printf("Введите систему счистления: ");
    p = ScanINT();

    printf("Пример использования функции my_itoa: ");
    my_itoa(&num, a, p);
    printf("\n");
    if (num != (char*)NULL) {
        free(num);
        num = (char*)NULL;
    }
}

