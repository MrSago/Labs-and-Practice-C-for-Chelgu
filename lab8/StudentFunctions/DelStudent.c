
#include <stdbool.h>
#include <string.h>

#include "../main.h"

/*Menu Functions*/
void DelNumber(Students Group);
void DelLastName(Students Group);
void DelInfo(Students Group);

/*Other Functions*/
void CopyAndFreeInfo(Students Group, size_t del_index);
void MemIndexInfoFree(Students Group, size_t index);

void DelStudent(Students Group) {
    if (Group->count == 0) {
        printf("Список пуст!\n");
        return;
    }

    while (1) {
        printf(
            "Выберите способ удаления:\n\n1.По номеру в списке\n2.По "
            "фамилии\n3.Очистить весь список\n0.Вернуться назад\n"
		);

        switch (MenuSelection()) {
            case 1:
                DelNumber(Group);
                return;

            case 2:
                DelLastName(Group);
                return;

            case 3:
                DelInfo(Group);
                printf("Список студентов удален!\n");
                return;

            case 0:
                return;

            default:
                printf("Ошибка! Такой опции не существует!\n\n");
                break;
        }
    }
}

void DelNumber(Students Group) {
    int err;
    size_t del_number;
    char tmp;

    PrintStudents(Group);

    while (1) {
        printf("Введите номер студента для удаления (для выхода введите 0): ");
        err = scanf("%llu", &del_number);

        if (err != 0 && del_number >= 0 && del_number <= Group->count) {
            for (tmp = 0; tmp != 10; /*empty*/) {
                err = scanf("%c", &tmp);
            }

            if (del_number == 0) {
                return;
            } else {
                break;
            }
        } else {
            for (tmp = 0; tmp != 10; /*empty*/) {
                scanf("%c", &tmp);
            }
            printf("Неверный номер студента!\n\n");
            continue;
        }
    }

    CopyAndFreeInfo(Group, del_number - 1);

    printf("Студент успешно удален!\n\n");
}

void DelLastName(Students Group) {
    size_t del_index, i;
    bool check = false;
    char* search;

    PrintStudents(Group);

    printf("Введите фамилию студента для удаления: ");
    search = ScanString();

    for (i = 0; i < Group->count; ++i) {
        if (strcmp(Group->info[i].LastName, search) == 0) {
            check = true;
            del_index = i;
            break;
        }
    }

    free(search);

    if (check == false) {
        printf("Студент не найден!\n\n");
        return;
    }

    CopyAndFreeInfo(Group, del_index);

    printf("Студент успешно удален!\n\n");
}

void DelInfo(Students Group) {
	size_t i;
    for (i = 0; i < Group->count; ++i) {
        MemIndexInfoFree(Group, i);
    }

    free(Group->info);
    Group->info = (Info*)NULL;
    Group->count = 0;
}

void CopyAndFreeInfo(Students Group, size_t del_index) {
    Info* NewInfo;
	size_t i, k;

    Group->count--;
    NewInfo = (Info*)malloc(Group->count * sizeof(Info));
    if (NewInfo == (Info*)NULL) {
        exit(EXIT_FAILURE);
    }

    for (i = 0, k = 0; i < Group->count + 1; ++i) {
        if (i == del_index) {
            ++k;
            continue;
        }

        NewInfo[i - k].LastName = Group->info[i].LastName;
        NewInfo[i - k].FirstName = Group->info[i].FirstName;
        NewInfo[i - k].Age = Group->info[i].Age;
        NewInfo[i - k].Object.Informatika = Group->info[i].Object.Informatika;
        NewInfo[i - k].Object.Algebra = Group->info[i].Object.Algebra;
        NewInfo[i - k].Object.Matanaliz = Group->info[i].Object.Matanaliz;
        NewInfo[i - k].Object.Fizika = Group->info[i].Object.Fizika;
    }

    MemIndexInfoFree(Group, del_index);
    free(Group->info);

    Group->info = NewInfo;
}

void MemIndexInfoFree(Students Group, size_t index) {
    if (Group->info[index].LastName != (char*)NULL) {
        free(Group->info[index].LastName);
    }

    if (Group->info[index].FirstName != (char*)NULL) {
        free(Group->info[index].FirstName);
    }

    Group->info[index].Age = 0;

    Group->info[index].Object.Informatika = 0;
    Group->info[index].Object.Algebra = 0;
    Group->info[index].Object.Matanaliz = 0;
    Group->info[index].Object.Fizika = 0;
}

