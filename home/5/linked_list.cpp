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
void loadCSV();

int main()
{

    loadCSV();
    return 0;

}

void loadCSV(){
     fstream fin;
        fin.open("logs.csv", ios::in);
        int chk = 1;
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
                    chk++;
                    break;
                case 2:
                    muhammad_node.muhammad_ip = word;
                    chk++;
                    break;
                case 3:
                    muhammad_node.muhammad_path = word;
                    chk++;
                    break;
                case 4:
                    muhammad_node.muhammad_status = stoi(word);
                    chk++;
                    break;
                case 5:
                    muhammad_node.muhammad_port = stoi(word);
                    chk++;
                    break;
                case 6:
                    muhammad_head->muhammad_time = word;
                    chk++;
                    break;
                }
            }
            chk = 1;
            muhammad_node.next = NULL;
            createNewNode(muhammad_node);
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

bool display()
{
    if (muhammad_head != NULL)
    {
        Logs *muhammad_tmp = muhammad_head;
        while (muhammad_tmp)
        {
            cout << "[" << muhammad_tmp->muhammad_id << "]-[" << muhammad_tmp->muhammad_time << "] " << muhammad_tmp->muhammad_ip << ":" << muhammad_tmp->muhammad_port << " [" << muhammad_tmp->muhammad_status << "] " << muhammad_tmp->muhammad_path << endl;
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
            cout << "[" << muhammad_tmp->muhammad_id << "]-[" << muhammad_tmp->muhammad_time << "] " << muhammad_tmp->muhammad_ip << ":" << muhammad_tmp->muhammad_port << " [" << muhammad_tmp->muhammad_status << "] " << muhammad_tmp->muhammad_path << endl;
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
            cout << "[" << muhammad_tmp->muhammad_id << "]-[" << muhammad_tmp->muhammad_time << "] " << muhammad_tmp->muhammad_ip << ":" << muhammad_tmp->muhammad_port << " [" << muhammad_tmp->muhammad_status << "] " << muhammad_tmp->muhammad_path << endl;
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

void search(int muhammad_port, int muhammad_status){
    Logs *muhammad_tmp = muhammad_head;
    while (muhammad_tmp)
    {
        if (muhammad_port == muhammad_tmp->muhammad_port && muhammad_status == muhammad_tmp->muhammad_status)
        {
            cout << "[" << muhammad_tmp->muhammad_id << "]-[" << muhammad_tmp->muhammad_time << "] " << muhammad_tmp->muhammad_ip << ":" << muhammad_tmp->muhammad_port << " [" << muhammad_tmp->muhammad_status << "] " << muhammad_tmp->muhammad_path << endl;
            break;
        }
        muhammad_tmp = muhammad_tmp->next;
    }
}