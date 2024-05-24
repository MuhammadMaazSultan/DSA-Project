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
    void Delete_contact(string, string);
};

#endif
