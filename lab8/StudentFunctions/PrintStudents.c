
#include "../main.h"

void PrintStudents(Students Group) {
    size_t i;
    if (Group->count == 0) {
        printf("������ ����!\n");
        return;
    }

    printf("������ ���������:\n\n");

    for (i = 0; i < Group->count; ++i) {
        printf(
            "%llu. %s %s\n�������: %hhu\n������: ����������� - %hhu, ������� - "
            "%hhu, ���.������ - %hhu, ������ - %hhu\n\n",
            i + 1, Group->info[i].LastName, Group->info[i].FirstName,
            Group->info[i].Age, Group->info[i].Object.Informatika,
            Group->info[i].Object.Algebra, Group->info[i].Object.Matanaliz,
            Group->info[i].Object.Fizika);
    }
}

