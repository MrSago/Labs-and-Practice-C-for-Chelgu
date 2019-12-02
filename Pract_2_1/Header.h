#ifndef HEADER_H
#define HEADER_H

#include "stdio.h"
#include "stdlib.h"
#include "locale.h"

char *ScanString(void);
int ScanINT(void);

//MenuFunctions
int MenuSelection(void);
void FunctionsExample(void);
void HexFile(void);

//MyFunctions
int my_atoi(char *str, int p);
void my_itoa(char **buf, int a, int p);

#endif //HEADER_H