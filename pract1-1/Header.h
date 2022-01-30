
#ifndef HEADER_H
#define HEADER_H

#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

char* ScanString();
int ScanINT();

int MenuSelection();
void FunctionsExample();
void HexFile();

int my_atoi(char* str, int p);
void my_itoa(char** buf, int a, int p);

#endif

