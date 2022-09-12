#include<iostream>

using namespace std;

struct User{
    int id;
    string fullName;
    string username;
    string password;
    bool isAdmin;
};

int main(){

    User users[10];

    users[1].id = 1;
    users[1].fullName = "Muhammad Saad";
    users[1].username = "ghostx64";
    users[1].password = "12345";
    users[1].isAdmin = true;

    string user, pass;
    cout<<"Enter Username >> ";
    cin>>user;
    cout<<"Enter Password >> ";
    cin>>pass;

    for(int i = 0; i < 10; i++){
        if(users[i].username == user && users[i].password == pass){
            if(users[i].isAdmin){
                cout<<"[*] Successfully Logged In As Admin.";
                break;
            }else{
                cout<<"[+] Logged In Successfully";
                break;
            }
        }else{
            if(i == 9){
                cout<<"[!] Incorrect Username OR Password!";
            }
        }
    }

    return 0;
}