
#include "main.h"

int main() {
    setlocale(LC_ALL, "Rus");

    printf(
        "Приветствую тебя, Юзверь!\n\n"
        "Меню:\n"
        "1.Брутфорс строки\n"
        "2.Полный брутфорс\n"
        "0.Выход\n"
    );

    while (1) {
        switch (MenuSelection()) {
            case 1:
                StringBruteForce();
                break;

            case 2:
                FullBruteForce(FILENAME_REPORT);
                break;

            case 0:
                return 0;

            default:
                printf("Ошибка! Такой опции не существует!\n\n");
                break;
        }
    }
}

