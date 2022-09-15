#include <iostream>
using namespace std;

int main()
{

    int mat1[4][3] = {
        {5, 6, 1},
        {2, 10, 19},
        {59, 56, 100},
        {111, 120, 135}};

    int mat2[4][3] = {
        {2, 8, 3},
        {5, 10, 5},
        {3, 7, 2},
        {25, 10, 12}};

    int mat3[4][3] = {0};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat3[i][j] = (mat1[i][j]) % (mat2[i][j]);
            if (mat1[i][j] < mat2[i][j])
            {
                mat3[i][j] = mat1[i][j];
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << mat3[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}