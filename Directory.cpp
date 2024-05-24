#include <iostream>
#include "Directory.h"
using namespace std;
Node ::Node(Contact d)
{
    data = d;
    next = NULL;
}

// Constructor

Directory::Directory()
{
    head = NULL;
}



// Function to delete Contact

void Directory ::Delete_contact(string frstname, string lstname)
{
    if (head == NULL)
    {
        cout << "There is no contact saved in Directory " << endl;
        cout << "--------------------------------------------" << endl;
        return;
    }
    if (head->next == NULL)
    {
        delete head;
        cout << "Contact Deleted Successfully " << endl;
        cout << "--------------------------------------------" << endl;
        head=NULL;
        return;
    }
    if (head->data.firstname == frstname && head->data.lastname == lstname)
    {
        Node *todelete = head;
        head = head->next;
        delete todelete;
        cout << "Contact Deleted Successfully " << endl;
        cout << "--------------------------------------------" << endl;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data.firstname == frstname && temp->next->data.lastname == lstname)
        {
            Node *todelete = temp->next;
            temp->next = temp->next->next;
            delete todelete;
            cout << "Contact Deleted Successfully " << endl;
            cout << "--------------------------------------------" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Contact Not Found " << endl;
    cout << "--------------------------------------------" << endl;
}


}
