
#include "Header.h"

int main() {
    setlocale(LC_ALL, "rus");

    while (1) {
        printf("�������� �����:\n");
        printf("1. ������� �������\n");
        printf("2. ����� ����� � ����������������� ����\n");
        printf("0. ����� �� ���������\n");

        switch (MenuSelection()) {
            case 1:
                system("cls");
                FunctionsExample();
                system("pause");
                system("cls");
                break;

            case 2:
                system("cls");
                HexFile();
                system("pause");
                system("cls");
                break;

            case 0:
                return 0;

            default:
                printf("��� ����� �����!\n");
                break;
        }
    }
}

