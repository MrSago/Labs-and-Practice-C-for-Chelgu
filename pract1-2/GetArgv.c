
#include "Header.h"

int GetArgv(int argc, char** argv,
                char** fin, char** fout,
                char** rstr, char** str) {
    int i;

    for (i = 1; i < argc; ++i) {
        if (!strcmp(argv[i], "-fin")) {
            if (argv[i + 1] == (char*)NULL) {
                printf("unknown arguments!");
                return ERR_UNKNOWN_ARG;
            }
            *fin = (char*)argv[i + 1];
            ++i;
            continue;
        }

        if (!strcmp(argv[i], "-fout")) {
            if (argv[i + 1] == (char*)NULL) {
                printf("unknown arguments!");
                return ERR_UNKNOWN_ARG;
            }
            *fout = (char*)argv[i + 1];
            ++i;
            continue;
        }

        if (!strcmp(argv[i], "-rstr")) {
            if (argv[i + 1] == (char*)NULL) {
                printf("unknown arguments!");
                return ERR_UNKNOWN_ARG;
            }
            *rstr = (char*)argv[i + 1];
            ++i;
            continue;
        }

        if (!strcmp(argv[i], "-str")) {
            if (argv[i + 1] == (char*)NULL) {
                printf("unknown arguments!");
                return ERR_UNKNOWN_ARG;
            }
            *str = (char*)argv[i + 1];
            ++i;
            continue;
        }
    }

    if (*fin == (char*)NULL || *fout == (char*)NULL || *rstr == (char*)NULL || *str == (char*)NULL) {
        printf("few arguments!");
        return ERR_FEW_ARG;
    }

    return 0;
}

