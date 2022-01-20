
#include "./main.h"

int main() {
    setlocale(LC_ALL, "Rus");

    char* str =
        "Вышел Петя на пенек и скушал пирожок, а пирожок был не простым, "
        "пирожок был золотым";
    char* find = "ро";

    printf("str = %s\n", str);
    printf("find = %s\n", find);
    printf("%llu\n", strfind(str, find));

    return 0;
}

