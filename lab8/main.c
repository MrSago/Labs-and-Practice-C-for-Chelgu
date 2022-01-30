
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
                printf("Ошибка! Такой опции не существует!\n\n");
                break;
        }
    }
}

