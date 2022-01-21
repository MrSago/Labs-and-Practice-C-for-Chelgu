
#include "../main.h"

void PrintStudents(Students Group) {
    size_t i;
    if (Group->count == 0) {
        printf("Список пуст!\n");
        return;
    }

    printf("Список студентов:\n\n");

    for (i = 0; i < Group->count; ++i) {
        printf(
            "%llu. %s %s\nВозраст: %hhu\nОценки: Информатика - %hhu, Алгебра - "
            "%hhu, Мат.Анализ - %hhu, Физика - %hhu\n\n",
            i + 1, Group->info[i].LastName, Group->info[i].FirstName,
            Group->info[i].Age, Group->info[i].Object.Informatika,
            Group->info[i].Object.Algebra, Group->info[i].Object.Matanaliz,
            Group->info[i].Object.Fizika);
    }
}

