
#include "main.h"

int main() {
    setlocale(LC_ALL, "Rus");

    /* Size of Numbers */
    size_t
        size1 = 0,
        size2 = 0, size_res = 0, tmp_size;

    char /* Array of Numbers */
        *number1,
        *number2, *result, *tmp_number;

    number1 = NumberFromFile(FILENUM1, &size1);
    if (number1 == (char*)NULL) {
        printf("Error open file: %s\n", FILENUM1);
        return EFOPEN;
    }

    number2 = NumberFromFile(FILENUM2, &size2);
    if (number2 == (char*)NULL) {
        printf("Error open file: %s\n", FILENUM2);
        return EFOPEN;
    }

    if (size2 > size1) {
        tmp_number = number1;
        tmp_size = size1;
        number1 = number2;
        size1 = size2;
        number2 = tmp_number;
        size2 = tmp_size;
    }

    printf("First Number:\n");
    PrintNumber(number1, size1);
    printf("\n");

    printf("Second Number:\n");
    PrintNumber(number2, size2);
    printf("\n");

    result = Addition(number2, number1, size2, size1, &size_res);
    printf("Addiction Result:\n");
    PrintNumber(result, size_res);
    printf("\n");

    free(result);

    result = Multiplication(number2, number1, size2, size1, &size_res);
    printf("Multiplication result:\n");
    PrintNumber(result, size_res);
    printf("\n");

    free(result);
    free(number1);
    free(number2);

    return 0;
}

