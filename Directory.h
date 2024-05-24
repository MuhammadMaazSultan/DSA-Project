// Directory.h
#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <string>
using namespace std;

class Contact
{
public:
    string firstname;
    string lastname;
    string mobile;
    string home;
    string work;
    string email;
};

class Node
{
public:
    Contact data;
    Node *next;
    Node(Contact);
};

class Directory
{
private:
    Node *head;

public:
    //Code by Ahmed  1218
    Directory();
    void Add_contact(Contact);
    void Display();


    //Code by Mehroz ALi
    void Delete_contact(string, string);

    //Code By Maaz Sultan 1152
    void Edit_contact(string, string);
    void Search_contact(string);
};

#endif
