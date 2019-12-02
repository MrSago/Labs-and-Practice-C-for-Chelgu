#ifndef HEADER_H
#define HEADER_H

#include "stdio.h"
#include "stdlib.h"
#include "locale.h"
#include "time.h"

#define WELCOME "Приветствую тебя, Юзверь!\n\n"

#define FILENAME_RESULT "Result.txt"
#define FILENAME_REPORT "Report.txt"
#define FILENAME_STRINGS "Strings.txt"

void BruteForce(unsigned int result, char *string, char filename[]);
void FullBruteForce(char filename[]);
unsigned int HashRot13(char* str);
char *ScanString(void);
int MenuSelection(void);
void StringBruteForce(void);
#endif //HEADER_H