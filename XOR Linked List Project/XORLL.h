#ifndef XORLL_H_INCLUDED
#define XORLL_H_INCLUDED
#include <bits/stdc++.h>
#include <inttypes.h>
#include <conio.h>
#include "Node.h"
#include "interface.h"
using namespace std;
int x, i, input;

Node* XOR (Node *previous, Node *next)
{
    return (Node*) ((uintptr_t) (previous) ^ (uintptr_t) (next));
}

void insert(Node **head, int data)
{
    Node *temp = new Node();
    temp->data = data;

    temp->npx = *head;
    if (*head != NULL)
    {
        (*head)->npx = XOR(temp, (*head)->npx);
    }
    *head = temp;
}

void insert_multiple()
{
    system("cls");
    cout << "How many numbers do you want to add?";
    cin >> x;
    int input;
    for(i=0; i<x; i++)
    {
        cout << "\tEnter number " << i+1 <<": " ;
        cin >> input;
        insert(&head,input);
    }
}

int size()
{
    int count = 0;
    Node *current = head;
    Node *previous = NULL;
    Node *next;
    while(current!=NULL)
    {
        next = XOR (previous, current->npx);
        previous = current;
        current = next;
        count++;
    }
    return count;
}

void delete_all()
{
    head -> data = 0;
    head -> npx = NULL;
}

void printList ()
{
    Node *current = head;
    Node *previous = NULL;
    Node *next;
    cout << "Following are the nodes of Linked List: \n";
    while (current != NULL)
    {
        cout<<current ->data<<" ";
        next = XOR (previous,current->npx);
        previous = current;
        current = next;
    }
    getch();
}
void print_First()
{
    Node *current = head;
    cout << "First Element of Linked List: \n";
    cout<<current->data;
    getch();
}

void print_Last()
{
    Node *current = head;
    Node *previous = NULL;
    Node *next;

    cout << "Last Element of Linked List: \n";

    while (current != NULL)
    {
        next = XOR (previous, current->npx);
        previous = current;
        current = next;
    }
    cout << previous->data;
    getch();
}

void print_toPos(int x)
{
    Node *current = head;
    Node *previous = NULL;
    Node *next;
    cout << "\n\tEnter Position: ";
    cin >> x;

    if(x < size() || x == size())
    {
        cout << "Data in position "<< x << ": ";
        for(i=1; i<x; i++)
        {
            next = XOR (previous, current->npx);
            previous = current;
            current = next;
        }
        cout << current->data;
    }
    getch();
}

void search_element()
{
    int count=1;
    bool found = false;
    cout << "Enter Element to Search: ";
    cin >> x;
    Node *current = head;
    Node *previous = NULL;
    Node *next;
    system("cls");
    while (current != NULL)
    {
        if(current ->data == x)
        {
            system("color 2");
            cout << "\n\tElement Found!!" <<endl;
            cout << "\n\tFound at Position : " << count <<endl;
            found = true;
            break;
        }
        else
        {
            next = XOR (previous, current->npx);
            previous = current;
            current = next;
            count++;
        }
    }
    if(found == false)
    {
        system("color 4");
        cout << "\n\n\tElement not found!!";
    }
    getch();
}

void search_toPos()
{
    Node *current = head;
    Node *previous = NULL;
    Node *next;
    cout << "\n\tEnter Position: ";
    cin >> x;
    system("cls");
    if(x < size() || x == size())
    {
        system("color 2");
        cout << "\n\tElement Found!!";
        cout << "\n\tData in position "<< x << ": ";
        for(i=1; i<x; i++)
        {
            next = XOR (previous, current->npx);
            previous = current;
            current = next;
        }
        cout << current->data;
    }
    else
    {
        system("color 4");
        cout << "\n\n\tPosition invalid!!";
    }
    getch();
}

#endif // XORLL_H_INCLUDED
