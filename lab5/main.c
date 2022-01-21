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

        switch (_getch()) {
            case '1':
                system("cls");
                code = ManuallyMatrix();
                break;

            case '2':
                system("cls");
                code = FileMatrix();
                break;

            case '3':
                system("cls");
                code = GenRndMatrix();
                break;

            case '0':
                system("cls");
                return (SUCCESS);

            default:
                printf("\n������! ����� ����� �� ����������!\n");
                break;
        }

        if (code != SUCCESS && code != EFOPEN && code != EINCORMATR) {
            return my_exception(code);
        } else {
            system("pause");
            system("cls");
        }
    }

    return code;
}

