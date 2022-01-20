
#include "../main.h"

void NiceStudents(Students Group) {
    size_t i;

    if (Group->count == 0) {
        printf("Список пуст!\n");
        return;
    }

    printf("Список успевающих студентов (средняя оценка выше 3):\n\n");

    for (i = 0; i < Group->count; ++i) {
        if ((double)NICE_MARKS < 4.0) {
            continue;
        }

        printf(
            "%llu. %s %s\nВозраст: %hhu\nОценки: Информатика - %hhu, Алгебра - "
            "%hhu, Мат.Анализ - %hhu, Физика - %hhu\n\n",
            i + 1, Group->info[i].LastName, Group->info[i].FirstName,
            Group->info[i].Age, Group->info[i].Object.Informatika,
            Group->info[i].Object.Algebra, Group->info[i].Object.Matanaliz,
            Group->info[i].Object.Fizika);
    }
}

