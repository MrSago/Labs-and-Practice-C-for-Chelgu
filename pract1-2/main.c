
#include "Header.h"

int main(int argc, char **argv) {
    if (argc <= 1) {
        printf(PRNT_SYNTAX);
        return ERR_FEW_ARG;
    }

    errno_t err;
    char *fin, *fout, *rstr, *str;

    err = GetArgv(argc, argv, &fin, &fout, &rstr, &str);
    if (err != SUCCESS) return err;

    FileStrReplace(fin, fout, rstr, str);

    printf("successful!");
    return SUCCESS;
}

