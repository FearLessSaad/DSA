#include<iostream>

using namespace std;

struct Person {
    int id;
    string name;
    Person *prev;
    Person *next;
};

Person *head = NULL;
Person *tail = NULL;

void createNewNode(Person person){
    Person *node = new Person();
    *node = person;

    if(head == NULL){
        head = node;
        head->prev = NULL;
        head->next = NULL;
        tail = node;
    }else{
        tail->next = node;
        node->prev = tail;
    }
}

void display(){
    if(head == NULL){
        cout<<"List Is Empity!"<<endl;
    }else{
         Person *tmp = head;

        do{
            cout<<"Id >> "<<tmp->id<<endl<<"Name >> "<<tmp->name<<endl;
            tmp = tmp->next;
        }while(tmp->next != NULL);
    }
}


int main(){

    Person p1 = {1, "Saad"};
    Person p2 = {2, "Waleed"};
    Person p3 = {3, "Arshman"};
    Person p4 = {4, "Zeshii"};

    createNewNode(p1);
    createNewNode(p2);
    createNewNode(p3);
    createNewNode(p4);

    display();


    return 0;
}