
#include "main.h"

void FullBruteForce(char filename[]) {
    unsigned int res1, res2, res3, res4, res5;
    char str1[2], str2[3], str3[4], str4[5], str5[6];
    char i, j, k, n, m, s;

    str1[1] = 0;
    str2[2] = 0;
    str3[3] = 0;
    str4[4] = 0;
    str5[5] = 0;

    printf("Начат полный перебор\nВесь отчет будет сохранен в файл: %s\n\n",
           filename);

    for (i = -64; i <= 122; ++i) {
        if (i == 0)
            i = 48;
        else if (i == 58)
            i = 65;
        else if (i == 91)
            i = 97;
        str1[0] = i;
        res1 = HashRot13(str1);
        printf(
            "Строка: %s\nРезультат выполнения функции: %d\nНачало перебора:\n",
            str1, res1);
        BruteForce(res1, str1, filename);
        printf("Конец перебора!\n\n");
    }

    for (i = -64; i <= 122; ++i) {
        if (i == 0)
            i = 48;
        else if (i == 58)
            i = 65;
        else if (i == 91)
            i = 97;
        for (j = -64; j <= 122; ++j) {
            if (j == 0)
                j = 48;
            else if (j == 58)
                j = 65;
            else if (j == 91)
                j = 97;
            str2[0] = i;
            str2[1] = j;
            res2 = HashRot13(str2);
            printf(
                "Строка: %s\nРезультат выполнения функции: %d\nНачало "
                "перебора:\n",
                str2, res2);
            BruteForce(res2, str2, filename);
            printf("Конец перебора!\n\n");
        }
    }

    for (i = -64; i <= 122; ++i) {
        if (i == 0)
            i = 48;
        else if (i == 58)
            i = 65;
        else if (i == 91)
            i = 97;
        for (j = -64; j <= 122; ++j) {
            if (j == 0)
                j = 48;
            else if (j == 58)
                j = 65;
            else if (j == 91)
                j = 97;
            for (m = -64; m <= 122; ++m) {
                if (m == 0)
                    m = 48;
                else if (m == 58)
                    m = 65;
                else if (m == 91)
                    m = 97;
                str3[0] = i;
                str3[1] = j;
                str3[2] = m;
                res3 = HashRot13(str3);
                printf(
                    "Строка: %s\nРезультат выполнения функции: %d\nНачало "
                    "перебора:\n",
                    str3, res3);
                BruteForce(res3, str3, filename);
                printf("Конец перебора!\n\n");
            }
        }
    }

    for (i = -64; i <= 122; ++i) {
        if (i == 0)
            i = 48;
        else if (i == 58)
            i = 65;
        else if (i == 91)
            i = 97;
        for (j = -64; j <= 122; ++j) {
            if (j == 0)
                j = 48;
            else if (j == 58)
                j = 65;
            else if (j == 91)
                j = 97;
            for (m = -64; m <= 122; ++m) {
                if (m == 0)
                    m = 48;
                else if (m == 58)
                    m = 65;
                else if (m == 91)
                    m = 97;
                for (n = -64; n <= 122; ++n) {
                    if (n == 0)
                        n = 48;
                    else if (n == 58)
                        n = 65;
                    else if (n == 91)
                        n = 97;
                    str4[0] = i;
                    str4[1] = j;
                    str4[2] = m;
                    str4[3] = n;
                    res4 = HashRot13(str4);
                    printf(
                        "Строка: %s\nРезультат выполнения функции: %d\nНачало "
                        "перебора:\n",
                        str4, res4);
                    BruteForce(res4, str4, filename);
                    printf("Конец перебора!\n\n");
                }
            }
        }
    }

    for (i = -64; i <= 122; ++i) {
        if (i == 0)
            i = 48;
        else if (i == 58)
            i = 65;
        else if (i == 91)
            i = 97;
        for (j = -64; j <= 122; ++j) {
            if (j == 0)
                j = 48;
            else if (j == 58)
                j = 65;
            else if (j == 91)
                j = 97;
            for (m = -64; m <= 122; ++m) {
                if (m == 0)
                    m = 48;
                else if (m == 58)
                    m = 65;
                else if (m == 91)
                    m = 97;
                for (n = -64; n <= 122; ++n) {
                    if (n == 0)
                        n = 48;
                    else if (n == 58)
                        n = 65;
                    else if (n == 91)
                        n = 97;
                    for (s = -64; s <= 122; ++s) {
                        if (s == 0)
                            s = 48;
                        else if (s == 58)
                            s = 65;
                        else if (s == 91)
                            s = 97;
                        str5[0] = i;
                        str5[1] = j;
                        str5[2] = m;
                        str5[3] = n;
                        str5[4] = s;
                        res5 = HashRot13(str5);
                        printf(
                            "Строка: %s\nРезультат выполнения функции: "
                            "%d\nНачало перебора:\n",
                            str5, res5);
                        BruteForce(res5, str5, filename);
                        printf("Конец перебора!\n\n");
                    }
                }
            }
        }
    }
}

