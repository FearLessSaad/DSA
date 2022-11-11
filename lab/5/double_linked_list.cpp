#include <iostream>
using namespace std;

struct Book
{
    int ISBAN;
    string title, auther;

    Book *prev;
    Book *next;
};

Book *head = NULL;
Book *tail = NULL;

void createNode(Book book)
{
    Book *newNode = new Book;
    *newNode = book;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        head->next = NULL;
        head->prev = NULL;
    }
    else
    {
        Book *tmp = head;

        while (tmp != NULL)
        {
            if (tmp->next == NULL)
            {
                tmp->next = newNode;
                newNode->prev = tmp;
                tail = newNode;
                break;
            }
            else
            {
                tmp = tmp->next;
            }
        }
    }
}

void insertAtStart(Book book)
{
    Book *newNode = new Book;
    *newNode = book;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        head->next = NULL;
        head->prev = NULL;
    }
    else
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        head->prev = NULL;
    }
}

void deleteLast()
{
    Book *tmp = head;

    if (head == NULL)
    {
        cout << "List Is Empity!!" << endl;
    }
    else
    {
        while (tmp != NULL)
        {
            if (tmp->next == NULL)
            {
                tail = tmp->prev;
                tmp->prev->next = NULL;
                break;
            }
            else
            {
                tmp = tmp->next;
            }
        }
    }
}

void deleteFirst()
{

    Book *tmp = head;

    if (head == NULL)
    {
        cout << "List Is Empity!!" << endl;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }
}

void displayNode(Book *tmp)
{
    cout << "=============================================" << endl;
    cout << "ISBAN >>  " << tmp->ISBAN << endl;
    cout << "Title >>  " << tmp->title << endl;
    cout << "Auther >> " << tmp->auther << endl;
    cout << "=============================================" << endl;
}

void search(int isban)
{
    if (head == NULL)
    {
        cout << "List Is Empity!!" << endl;
    }
    else
    {
        Book *tmp = head;

        while (tmp != NULL)
        {
            if (tmp->ISBAN == isban)
            {
                displayNode(tmp);
                break;
            }
            else
            {
                tmp = tmp->next;
            }
        }
    }
}

void display()
{
    if (head == NULL)
    {
        cout << "List Is Empity!!" << endl;
    }
    else
    {
        Book *tmp = head;
        do
        {
            cout << "=============================================" << endl;
            cout << "ISBAN >>  " << tmp->ISBAN << endl;
            cout << "Title >>  " << tmp->title << endl;
            cout << "Auther >> " << tmp->auther << endl;
            tmp = tmp->next;
        } while (tmp != NULL);
        cout << "=============================================" << endl;
    }
}

int main()
{
    
    Book b1 = {1111, "C++", "Ihsan Elahi"};
    Book b2 = {2222, "C#", "Ihsan Elahi"};
    Book b3 = {3333, "Java", "Adams"};
    Book b4 = {4444, "CEH", "EC-Council"};

    createNode(b1);
    createNode(b2);
    createNode(b3);
    insertAtStart(b4);
    deleteLast();
    deleteFirst();

    display();

    cout<<"Search ISBAN = 2222 "<<endl;
    search(2222);

    return 0;
}