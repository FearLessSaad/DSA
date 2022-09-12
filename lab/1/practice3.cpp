#include<iostream>
using namespace std;

int main(){

    int _2d[5][5]={{11, 12, 13, 14, 15},
                    {21, 22, 23, 24, 25},
                    {31, 32, 33, 34, 35},
                    {41, 42, 43, 44, 45},
                    {51, 52, 53, 54, 55}};

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(i == j){
                cout<<_2d[i][j]<<" ";
            }else{
                cout<<"0 ";
            }
        }
        cout<<"\n";
    }

    return 0;
}