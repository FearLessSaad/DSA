#include<iostream>
using namespace std;


int main(){

    int mat1[2][2] = {
                        {1, 2},
                        {3, 4}

                    };

    int mat2[2][2] = {
                        {5, 6},
                        {7, 8}
                    };

    int mat3[2][2] = {0};


    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                mat3[i][j] += (mat1[i][j] * mat2[k][j]); 
            }
        }
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout<<mat3[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}