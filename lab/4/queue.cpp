#include <iostream>

using namespace std;

struct Process
{
    int pId;
    string pName;
    Process *next;
};

Process *front = NULL;

bool isEmpity()
{
    if (front == NULL)
    {
        return true;
    }
    return false;
}

void enQueue(Process p)
{
    Process *newNode = new Process;
    *newNode = p;

    if (isEmpity())
    {
        front = newNode;
        front->next = NULL;
    }
    else
    {
        newNode->next = front;
        front = newNode;
    }
}

void deQueue()
{
    Process *tmp = front;
    while (tmp != NULL)
    {
        if (tmp->next->next == NULL)
        {
            tmp->next = NULL;
            break;
        }
        else
        {
            tmp = tmp->next;
        }
    }
}

void display()
{
    if (isEmpity())
    {
        cout << "Queue Is Empity." << endl;
    }
    else
    {
        Process *tmp = front;
        while (tmp)
        {
            cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;
            cout << "[+]Process ID >> " << tmp->pId << endl;
            cout << "[+]Process Name >> " << tmp->pName << endl;
            tmp = tmp->next;
        }
        cout << "++++++++++++++++++++++++++++++++++++++++++++" << endl;
    }
}

int main()
{

    Process p1 = {1, "Metasploit"};
    Process p2 = {2, "BurpSuit"};
    Process p3 = {3, "WireShark"};

    enQueue(p1);
    enQueue(p2);
    enQueue(p3);

    deQueue();

    display();

    return 0;
}