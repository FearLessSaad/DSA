#include<iostream>
using namespace std;

struct  Student
{
    //Data Portion
    string name, dpt;
    float sgpa, cgpa;
    //Address Portion
    Student* next;
};


int main(){

    Student* node1 = new Student;
    

    return 0;
}