
#include "main.h"

extern void DelInfo(Students Group);

int main() {
    srand((unsigned)time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Students MK101 = (Students)malloc(sizeof(Student));
    if (MK101 == NULL) {
        exit(EXIT_FAILURE);
    } else {
        MK101->info = NULL;
        MK101->count = 0;
    }

    printf("����������� ����, ������!\n\n");

    while (1) {
        printf(
            "������ �����:\n\n"
            "1.���������� ��������\n"
            "2.���������� ���������� ��������\n"
            "3.�������� ��������\n"
            "4.������� ������ ���������\n"
            "5.�������� ������ �� �����\n"
            "6.�������� ������ �� ��������� �����\n"
            "7.�������� ������ � ����\n"
            "8.�������� ������ � �������� ����\n"
            "9.������� ���������� ���������\n"
            "10.�������� �� ������ ������������ ���������\n"
            "0.����� �� ���������\n");

        switch (MenuSelection()) {
            case 1:
                system("cls");
                AddStudent(MK101);
                system("pause");
                system("cls");
                break;

            case 2:
                system("cls");
                RandomStudent(MK101);
                system("pause");
                system("cls");
                break;

            case 3:
                system("cls");
                DelStudent(MK101);
                system("pause");
                system("cls");
                break;

            case 4:
                system("cls");
                PrintStudents(MK101);
                system("pause");
                system("cls");
                break;

            case 5:
                system("cls");
                ReadFromFileStudents(MK101);
                system("pause");
                system("cls");
                break;

            case 6:
                system("cls");
                ReadFromBinFileStudents(MK101);
                system("pause");
                system("cls");
                break;

            case 7:
                system("cls");
                WriteInFileStudents(MK101);
                system("pause");
                system("cls");
                break;

            case 8:
                system("cls");
                WriteInBinFileStudents(MK101);
                system("pause");
                system("cls");
                break;

            case 9:
                system("cls");
                NiceStudents(MK101);
                system("pause");
                system("cls");
                break;

            case 10:
                system("cls");
                DelNotNiceStudents(MK101);
                system("pause");
                system("cls");
                break;

            case 0:
                DelInfo(MK101);
                free(MK101);
                return SUCCESS;

            default:
                printf("������! ����� ����� �� ����������!\n\n");
                break;
        }
    }
}

