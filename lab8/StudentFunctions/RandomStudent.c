
#include "../main.h"

char* RndName(int rnd);

void RandomStudent(Students Group) {
    Info* NewStudent;
    size_t index;

    if (Group->info == (Info*)NULL || Group->count == 0) {
        Group->count = 1;

        NewStudent = (Info*)malloc(sizeof(Info));
        if (NewStudent == (Info*)NULL) {
            exit(EXIT_FAILURE);
        }
    } else {
        Group->count++;

        NewStudent = (Info*)realloc(Group->info, Group->count * sizeof(Info));
        if (NewStudent == (Info*)NULL) {
            exit(EXIT_FAILURE);
        }
    }

    index = Group->count - 1;

    NewStudent[index].LastName = RndName(3 + (uint8_t)rand() % 9);
    NewStudent[index].FirstName = RndName(3 + (uint8_t)rand() % 9);
    NewStudent[index].Age = (1 + (uint8_t)rand() % 100);
    NewStudent[index].Object.Informatika = MARKS;
    NewStudent[index].Object.Algebra = MARKS;
    NewStudent[index].Object.Matanaliz = MARKS;
    NewStudent[index].Object.Fizika = MARKS;

    printf("Добавленный рандомный студент:\n\n");
    printf(
        "%llu. %s %s\nВозраст: %hhu\nОценки: Информатика - %hhu, Алгебра - "
        "%hhu, Мат.Анализ - %hhu, Физика - %hhu\n\n",
        index + 1, NewStudent[index].LastName, NewStudent[index].FirstName,
        NewStudent[index].Age, NewStudent[index].Object.Informatika,
        NewStudent[index].Object.Algebra, NewStudent[index].Object.Matanaliz,
        NewStudent[index].Object.Fizika);

    Group->info = NewStudent;
}

char* RndName(int rnd) {
	int i;

    char* name = (char*)malloc(rnd * sizeof(char));
    if (name == (char*)NULL) {
        exit(EXIT_FAILURE);
    }

    name[0] = -64 + (rand() % 32);
    for (i = 1; i < rnd - 1; ++i) {
        name[i] = -32 + (rand() % 32);
    }
    name[rnd - 1] = 0;

    return name;
}

