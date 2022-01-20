
#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRNT_SYNTAX                                             \
    "syntax:\t-fin \"input file name\"\n\t-fout \"output file " \
    "name\"\n\t-rstr \"replaceable string\"\n\t-str \"on string\""

#define SUCCESS 0
#define EFOPEN 1
#define ERR_FEW_ARG -1
#define ERR_UNKNOWN_ARG -2

errno_t GetArgv(int argc, char **argv,
                char **fin, char **fout,
                char **rstr, char **str);
errno_t FileCheck(FILE **file, const char filename[], const char mode[]);
void FileStrReplace(char *fin, char *fout, char *rstr, char *str);

#endif

