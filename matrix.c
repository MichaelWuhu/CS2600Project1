#include <stdio.h>
#include <stdlib.h>

struct matrix {
    float **matrix; // pointer to a pointer for storing the 2D array
    int rows, cols; // rows and columns
};

void printMatrix(struct matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%d ", (int)m.matrix[i][j]);
        }
        printf("\n");
    }
}

struct matrix multiply(struct matrix m1, struct matrix m2) {
    struct matrix result;
    if (m1.cols != m2.rows) {
        printf("Matrices cannot be multiplied due to incompatible dimensions.\n");
        result.matrix = NULL;
        return result;
    }

    result.rows = m1.rows;
    result.cols = m2.cols;
    result.matrix = (float **)malloc(result.rows * sizeof(float *));
    for (int i = 0; i < result.rows; i++) {
        result.matrix[i] = (float *)malloc(result.cols * sizeof(float));
    }

    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            result.matrix[i][j] = 0;
            for (int k = 0; k < m1.cols; k++) {
                result.matrix[i][j] += m1.matrix[i][k] * m2.matrix[k][j];
            }
        }
    }

    return result;
}

int main() {
    struct matrix m1, m2, result;

    // User Input for Matrix 1
    printf("Enter the size of the first matrix in format \"rowsxcols\": ");
    scanf("%dx%d", &m1.rows, &m1.cols);

    // Allocate memory for the matrix
    m1.matrix = (float **)malloc(m1.rows * sizeof(float *));
    for (int i = 0; i < m1.rows; i++) {
        m1.matrix[i] = (float *)malloc(m1.cols * sizeof(float));
    }

    // Fill the matrix with inputted values
    printf("Enter the values for the first matrix row-wise:\n");
    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            scanf("%f", &m1.matrix[i][j]);
        }
    }

    // User Input for Matrix 2
    printf("Enter the size of the second matrix in format \"rowsxcols\": ");
    scanf("%dx%d", &m2.rows, &m2.cols);

    // Allocate memory for the matrix
    m2.matrix = (float **)malloc(m2.rows * sizeof(float *));
    for (int i = 0; i < m2.rows; i++) {
        m2.matrix[i] = (float *)malloc(m2.cols * sizeof(float));
    }

    // Fill the matrix with inputted values
    printf("Enter the values for the second matrix row-wise:\n");
    for (int i = 0; i < m2.rows; i++) {
        for (int j = 0; j < m2.cols; j++) {
            scanf("%f", &m2.matrix[i][j]);
        }
    }

    printf("Matrix 1:\n");
    printMatrix(m1);
    printf("Matrix 2:\n");
    printMatrix(m2);

    result = multiply(m1, m2);
    if (result.matrix != NULL) {
        printf("Resulting Matrix:\n");
        printMatrix(result);
    }

    // Free allocated memory
    for (int i = 0; i < m1.rows; i++) {
        free(m1.matrix[i]);
    }
    free(m1.matrix);

    for (int i = 0; i < m2.rows; i++) {
        free(m2.matrix[i]);
    }
    free(m2.matrix);

    if (result.matrix != NULL) {
        for (int i = 0; i < result.rows; i++) {
            free(result.matrix[i]);
        }
        free(result.matrix);
    }

    return 0;
}