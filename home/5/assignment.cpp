#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Logs
{
    int muhammad_id;
    string muhammad_ip, muhammad_path, muhammad_time;
    int muhammad_status, muhammad_port;
    Logs *next;
};

Logs *muhammad_head = NULL;

void loadCSV();
void createNewNode(Logs);
void createNodeAtStart(Logs);
void insertNodeAfterId(Logs, int);
void insertNodeBeforeId(Logs, int);
bool display();
void search(int, int);
void searchByIp(string);
void searchById(int);
void deleteFirst();
void deleteLast();
void deleteById(int);
void updateNode(string, int);

int main()
{

    loadCSV();

    cout<<"Display All List"<<endl;
    display();

    Logs * muhammad_node = muhammad_head->next->next;
    muhammad_node->muhammad_id = 14;
    createNodeAtStart(*muhammad_node);

    muhammad_head->muhammad_id = 15;
    insertNodeAfterId(*muhammad_head, 5);

    muhammad_node->muhammad_id = 16;
    insertNodeBeforeId(*muhammad_node, 13);

    cout<<endl<<"Search By Port And Status Code"<<endl;
    search(443, 404);

    cout<<endl<<"Search By IP Address"<<endl;
    searchByIp("192.168.1.107");

    cout<<endl<<"Search By ID"<<endl;
    searchById(4);

    deleteFirst();

    deleteLast();

    deleteById(7);

    updateNode("07:00:00 PM", 3);

    cout<<endl<<"Final Results"<<endl;
    display();
    return 0;
}

void loadCSV()
{
    fstream fin;
    fin.open("logs.csv", ios::in);
    int chk = 1, i = 0;
    string line, word;
    while (fin)
    {
        Logs muhammad_node;
        getline(fin, line);
        stringstream s(line);
        while (getline(s, word, ','))
        {
            switch (chk)
            {
            case 1:
                muhammad_node.muhammad_id = stoi(word);
                break;
            case 2:
                muhammad_node.muhammad_ip = word;
                break;
            case 3:
                muhammad_node.muhammad_path = word;
                break;
            case 4:
                muhammad_node.muhammad_status = stoi(word);
                break;
            case 5:
                muhammad_node.muhammad_port = stoi(word);
                break;
            case 6:
                muhammad_node.muhammad_time = word;
                break;
            default:
                    break;
            }
            chk++;
        }
        chk = 1;
        muhammad_node.next = NULL;
        createNewNode(muhammad_node);
        i++;
        if(i == 13) break;
    }
}

void createNewNode(Logs l)
{
    Logs *muhammad_node = new Logs;
    *muhammad_node = l;

    if (muhammad_head == NULL)
    {
        muhammad_head = muhammad_node;
    }
    else if (muhammad_head->next == NULL)
    {
        muhammad_head->next = muhammad_node;
    }
    else
    {
        Logs *muhammad_tmp = muhammad_head;

        while (muhammad_tmp)
        {
            if (muhammad_tmp->next == NULL)
            {
                muhammad_tmp->next = muhammad_node;
                break;
            }
            else
            {
                muhammad_tmp = muhammad_tmp->next;
            }
        }
    }
}

void createNodeAtStart(Logs l)
{
    Logs *muhammad_node = new Logs;
    *muhammad_node = l;

    if (muhammad_head == NULL)
    {
        muhammad_head = muhammad_node;
    }
    else
    {
        muhammad_node->next = muhammad_head;
        muhammad_head = muhammad_node;
    }
}

void insertNodeAfterId(Logs l, int muhammad_id)
{
    Logs *muhammad_newNode = new Logs;
    *muhammad_newNode = l;

    if (muhammad_head == NULL)
    {
        muhammad_head = muhammad_newNode;
        muhammad_head->next = NULL;
    }
    else
    {
        Logs *muhammad_tmp = muhammad_head;
        while (muhammad_tmp)
        {
            if (muhammad_tmp->muhammad_id == muhammad_id)
            {
                muhammad_newNode->next = muhammad_tmp->next;
                muhammad_tmp->next = muhammad_newNode;
                break;
            }
            else if (muhammad_tmp->next != NULL)
            {
                muhammad_tmp = muhammad_tmp->next;
            }
            else
            {
                cout << "Id Not Found!!";
                break;
            }
        }
    }
}

void insertNodeBeforeId(Logs l, int muhammad_id)
{
    Logs *muhammad_newNode = new Logs;
    *muhammad_newNode = l;

    Logs *muhammad_tmp = muhammad_head;

    if (muhammad_head == NULL)
    {
        muhammad_head = muhammad_newNode;
        muhammad_head->next = NULL;
    }
    else if (muhammad_tmp->muhammad_id == muhammad_id)
    {
        createNodeAtStart(*muhammad_newNode);
    }
    else
    {
        while (muhammad_tmp)
        {
            if (muhammad_tmp->next->muhammad_id == muhammad_id)
            {

                muhammad_newNode->next = muhammad_tmp->next;
                muhammad_tmp->next = muhammad_newNode;
                break;
            }
            else if (muhammad_tmp->next != NULL)
            {
                muhammad_tmp = muhammad_tmp->next;
            }
            else
            {
                cout << "Id Not Found!!";
                break;
            }
        }
    }
}

void show(Logs* muhammad_tmp){
    cout << "[" << muhammad_tmp->muhammad_id << "]-[" << muhammad_tmp->muhammad_time << "] " << muhammad_tmp->muhammad_ip << ":" << muhammad_tmp->muhammad_port << " [" << muhammad_tmp->muhammad_status << "] " << muhammad_tmp->muhammad_path << endl;
}

bool display()
{
    if (muhammad_head != NULL)
    {
        Logs *muhammad_tmp = muhammad_head;
        while (muhammad_tmp)
        {
            show(muhammad_tmp);
            muhammad_tmp = muhammad_tmp->next;
        }
        return true;
    }
    return false;
}

void searchByIp(string muhammad_ip)
{
    Logs *muhammad_tmp = muhammad_head;
    while (muhammad_tmp)
    {
        if (muhammad_ip == muhammad_tmp->muhammad_ip)
        {
            show(muhammad_tmp);
        }
        muhammad_tmp = muhammad_tmp->next;
    }
}

void searchById(int muhammad_id)
{
    Logs *muhammad_tmp = muhammad_head;
    while (muhammad_tmp)
    {
        if (muhammad_id == muhammad_tmp->muhammad_id)
        {
            show(muhammad_tmp);
            break;
        }
        muhammad_tmp = muhammad_tmp->next;
    }
}

void deleteFirst()
{
    muhammad_head = muhammad_head->next;
}

void deleteLast()
{
    if (muhammad_head->next == NULL)
    {
        muhammad_head = NULL;
    }
    else
    {
        Logs *muhammad_tmp = muhammad_head;
        while (muhammad_tmp)
        {
            if (muhammad_tmp->next->next == NULL)
            {
                muhammad_tmp->next = muhammad_tmp->next->next;
                break;
            }
            else
            {
                muhammad_tmp = muhammad_tmp->next;
            }
        }
    }
}

void deleteById(int muhammad_id)
{
    if (muhammad_head->muhammad_id == muhammad_id && muhammad_head != NULL)
    {
        muhammad_head = muhammad_head->next;
    }
    else
    {
        Logs *muhammad_tmp = muhammad_head;

        while (muhammad_tmp)
        {
            if (muhammad_tmp->next->muhammad_id == muhammad_id)
            {
                muhammad_tmp->next = muhammad_tmp->next->next;
                break;
            }
            else
            {
                muhammad_tmp = muhammad_tmp->next;
            }
        }
    }
}

void updateNode(string muhammad_time, int muhammad_id)
{
    Logs *muhammad_tmp = muhammad_head;

    while (muhammad_tmp)
    {
        if (muhammad_tmp->muhammad_id == muhammad_id)
        {
            muhammad_tmp->muhammad_time = muhammad_time;
            break;
        }
        else
        {
            muhammad_tmp = muhammad_tmp->next;
        }
    }
}

void search(int muhammad_port, int muhammad_status)
{
    Logs *muhammad_tmp = muhammad_head;
    while (muhammad_tmp)
    {
        if (muhammad_port == muhammad_tmp->muhammad_port && muhammad_status == muhammad_tmp->muhammad_status)
        {
            show(muhammad_tmp);
            break;
        }
        muhammad_tmp = muhammad_tmp->next;
    }
}