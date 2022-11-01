#include <iostream>
using namespace std;

struct Student
{
    // Data Portion
    string name, dpt;
    float sgpa, cgpa;
    // Address Portion
    Student *next;
};

Student *head = NULL;

void createNode(Student st)
{
    Student *newNode = new Student;
    newNode->name = st.name;
    newNode->dpt = st.dpt;
    newNode->sgpa = st.sgpa;
    newNode->cgpa = st.cgpa;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else if (head->next == NULL)
    {
        head->next = newNode;
    }
    else
    {
        Student *tmp = head;

        while (tmp != NULL)
        {
            if (tmp->next == NULL)
            {
                tmp->next = newNode;
                break;
            }
            else
            {
                tmp = tmp->next;
            }
        }
    }
}

int main()
{

    Student st;
    st.name = "Muhammad Saad";
    st.dpt = "BS-IT";
    st.sgpa = 3.489;
    st.cgpa = 4.486;

    Student st1;
    st1.name = "Muhammad Waleed";
    st1.dpt = "BS-CS";
    st1.sgpa = 3.569;
    st1.cgpa = 4.555;

    Student st2;
    st2.name = "Muhammad Waleed 2";
    st2.dpt = "BS-CS 2";
    st2.sgpa = 3.5692;
    st2.cgpa = 4.555;

    Student st3;
    st3.name = "Muhammad Saad2";
    st3.dpt = "BS-IT2";
    st3.sgpa = 3.489;
    st3.cgpa = 4.486;

    createNode(st);
    createNode(st1);
    createNode(st2);
    createNode(st3);

    Student *tmp = head;

    while (tmp != NULL)
    {
        cout << "Name >> " << tmp->name << endl;
        tmp = tmp->next;
    }

    return 0;
}