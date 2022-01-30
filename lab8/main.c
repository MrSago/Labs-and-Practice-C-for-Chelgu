
#include "main.h"

extern void DelInfo(Students Group);

int main() {
    srand((unsigned)time(NULL));
    #ifdef WIN32
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
    #endif

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
                AddStudent(MK101);
                break;

            case 2:
                RandomStudent(MK101);
                break;

            case 3:
                DelStudent(MK101);
                break;

            case 4:
                PrintStudents(MK101);
                break;

            case 5:
                ReadFromFileStudents(MK101);
                break;

            case 6:
                ReadFromBinFileStudents(MK101);
                break;

            case 7:
                WriteInFileStudents(MK101);
                break;

            case 8:
                WriteInBinFileStudents(MK101);
                break;

            case 9:
                NiceStudents(MK101);
                break;

            case 10:
                DelNotNiceStudents(MK101);
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

