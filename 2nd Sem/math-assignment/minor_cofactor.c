#include <stdio.h>

int determinant(int matrix[10][10], int n, int row, int col);
int cofactor(int matrix[10][10], int n, int row, int col);

int main() {
    int n, i, j;
    int matrix[10][10];
    int row, col;

    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Enter row and col position for calculating the cofactor: ");
    scanf("%d %d", &row, &col);

    row--;
    col--;

    if (row >= 0 && row < n && col >= 0 && col < n) {
        int minor = determinant(matrix, n, row, col);
        int cof = cofactor(matrix, n, row, col);
        printf("The position of the minor element [%d %d] is: %d\n", row + 1, col + 1, minor);
        printf("The position of the cofactor element [%d %d] is: %d\n", row + 1, col + 1, cof);
    } else {
        printf("Invalid position!\n");
    }

    return 0;
}

int determinant(int matrix[10][10], int n, int row, int col) {
    int minor[10][10];
    int minorSize = n - 1;
    int i, j, p = 0, q = 0;

    for (i = 0; i < n; i++) {
        if (i != row) {
            for (j = 0; j < n; j++) {
                if (j != col) {
                    minor[p][q++] = matrix[i][j];
                }
            }
            p++;
            q = 0;
        }
    }

    if (minorSize == 1) {
        return minor[0][0];
    } else {
        int det = 0;
        int sign = 1;
        for (j = 0; j < minorSize; j++) {
            det += sign * minor[0][j] * determinant(minor, minorSize, 0, j);
            sign = -sign;
        }
        return det;
    }
}

int cofactor(int matrix[10][10], int n, int row, int col) {
    int det = determinant(matrix, n, row, col);
    if ((row + col) % 2 == 0)
        return det;
    else
        return -det;
}
