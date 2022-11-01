#include<iostream>
using namespace std;

int main(){

    int arr[10] = {9, 8, 7, 22, 5, 4, 12, 2, 1, 11};

    for(int i = 0; i < 10; i++){
        int min = i;

        for(int j = i; j < 10; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }

        int tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
        
    }

    for(int i = 0; i < 10; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}