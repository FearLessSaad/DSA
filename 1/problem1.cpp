#include<iostream>
using namespace std;


int main(){

    //Array Of 10 Integers
    int arr[10] = {9, 20, 28, 35, 7, 45, 10, 55, 13, 5};

    //Printing Array On Screen
    cout<<"Array = { ";
    for(int i = 0; i < 10; i++){
        cout<<arr[i];
        (i == 9)?cout<<" ":cout<<", ";
    }
    cout<<"}"<<endl;

    //Finding Smallest Element
    int small = arr[0];
    for(int i = 0;i < 10; i++){
        if(arr[i]<small){
            small = arr[i];
        }
    }
    cout<<"The Smallest Element >> "<<small<<endl;

    return 0;

}