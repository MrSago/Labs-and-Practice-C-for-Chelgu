
#include "../main.h"

void WriteInFileStudents(Students Group) {
    int err;
    FILE* file;
    char* filename;
    size_t i;

    if (Group->info == (Info*)NULL || Group->count == 0) {
        printf("������ ����!\n");
        return;
    }

    printf("������� ��� ����� ��� ����������: ");
    filename = ScanString();

    err = FileCheck(&file, filename, "w");
    if (err == EFOPEN) {
        printf("�� ���� ������� ����: %s\n", filename);
        free(filename);
        return;
    } else {
        printf("���� %s ������� ������!\n", filename);
        free(filename);
    }

    fprintf(file, "���������� �������: %llu\n\n", Group->count);

    for (i = 0; i < Group->count; ++i) {
        fprintf(
            file,
            "%llu. %s %s\n�������: %hhu\n������: ����������� - %hhu, ������� - "
            "%hhu, ���.������ - %hhu, ������ - %hhu\n\n",
            i + 1, Group->info[i].LastName, Group->info[i].FirstName,
            Group->info[i].Age, Group->info[i].Object.Informatika,
            Group->info[i].Object.Algebra, Group->info[i].Object.Matanaliz,
            Group->info[i].Object.Fizika);
    }

    fclose(file);

    printf("������ ��������� ������� ��������!\n\n");
}

