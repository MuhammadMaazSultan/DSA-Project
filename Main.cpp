#include <iostream>
#include <string>
#include "Directory.h"
using namespace std;

int main()
{
    string firstname, lastname, search, edit;

    Directory d;
    int choice;
    Contact newcontact;
    do
    {
        cout << "Main Menu: " << endl;
        cout << "Please Select one " << endl;
        cout << "1: To add Contact " << endl;
        cout << "2: To Display Contacts " << endl;
        cout << "3: To Delete Contact " << endl;
        cout << "4: To Search Contact " << endl;
        cout << "5: Edit Contact " << endl;
        cout << "6: To exit " << endl;
        cin >> choice;
        cin.ignore(); // Clear the newline character left by cin

        switch (choice)
        {
        case 1:
            cout << "Enter First Name " << endl;
            cin >> newcontact.firstname;
            cin.ignore();
            cout << "Enter Last Name " << endl;
            cin >> newcontact.lastname;
            cin.ignore();
            cout << "Enter Mobile Number " << endl;
            cin >> newcontact.mobile;
            cin.ignore();
            cout << "Enter Home Number (Optional: Press Enter to skip) " << endl;
            getline(cin, newcontact.home);
            cout << "Enter Work Number (Optional: Press Enter to skip) " << endl;
            getline(cin, newcontact.work);
            cout << "Enter E-mail Address (Optional: Press Enter to skip)" << endl;
            getline(cin, newcontact.email);
            d.Add_contact(newcontact);
            break;
        case 2:
            cout << "Displaying All Contacts " << endl;
            d.Display();
            break;
        case 3:
            cout << "Enter First Name of contact to delete " << endl;
            cin >> firstname;
            cout << "Enter Last Name of contact to delete " << endl;
            cin >> lastname;

            d.Delete_contact(firstname, lastname);
            break;
        case 4:
            cout << "Enter Name / Phone number to search contact " << endl;
            cin >> search;
            d.Search_contact(search);
            break;
        case 5:
            cout << "Enter First Name of contact to edit " << endl;
            cin >> firstname;
            cout << "Enter Last Name of contact to edit " << endl;
            cin >> lastname;

            d.Edit_contact(firstname, lastname);
            break;
        case 6:
            cout << "Exiting the app " << endl;
            cout << "--------------------------------------------" << endl;
            break;
        default:
            cout << "Invalid Number Entered; Please Enter the number between 1-6 only " << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}
