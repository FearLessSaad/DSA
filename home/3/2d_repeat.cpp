#include <iostream>
using namespace std;

int _2d[5][5] = {
                    {11, 12, 13, 10, 15},
                    {21, 11, 23, 24, 25},
                    {55, 12, 33, 34, 35},
                    {41, 42, 43, 55, 45},
                    {51, 10, 11, 54, 55}
                };


bool cmp(int e){
    int count = 0; 
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(e == _2d[i][j]){
                count++;
            }
            if(count>1){
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int size = 0;
    int repeats[15] = {0};

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
          if(cmp(_2d[i][j])){
            bool chk = true;
            for(int r = 0; r < size + 1; r++){
                if(repeats[r] == _2d[i][j]){
                    chk = false;
                    break;
                }
            }
            if(chk){
                repeats[size++] = _2d[i][j];
            }
          }
        }
    }

    for(int i = 0; i < size; i++){
        cout<<repeats[i] << " Repeats."<<endl;
    }

    return 0;
}
