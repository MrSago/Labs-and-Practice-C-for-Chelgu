
#include "main.h"

int main() {
    retcode_t code = SUCCESS;
    setlocale(LC_ALL, "Rus");

    while (1) {
        printf(
            "Программа для вычисления определителя матрицы\n\n"
            "Выбери опцию:\n"
            "1.Ввести матрицу вручную\n"
            "2.Ввести из файла\n"
            "3.Сгенерировать матрицу\n"
            "0.Выйти из программы\n");

        switch (getchar()) {
            case '1':
                code = ManuallyMatrix();
                break;

            case '2':
                code = FileMatrix();
                break;

            case '3':
                code = GenRndMatrix();
                break;

            case '0':
                return SUCCESS;

            default:
                printf("\nОшибка! Такой опции не существует!\n");
                break;
        }

        if (code != SUCCESS && code != EFOPEN && code != EINCORMATR) {
            return my_exception(code);
        }
    }

    return code;
}

