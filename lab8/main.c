
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

    printf("Приветствую тебя, Юзверь!\n\n");

    while (1) {
        printf(
            "Выбери опцию:\n\n"
            "1.Добавление студента\n"
            "2.Добавление рандомного студента\n"
            "3.Удаление студента\n"
            "4.Вывести список студентов\n"
            "5.Загрузка списка из файла\n"
            "6.Загрузка списка из бинарного файла\n"
            "7.Выгрузка списка в файл\n"
            "8.Выгрузка списка в бинарный файл\n"
            "9.Вывести успевающих студентов\n"
            "10.Удаление из списка неуспевающих студентов\n"
            "0.Выход из программы\n");

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
                printf("Ошибка! Такой опции не существует!\n\n");
                break;
        }
    }
}

