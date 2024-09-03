#include <iostream>

using namespace std;

int cofactor(int x, int y)
{
    int sign = (x + y) % 2 == 0 ? 1 : -1;
    return sign;
}

void print(int det, int x, int y)
{
    cout << "Minor: " << det << endl;
    cout << "Co-factor: " << cofactor(x, y) * det << endl;
}

int main()
{
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    int matrix[n][n];

    cout << "Enter the elements of the matrix: " << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "Enter the position to find the Minor & Co-factor : ";
    int x, y;
    cin >> x >> y;

    int minor[n - 1][n - 1];
    int p = 0, q = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == x - 1)
        {
            continue;
        }
        q = 0;
        for (int j = 0; j < n; j++)
        {
            if (j == y - 1)
            {
                continue;
            }

            minor[p][q] = matrix[i][j];
            q++;
        }
        p++;
    }

    int det;
    if (n == 2)
    {
        det = minor[0][0];
    }
    else if (n == 3)
    {
        det = (minor[0][0] * minor[1][1]) - (minor[0][1] * minor[1][0]);
    }
    else if (n == 4)
    {
        det = (minor[0][0] * (minor[1][1] * minor[2][2]) - (minor[1][2] * minor[2][1])) - (minor[0][1] * (minor[1][0] * minor[2][2]) - (minor[1][2] * minor[2][0])) + (minor[0][2] * (minor[1][0] * minor[2][1]) - (minor[1][1] * minor[2][0]));
    }

    print(det, x, y);
}