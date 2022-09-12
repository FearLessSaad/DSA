#include <iostream>
using namespace std;

int main()
{
    int a = 10; 
    int b = 20;
    int c = 30;
    if (a < b)
    { 
        cout << " a is less than b " << endl;
        if (b < c)
        { 
            cout << " b is less than c " << endl;
            if (a < c)
            { 
                cout << " a is less than c " << endl;
            }
        }
    }

    return 0;
}