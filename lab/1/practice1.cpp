#include<iostream>
using namespace std;

int main(){

    int _2d[5][5]={{11, 12, 13, 14, 15},
                    {21, 22, 23, 24, 25},
                    {31, 32, 33, 34, 35},
                    {41, 42, 43, 44, 45},
                    {51, 52, 53, 54, 55}};
    
    int _2d1[5][5]={{11, 12, 13, 14, 15},
                    {21, 22, 23, 24, 25},
                    {31, 32, 33, 34, 35},
                    {41, 42, 43, 44, 45},
                    {51, 52, 53, 54, 55}};

    int _2d2[5][5];

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            _2d2[i][j] = _2d[i][j] + _2d1[i][j];
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout<<_2d2[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}