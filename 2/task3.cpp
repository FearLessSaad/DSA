#include<iostream>
using namespace std;

struct Permission{
    int id;
    bool hasDeletePer = false;
    bool hasAddPer = false;
    bool hasUpdatePer = false;
};

Permission permissions[10];

void loadData(){
    permissions[1].id  = 1;
    permissions[1].hasAddPer = true;
    permissions[1].hasUpdatePer = true;
    permissions[1].hasDeletePer = true;
}

void showPermission(int id){
    for(int i = 0; i < 10; i++){
        if(id == permissions[i].id){
            if(permissions[i].hasAddPer){
                cout<<"User Has Permission Of Adding New Records."<<endl;
            }
            permissions[i].hasDeletePer?cout<<"User Has Permission Of Deleting Records."<<endl:cout<<"";
            permissions[i].hasUpdatePer?cout<<"User Has Permission Of Updating Records."<<endl:cout<<"";
            break;
        }else{
            if(i == 9){
                cout<<"[!]User Not Fount!\n";
            }
        }
    }

}

int main(){

    loadData();

    int id = 0;
    cout<<"Enter User ID >> ";
    cin>>id;

    showPermission(id);

    return 0;
}