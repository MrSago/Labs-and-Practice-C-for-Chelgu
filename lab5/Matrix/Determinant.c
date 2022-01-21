
#include "./../main.h"

void MinorMatrix(int** matrix, int** new_matrix, const size_t size,
                 const size_t m_c);
void FreeArray(int** arr, const size_t size);

long long DetMatrix(int** matrix, const size_t size) {
    long long det;
    int** new_matrix;
    size_t i;
    char k;

    if (size == 1) {
        return matrix[0][0];
    } else if (size == 2) {
        return ((long long)matrix[0][0] * (long long)matrix[1][1]) -
               ((long long)matrix[1][0] * (long long)matrix[0][1]);
    }

    det = 0;
    k = 1;

    new_matrix = (int**)malloc((size - 1) * sizeof(int*));
    if (new_matrix == (int**)NULL) {
        exit(EMALLOC);
    }

    for (i = 0; i < size - 1; ++i) {
        new_matrix[i] = (int*)malloc((size - 1) * sizeof(int));
        if (new_matrix[i] == (int*)NULL) {
            exit(EMALLOC);
        }
    }

    for (i = 0; i < size; ++i) {
        MinorMatrix(matrix, new_matrix, size, i);
        det += (long long)k * (long long)matrix[i][0] *
               DetMatrix(new_matrix, size - 1);
        k = -k;
    }

    FreeArray(new_matrix, size - 1);

    return det;
}

void MinorMatrix(int** matrix, int** new_matrix, const size_t size,
                 const size_t m_c) {
    size_t i, j;
    size_t m_i = 0, m_j = 0;

    for (i = 0; i < size - 1; ++i) {
        if (i == 0) {
            m_i = 1;
        }

        m_j = 0;

        for (j = 0; j < size - 1; ++j) {
            if (j == m_c) {
                m_j = 1;
            }

            new_matrix[i][j] = matrix[i + m_i][j + m_j];
        }
    }
}

void FreeArray(int** arr, const size_t size) {
    size_t i;

    if (arr != (int**)NULL) {
        for (i = 0; i < size; ++i) {
            if (arr[i] != (int*)NULL) {
                free(arr[i]);
            }
        }

        free(arr);
    }
}

