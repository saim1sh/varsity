#include <bits/stdc++.h>
using namespace std;

int determinant(int matrix[8][8], int n, int row, int col)
{
    int minor[8][8];
    int minorSize = n - 1;
    int p = 0, q = 0;

    for (int i = 0; i < n; i++)
    {
        if (i != row)
        {
            for (int j = 0; j < n; j++)
            {
                if (j != col)
                {
                    minor[p][q++] = matrix[i][j];
                }
            }
            p++;
            q = 0;
        }
    }

    if (minorSize == 1)
    {
        return minor[0][0];
    }
    else
    {
        int det = 0;
        int sign = 1;
        for (int j = 0; j < minorSize; j++)
        {
            det += sign * minor[0][j] * determinant(minor, minorSize, 0, j);
            sign = -sign;
        }
        return det;
    }
}

int cofactor(int matrix[8][8], int n, int row, int col)
{
    int det = determinant(matrix, n, row, col);
    if ((row + col) % 2 == 0)
        return det;
    else
        return -det;
}

int main()
{
    int n;
    int matrix[8][8];
    int row, col;

    cout << "Enter the size of the matrix: ";
    cin >> n;

    if (n < 1)
    {
        cout << "Invalid matrix size. Please enter a positive integer." << "\n";
        return 1;
    }

    cout << "Enter the elements of the matrix:" << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "\n";
    cout << "Here is the matrix that you have entered: " << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "Enter row and col position for calculating the cofactor: ";
    cin >> row >> col;

    row--;
    col--;

    if (row >= 0 && row < n && col >= 0 && col < n)
    {
        int minor = determinant(matrix, n, row, col);
        int cof = cofactor(matrix, n, row, col);

        cout << "Minor value for position (" << row + 1 << ", " << col + 1 << "): " << minor << "\n";
        cout << "Cofactor value for position (" << row + 1 << ", " << col + 1 << "): " << cof << "\n";
    }
    else
    {
        cout << "Invalid position!" << "\n";
    }

    return 0;
}