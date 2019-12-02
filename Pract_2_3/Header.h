#ifndef HEADER_H
#define HEADER_H

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "time.h"
#include "string.h"

#define SYNTAX "syntax:\t-m \"min password length\"\n\t-M \"max password length\"\n\t-n \"password length\"\n\t-a \"alphabet\"\n\t-C[aADS]"
#define ARG_a "abcdefghijklmnopqrstuvwxyz"
#define ARG_A "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define ARG_D "0123456789"
#define ARG_S "!\"#$%%&'()*+,-./@^"

void ParseArgv(int argc, char **argv, size_t *outPasswordLength, char **outAlph);
void GenerateRandomString(char *out, size_t size, char *alph, size_t sizeAlph);
char *GenerateRandomPassword(size_t passwordLength, char *alph);

#endif //HEADER_H