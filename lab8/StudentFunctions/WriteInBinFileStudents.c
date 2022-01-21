
#include "../main.h"

void WriteInBinFileStudents(Students Group) {
    errno_t err;
    FILE* file;
    size_t i, strsize;
    char* filename;

    if (Group->count == 0) {
        printf("������ ����!\n");
        return;
    }

    printf("������� ��� ��� ���������� � �������� �����: ");
    filename = ScanString();

    err = FileCheck(&file, filename, "wb");
    if (err == EFOPEN) {
        printf("�� ���� ������� ����: %s\n", filename);
        free(filename);
        return;
    } else {
        printf("���� %s ������� ������!\n", filename);
        free(filename);
    }

    /*Count*/
    fwrite(&Group->count, sizeof(size_t), 1, file);

    for (i = 0; i < Group->count; ++i) {
        /*LastName*/
        strsize = strlen(Group->info[i].LastName);
        fwrite(&strsize, sizeof(size_t), 1, file);
        fwrite(Group->info[i].LastName, sizeof(char), strsize, file);

        /*FirstName*/
        strsize = strlen(Group->info[i].FirstName);
        fwrite(&strsize, sizeof(size_t), 1, file);
        fwrite(Group->info[i].FirstName, sizeof(char), strsize, file);

        /*Age*/
        fwrite(&Group->info[i].Age, sizeof(uint8_t), 1, file);

        /*Objects*/
        fwrite(&Group->info[i].Object.Informatika, sizeof(uint8_t), 1, file);
        fwrite(&Group->info[i].Object.Algebra, sizeof(uint8_t), 1, file);
        fwrite(&Group->info[i].Object.Matanaliz, sizeof(uint8_t), 1, file);
        fwrite(&Group->info[i].Object.Fizika, sizeof(uint8_t), 1, file);
    }

    fclose(file);

    printf("������ ��������� ������� ��������!\n\n");
}

