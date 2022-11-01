#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *link;
};

Node *top = NULL;

void push(int data)
{

    Node *temp = new Node;
    temp->data = data;

    temp->link = top;

    top = temp;
}

void peek()
{
    if (top != NULL){
        cout << top->data;
    }else{
        cout<<"Stack Is Empity!"<<endl;
    }
}

void pop()
{
    Node *temp;

    if (top == NULL)
    {
        cout << "Stack Is Empity" << endl;
        exit(1);
    }
    else
    {
        temp = top;

        top = top->link;

        free(temp);
    }
}

void display()
{
    Node *temp;

    if (top == NULL)
    {
        cout << "Stack Is Empity"<<endl;
        exit(1);
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
            cout << temp->data<<endl;
            temp = temp->link;
        }
    }
}

int main()
{

    push(11);
    push(22);
    push(33);
    push(44);

    display();

    cout << "Top element is ";
    peek();
    cout<<endl;

    pop();
    pop();

    display();

    cout << "Top element is ";
    peek();
    cout<<endl;

    return 0;
}