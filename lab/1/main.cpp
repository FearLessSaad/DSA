#include<iostream>
using namespace std;

struct Student
{
    int id;
    string fullName, Class, dept;
};

Student addData(Student &_std){
    cout<<"Enter ID >> ";
    cin>>_std.id;
    cout<<"Enter Full Name >> ";
    cin>>_std.fullName;
    cout<<"Enter Class >> ";
    cin>>_std.Class;
    cout<<"Enter Department >> ";
    cin>>_std.dept;

    return _std;
}

void shodData(Student _std){
    cout<<"ID: "<<_std.id<<endl;
    cout<<"Full Name: "<<_std.fullName<<endl;
    cout<<"Class: "<<_std.Class<<endl;
    cout<<"Depaetment: "<<_std.dept<<endl;
}

void showHeader(){
    cout<<"===================================="<<endl;
    cout<<"===================================="<<endl;
}

int main(){

    Student _std;

    showHeader();

    _std = addData(_std);
    
    showHeader();

    shodData(_std);

}