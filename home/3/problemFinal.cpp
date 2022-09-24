#include <iostream>
using namespace std;

int main()
{

    int mat1[4][3], mat2[4][3], mat3[4][3] = {0};

    cout << "Input For Matrix 1." << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter Digit in [" << i << "][" << j << "] >> ";
            cin >> mat1[i][j];
        }
    }

    cout << "Input For Matrix 2." << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter Digit in [" << i << "][" << j << "] >> ";
            cin >> mat2[i][j];
        }
    }

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