
#include "main.h"

int main() {
    setlocale(LC_ALL, "Rus");

    printf(
        "����������� ����, ������!\n\n"
        "����:\n"
        "1.�������� ������\n"
        "2.������ ��������\n"
        "0.�����\n"
    );

    while (1) {
        switch (MenuSelection()) {
            case 1:
                StringBruteForce();
                break;

            case 2:
                FullBruteForce(FILENAME_REPORT);
                break;

            case 0:
                return 0;

            default:
                printf("������! ����� ����� �� ����������!\n\n");
                break;
        }
    }
}

