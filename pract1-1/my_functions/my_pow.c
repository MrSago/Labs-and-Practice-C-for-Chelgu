
int my_pow(int a, const unsigned n) {
    unsigned i;

    switch (n) {
        case 0:
            return 1;

        case 1:
            return a;

        default: {
            const int tmp = a;

            for (i = 0; i < n - 1; ++i) {
                a *= tmp;
            }

            return a;
        }
    }
}

