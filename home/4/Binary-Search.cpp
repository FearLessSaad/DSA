#include<iostream>
using namespace std;

int main(){

    int arr[15] = {1, 2, 44, 56, 67, 89, 100, 102, 130, 155, 167, 189, 199, 200, 222};
    int first = 0, last = 14, x;
    int mid = (first + last) / 2;

    cout<<"Enter Digit For Find >> ";
    cin>>x;

    while(first <= last){

        if(x == arr[mid]){
            cout<<"Entered Digit Is Found On Index "<<mid<<endl;
            break;
        }else if(x > arr[mid]){
            first = mid + 1;
            mid = (first + last) / 2;
        }else if(x < arr[mid]){
            last = mid -1;
            mid = (first + last) / 2;
        }if(first > last){
            cout<<"Entered Digit Is Not Found In Array."<<endl;
        }

    }

    return 0;
}