
#include "Header.h"

int main() {
    setlocale(LC_ALL, "rus");

    while (1) {
        printf("Выберите опцию:\n");
        printf("1. Примеры функций\n");
        printf("2. Вывод файла в шестнадцатиричном виде\n");
        printf("0. Выйти из программы\n");

        switch (MenuSelection()) {
            case 1:
                FunctionsExample();
                break;

            case 2:
                HexFile();
                break;

            case 0:
                return 0;

            default:
                printf("Нет такой опции!\n");
                break;
        }
    }
}

