
#ifndef _MAIN_H
#define _MAIN_H

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILENAME_RESULT "Result.txt"
#define FILENAME_REPORT "Report.txt"
#define FILENAME_STRINGS "Strings.txt"

void BruteForce(unsigned int result, char* string, char filename[]);
void FullBruteForce(char filename[]);
unsigned int HashRot13(char* str);
char* ScanString();
int MenuSelection();
void StringBruteForce();

#endif

