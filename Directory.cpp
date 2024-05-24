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


//Code by Ahmed 1218

// Function to add Contact

void Directory::Add_contact(Contact d)
{
    Node *n = new Node(d);
    if (head == NULL)
    {
        head = n;
        cout << "Contact Saved Successfully " << endl;
        cout << "--------------------------------------------" << endl;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    cout << "Contact Saved Successfully " << endl;
    cout << "--------------------------------------------" << endl;
}


// Function to Display Contacts

void Directory ::Display()
{
    if (head == NULL)
    {
        cout << "Contact List is empty " << endl;
        cout << "--------------------------------------------" << endl;
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        cout << "Name: " << temp->data.firstname << " " << temp->data.lastname << endl;
        cout << "Phone No: " << temp->data.mobile << endl;
        cout << "Home No: " << temp->data.home << endl;
        cout << "Work No: " << temp->data.work << endl;
        cout << "Email: " << temp->data.email << endl;
        cout << "--------------------------------------------" << endl;
        temp = temp->next;
    }
}


// Code by Maaz Sultan 1152
// Funtion to edit Contact

void Directory::Edit_contact(string frstname, string lstname)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (head->data.firstname == frstname && head->data.lastname == lstname)
        {
            cout << "Enter new details of contact " << endl
                 << endl;
            cout << "Enter New First Name " << endl;
            cin >> temp->data.firstname;
            cin.ignore();
            cout << "Enter New Last Name " << endl;
            cin >> temp->data.lastname;
            cin.ignore();
            cout << "Enter New Mobile Number " << endl;
            cin >> temp->data.mobile;
            cin.ignore();
            cout << "Enter New Home Number (Optional: Press Enter to skip) " << endl;
            getline(cin, temp->data.home);
            cout << "Enter New Work Number (Optional: Press Enter to skip) " << endl;
            getline(cin, temp->data.work);
            cout << "Enter New E-mail Address (Optional: Press Enter to skip)" << endl;
            getline(cin, temp->data.email);
            cout << "Contact edited Successfully " << endl;
            cout << "--------------------------------------------" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Contact Not found in Directory " << endl;
    cout << "--------------------------------------------" << endl;
}

// Function to Search Contact

void Directory::Search_contact(string search)
{
    bool found = false;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data.firstname.find(search) != string::npos || temp->data.lastname.find(search) != string::npos || temp->data.mobile.find(search) != string::npos ||
            temp->data.home.find(search) != string::npos ||
            temp->data.work.find(search) != string::npos ||
            temp->data.email.find(search) != string::npos)
        {
            cout << "Contact Found Successfully " << endl;
            cout << "Name: " << temp->data.firstname << " " << temp->data.lastname << endl;
            cout << "Phone No: " << temp->data.mobile << endl;
            cout << "Home No: " << temp->data.home << endl;
            cout << "Work No: " << temp->data.work << endl;
            cout << "Email: " << temp->data.email << endl;
            cout << "--------------------------------------------" << endl;
            found = true;
        }
        temp = temp->next;
    }
    if (!found)
    {
        cout << "Contact Not found " << endl;
        cout << "--------------------------------------------" << endl;
    }
}
