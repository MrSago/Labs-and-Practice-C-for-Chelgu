
#include <stdint.h>

#include "Header.h"

void FunctionsExample() {
    int a;
    int p;
    char* num = (char*)NULL;

    printf("������ ������� my_atoi\n");

    printf("������� �����(char*): ");
    num = ScanString();

    printf("������� ������� ����������: ");
    p = ScanINT();

    printf("������ ������������� ������� my_atoi: (char*)%s -> (int)%d\n\n\n",
           num, my_atoi(num, p));
    if (num != (char*)NULL) {
        free(num);
        num = (char*)NULL;
    }

    printf("������ ������� my_itoa\n");

    printf("������� �����(int): ");
    a = ScanINT();

    printf("������� ������� ����������: ");
    p = ScanINT();

    printf("������ ������������� ������� my_itoa: ");
    my_itoa(&num, a, p);
    printf("\n");
    if (num != (char*)NULL) {
        free(num);
        num = (char*)NULL;
    }
}

