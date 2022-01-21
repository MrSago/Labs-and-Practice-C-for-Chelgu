
#include "main.h"

void StringBruteForce(void) {
    FILE* file;
    clock_t start, stop;
    char* string;
    unsigned int result;

    printf("Введите строку: ");
    string = ScanString();
    result = HashRot13(string);

    printf(
        "Результат выполнения функции: %d\nВесь отчет будет сохранен в файл: "
        "Result.txt\n\nНачало перебора:\n",
        result);

    start = clock();
    BruteForce(result, string, FILENAME_RESULT);
    stop = clock();

    free(string);

    printf("Перебор завершен!\nВремя выполнения: %.3f сек.\n",
           (stop - start) / (float)CLOCKS_PER_SEC);

    file = fopen("Result.txt", "a");
    fprintf(file, "Время выполнения: %.3f сек.\n",
              (stop - start) / (float)CLOCKS_PER_SEC);
    fclose(file);
}

