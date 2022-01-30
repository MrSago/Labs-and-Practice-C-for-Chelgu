
#include "../main.h"

extern void DelInfo(Students Group);

void ReadFromFileStudents(Students Group) {
    Info* NewInfo;
    int err;
    FILE* file;
    char* filename;
    size_t i, j, count = 0;

    printf("Введите имя файла для загрузки: ");
    filename = ScanString();

    err = FileCheck(&file, filename, "r");
    if (err == EFOPEN) {
        printf("Не могу открыть файл: %s\n", filename);
        free(filename);
        return;
    } else {
        printf("Файл %s успешно открыт!\n", filename);
        free(filename);
    }

    if (Group->info != (Info*)NULL && Group->count > 0) {
        DelInfo(Group);
    }

    err = fseek(file, 20, SEEK_CUR);
    if (err != 0) {
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%llu", &Group->count);

    err = fseek(file, 2, SEEK_CUR);
    if (err != 0) {
        exit(EXIT_FAILURE);
    }

    NewInfo = (Info*)malloc(Group->count * sizeof(Info));
    if (NewInfo == (Info*)NULL) {
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < Group->count; ++i) {
        char tmp = 0;
        char* tmp_string;

        /*Переход к LastName и FirstName*/
        while (tmp != 32) {
            fscanf(file, "%c", &tmp);
        }

        /*Запись в LastName*/
        NewInfo[i].LastName = (char*)(malloc(sizeof(char)));
        if (NewInfo[i].LastName == (char*)NULL) {
            exit(EXIT_FAILURE);
        }

        for (j = 0; /*empty*/; ++j) {
            fscanf(file, "%c", &tmp);

            if (tmp == 32) {
                NewInfo[i].LastName[j] = 0;
                break;
            }

            NewInfo[i].LastName[j] = tmp;

            tmp_string = realloc(NewInfo[i].LastName, (j + 2) * sizeof(char));
            if (tmp_string == (char*)NULL) {
                exit(EXIT_FAILURE);
            }

            NewInfo[i].LastName = tmp_string;
        }

        /*Запись в FirstName*/
        NewInfo[i].FirstName = (char *)(malloc(sizeof(char)));
        if (NewInfo[i].FirstName == (char*)NULL) {
            exit(EXIT_FAILURE);
        }

        for (j = 0; /*empty*/; ++j) {
            fscanf(file, "%c", &tmp);

            if (tmp == 10) {
                NewInfo[i].FirstName[j] = 0;
                break;
            }

            NewInfo[i].FirstName[j] = tmp;

            tmp_string = realloc(NewInfo[i].FirstName, (j + 2) * sizeof(char));
            if (tmp_string == (char*)NULL) {
                exit(EXIT_FAILURE);
            }

            NewInfo[i].FirstName = tmp_string;
        }

        /*Переход и запись Age*/
        err = fseek(file, 9, SEEK_CUR);
        if (err != 0) {
            exit(EXIT_FAILURE);
        }
        fscanf(file, "%hhu", &NewInfo[i].Age);

        /*Переход и запись Object.Informatika*/
        err = fseek(file, 23, SEEK_CUR);
        if (err != 0) {
            exit(EXIT_FAILURE);
        }
        fscanf(file, "%hhu", &NewInfo[i].Object.Informatika);

        /*Переход и запись Object.Algebra*/
        err = fseek(file, 12, SEEK_CUR);
        if (err != 0) {
            exit(EXIT_FAILURE);
        }
        fscanf(file, "%hhu", &NewInfo[i].Object.Algebra);

        /*Переход и запись Object.Matanaliz*/
        err = fseek(file, 15, SEEK_CUR);
        if (err != 0) {
            exit(EXIT_FAILURE);
        }
        fscanf(file, "%hhu", &NewInfo[i].Object.Matanaliz);

        /*Переход и запись Object.Fizika*/
        err = fseek(file, 11, SEEK_CUR);
        if (err != 0) {
            exit(EXIT_FAILURE);
        }
        fscanf(file, "%hhu", &NewInfo[i].Object.Fizika);

        /*Переход к следующему студенту*/
        err = fseek(file, 4, SEEK_CUR);
        if (err != 0) {
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);

    Group->info = NewInfo;
    PrintStudents(Group);
}

