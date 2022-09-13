#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {1, 2, 3, 4, 4, 1, 3, 8, 9, 10};

    for(int i = 0; i < 10; i++){
        for(int j = i+1; j < 10; j++){
            if(arr[i] == arr[j]){
                cout<<arr[i]<<" Repeats."<<endl;
                break;
            }
        }
    }

    return 0;
}