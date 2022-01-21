
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

    printf("Введите фамилию студента: ");
    NewStudent[index].LastName = ScanString();

    printf("Введите имя студента: ");
    NewStudent[index].FirstName = ScanString();

    printf("Введите возраст студента: ");
    scanf("%hhu", &NewStudent[index].Age);

    printf("Введите оценки студента\nИнформатика: ");
    scanf("%hhu", &NewStudent[index].Object.Informatika);

    printf("Алгебра: ");
    scanf("%hhu", &NewStudent[index].Object.Algebra);

    printf("Мат.Анализ: ");
    scanf("%hhu", &NewStudent[index].Object.Matanaliz);

    printf("Физика: ");
    scanf("%hhu", &NewStudent[index].Object.Fizika);

    Group->info = NewStudent;
    printf("Студент успешно добавлен!\n");
}

