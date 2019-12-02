#ifndef HEADER_H
#define HEADER_H

#include "stdio.h"
#include "stdlib.h"
#include "locale.h"

#define FILENUM1 "1.txt"
#define FILENUM2 "2.txt"

#define EFOPEN -1
#define SUCCESS 0

char *NumberFromFile(char filename[], size_t *size);
void PrintNumber(char *number, size_t size);
char *CopyNumbers(char *number, size_t size);
char *Addition(char *number_min, char *number_max, size_t size_min, size_t size_max, size_t *size_res);
char *Multiplication(char *number_min, char *number_max, size_t size_min, size_t size_max, size_t *size_res);
errno_t FileCheck(FILE **file, const char filename[], const char mode[]);
#endif //HEADER_H