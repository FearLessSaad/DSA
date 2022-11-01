#include <iostream>
using namespace std;

struct Logs
{
    int id;
    string ip, path, time;
    int status, port;
    Logs *next;
};

Logs *head = NULL;

void createNewNode(Logs l)
{
    Logs *node = new Logs;
    *node = l;

    if (head == NULL)
    {
        head = node;
        head->next = head;
    }
    else
    {
        Logs *tmp = head;

        do{
            if (tmp->next == head)
            {
                tmp->next = node;
                node->next = head;
                break;
            }
            else
            {
                tmp = tmp->next;
            }
        } while (tmp != head);
    }
}

void createNodeAtStart(Logs l)
{
    Logs *node = new Logs;
    *node = l;

    if (head == NULL)
    {
        head = node;
        head->next = head;
    }
    else
    {

        node->next = head;

        Logs *tmp = head;

        do
        {
            if (tmp->next == head)
            {
                head = node;
                tmp->next = head;
                break;
            }
            else
            {
                tmp = tmp->next;
            }
        } while (tmp != head);
    }
}

void display()
{
    Logs *tmp = head;
    do
    {
        cout << "[" << tmp->id << "]-[" << tmp->time << "] " << tmp->ip << ":" << tmp->port << " [" << tmp->status << "] " << tmp->path << endl;
        tmp = tmp->next;
    } while (tmp != head);
}

void searchById(int id)
{
    Logs *tmp = head;
    do
    {
        if (id == tmp->id)
        {
            cout << "[" << tmp->id << "]-[" << tmp->time << "] " << tmp->ip << ":" << tmp->port << " [" << tmp->status << "] " << tmp->path << endl;
            break;
        }
        tmp = tmp->next;
    } while (tmp != head);
}

void deleteFirst()
{
    head = head->next;

    Logs *tmp = head;

    do
    {
        if (tmp->next == head)
        {
            tmp->next = head;
            break;
        }
        else
        {
            tmp = tmp->next;
        }
    } while (tmp != head);
}

void deleteLast()
{
    if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        Logs *tmp = head;

        do
        {
            if (tmp->next->next == head)
            {
                tmp->next = head;
                break;
            }
            else
            {
                tmp = tmp->next;
            }
        } while (tmp != head);
    }
}

int main()
{

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

    deleteLast();
    deleteFirst();

    display();
}