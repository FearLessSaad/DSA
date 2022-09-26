#include<iostream>
using namespace std;


int main(){

    int arr[10] = {9, 8, 7, 22, 5, 4, 12, 2, 1, 11};

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10 - 1 -i; j++){
            if(arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }

    for(int i = 0; i < 10; i++){
        cout<<arr[i]<<" ";
    }


}