
#include "../main.h"

void AddStudent(Students Group) {
    Info* NewStudent;
    size_t index;

    if (Group->info == NULL || Group->count == 0) {
        Group->count = 1;

        NewStudent = (Info*)malloc(sizeof(Info));
        if (NewStudent == NULL) {
            exit(EXIT_FAILURE);
        }
    } else {
        Group->count++;

        NewStudent = (Info*)realloc(Group->info, Group->count * sizeof(Info));
        if (NewStudent == NULL) {
            exit(EXIT_FAILURE);
        }
    }

    index = Group->count - 1;

    printf("������� ������� ��������: ");
    NewStudent[index].LastName = ScanString();

    printf("������� ��� ��������: ");
    NewStudent[index].FirstName = ScanString();

    printf("������� ������� ��������: ");
    scanf("%hhu", &NewStudent[index].Age);

    printf("������� ������ ��������\n�����������: ");
    scanf("%hhu", &NewStudent[index].Object.Informatika);

    printf("�������: ");
    scanf("%hhu", &NewStudent[index].Object.Algebra);

    printf("���.������: ");
    scanf("%hhu", &NewStudent[index].Object.Matanaliz);

    printf("������: ");
    scanf("%hhu", &NewStudent[index].Object.Fizika);

    Group->info = NewStudent;
    printf("������� ������� ��������!\n");
}

