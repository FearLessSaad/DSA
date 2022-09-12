#include<iostream>
using namespace std;


int main(){

    //Array Of 10 Integers
    int arr[10] = {9, 20, 28, 35, 7, 45, 10, 55, 13, 5};

    float avg = 0.0;
    int sum = 0;

    for(int i = 0; i < 10; i++){
        sum += arr[i];
    }

    avg = sum/10;

    cout<<"Average = "<<avg<<endl;

    return 0;

}