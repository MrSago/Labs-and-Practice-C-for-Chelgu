
#include "main.h"

int main() {
    retcode_t code = SUCCESS;
    setlocale(LC_ALL, "Rus");

    while (1) {
        printf(
            "��������� ��� ���������� ������������ �������\n\n"
            "������ �����:\n"
            "1.������ ������� �������\n"
            "2.������ �� �����\n"
            "3.������������� �������\n"
            "0.����� �� ���������\n");

        switch (getchar()) {
            case '1':
                code = ManuallyMatrix();
                break;

            case '2':
                code = FileMatrix();
                break;

            case '3':
                code = GenRndMatrix();
                break;

            case '0':
                return SUCCESS;

            default:
                printf("\n������! ����� ����� �� ����������!\n");
                break;
        }

        if (code != SUCCESS && code != EFOPEN && code != EINCORMATR) {
            return my_exception(code);
        }
    }

    return code;
}

