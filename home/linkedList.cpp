#include<iostream>
using namespace  std;

struct Logs{
    int id;
    string ip, path,time;
    int status, port;
    Logs * next;
};

Logs * head = NULL;

void createNewNode(Logs l){
    Logs * node = new Logs;
    *node = l;

    if(head == NULL){
        head = node;
    }else if(head->next == NULL){
        head->next = node;
    }else{
        Logs * tmp = head;

        while(tmp){
            if(tmp->next == NULL){
                tmp->next = node;
                break;
            }else{
                tmp = tmp->next;
            }
        }
    }
    
}

void createNodeAtStart(Logs l){
    Logs * node = new Logs;
    *node = l;

    if(head == NULL){
        head = node;
    }else{
        node->next = head;
        head = node;
    }
}

void display(){
    Logs * tmp = head;
    while(tmp){
        cout<<"["<<tmp->id<<"]-["<<tmp->time<<"] "<<tmp->ip<<":"<<tmp->port<<" ["<<tmp->status<<"] "<<tmp->path<<endl;
        tmp = tmp->next;
    }
}

void searchByStatus(int s_code){
    Logs * tmp = head;
    while(tmp){
        if(s_code == tmp->status){
            cout<<"["<<tmp->id<<"]-["<<tmp->time<<"] "<<tmp->ip<<":"<<tmp->port<<" ["<<tmp->status<<"] "<<tmp->path<<endl;
        }
        tmp = tmp->next;
    }
}

void searchByIP(string ip){
    Logs * tmp = head;
    while(tmp){
        if(ip == tmp->ip){
            cout<<"["<<tmp->id<<"]-["<<tmp->time<<"] "<<tmp->ip<<":"<<tmp->port<<" ["<<tmp->status<<"] "<<tmp->path<<endl;
        }
        tmp = tmp->next;
    }
}

void searchById(int id){
    Logs * tmp = head;
    while(tmp){
        if(id == tmp->id){
            cout<<"["<<tmp->id<<"]-["<<tmp->time<<"] "<<tmp->ip<<":"<<tmp->port<<" ["<<tmp->status<<"] "<<tmp->path<<endl;
            break;
        }
        tmp = tmp->next;
    }
}

void deleteFirst(){
    head = head->next;
}

void insertAfterSpecificId(Logs l, int id){
    Logs *newNode = new Logs;
    
    if(head->id == id && head != NULL){
        head = head->next;
    }else{
        Logs * tmp = head;

        while(tmp){
            if(tmp->next->id == id){
                tmp->next = tmp->next->next;
                break;
            }else{
                tmp = tmp->next;
            }
        }
    }
}

void deleteLast(){
    if(head->next == NULL){
        head = NULL;
    }else{
        Logs * tmp = head;
        while(tmp){
            if(tmp->next->next == NULL){
                tmp->next = tmp->next->next;
                break;
            }else{
                tmp = tmp->next;
            }
        }
    }
}

void deleteById(int id){
    if(head->id == id && head != NULL){
        head = head->next;
    }else{
        Logs * tmp = head;

        while(tmp){
            if(tmp->next->id == id){
                tmp->next = tmp->next->next;
                break;
            }else{
                tmp = tmp->next;
            }
        }
    }
}

int main(){

    Logs l;
    l.id = 1;
    l.ip = "192.168.1.156";
    l.path = "/var/www/index.php";
    l.status = 200;
    l.port = 443;
    l.time = "19:20:30";
    l.next = NULL;

    Logs l1;
    l1.id = 2;
    l1.ip = "192.168.1.115";
    l1.path = "/var/www/shell.php";
    l1.status = 404;
    l1.port = 443;
    l1.time = "19:21:38";
    l1.next = NULL;

    Logs l2;
    l2.id = 3;
    l2.ip = "192.168.1.156";
    l2.path = "/var/www/shell.php";
    l2.status = 404;
    l2.port = 443;
    l2.time = "19:25:11";
    l2.next = NULL;

    Logs l3;
    l3.id = 4;
    l3.ip = "192.168.1.115";
    l3.path = "/var/www/home.php";
    l3.status = 200;
    l3.port = 443;
    l3.time = "19:26:28";
    l3.next = NULL;

    createNewNode(l);
    createNewNode(l1);
    createNewNode(l2);
    createNodeAtStart(l3);

    //deleteLast();
    //deleteFirst();
    //deleteById(3);

    display();
    
    cout<<endl<<"Diplay 404 Status Code"<<endl;
    searchByStatus(404);
    cout<<endl<<"Diplay 200 Status Code"<<endl;
    searchByStatus(200);
    cout<<endl<<"Display Logs By ID = 2"<<endl;
    searchById(2);

}