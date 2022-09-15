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

    float mat3[2][2] = {0};

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            mat3[i][j] = float(float(mat2[i][j]) / float(mat1[i][j]));
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