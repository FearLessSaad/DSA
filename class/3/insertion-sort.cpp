#include<iostream>
using namespace std;


int main(){

    int arr[6] = {15, 9, 3, 17, 2, 6};

    for(int i = 1; i < 6; i++){
        for(int j = i; j > 0; j--){
            if(arr[j] < arr[j-1]){
                int tmp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = tmp;
            }else{
                break;
            }
        }
    }

    for(int i = 0; i < 6; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}