
#include "./main.h"

int main() {
    setlocale(LC_ALL, "Rus");

    char* str =
        "����� ���� �� ����� � ������ �������, � ������� ��� �� �������, "
        "������� ��� �������";
    char* find = "��";

    printf("str = %s\n", str);
    printf("find = %s\n", find);
    printf("%llu\n", strfind(str, find));

    return 0;
}

