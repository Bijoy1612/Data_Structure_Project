#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED
#include <bits/stdc++.h>
#include <time.h>
#include <conio.h>
#include "Node.h"
#include "XORLL.h"
using namespace std;
int choice, sub_choice, n;

//success and fail messages
void success()
{
    system("cls");
    system("color 2");
    cout << "\n\n\t\tSUCCESS!!" << endl;
    getch();
}

void fail()
{
    system("cls");
    system("color 4");
    cout << "\n\n\t\tFAIL!!" << endl;
    getch();
}

//sub menu
void add_operation(int sub_choice)
{
    switch(sub_choice)
    {
        case 1: cout <<"Enter element to add to the list: ";
                cin >> n;
                insert(&head, n);
                success();
                break;
        case 2: insert_multiple();
                success();
                break;
    }
}

void delete_operation(int sub_choice)
{
    switch(sub_choice)
    {
        case 1: delete_all();
                success();
                break;
    }
}

void print_operation(int sub_choice)
{
    switch(sub_choice)
    {
        case 1: system("cls");
                printList();
                break;
        case 2: system("cls");
                print_First();
                break;
        case 3: system("cls");
                print_Last();
                break;
        case 4: system("cls");
                print_toPos(0);
                break;
        case 5: system("cls");
                cout << "Size of the List: " << size() << endl;
                break;
    }
}

void search_operation(int sub_choice)
{
    switch(sub_choice)
    {
        case 1: system("cls");
                search_element();
                break;
        case 2: system("cls");
                search_toPos();
                break;
    }
}

//main menu
void menu()
        {
            choice = -1;
            system("color F");
            system("cls");

            cout << "\n\n\t\t*** WELCOME TO XOR LINKED LIST ADT ***" << endl;
            cout << "\n\tChoose An Operation:" << endl;
            cout << "\n\t1. ADD Operations\t2. DELETE Operations\n\t3. PRINT Operations\t4. SEARCH Operations" << endl;
            cout << "\t0. EXIT" << endl;

            menu_choice:
                cin >> choice;
                if(choice < 0 || choice > 5)
                {
                    cout << "\n\tEnter a valid choice please: ";
                    goto menu_choice;
                }

            sub_choice = -1;
            switch(choice)
            {
                case 1: system("cls");
                        cout << "\n\n\t\t*** ADD operation selected ***" << endl;
                        cout << "\n\tChose your option:" << endl;
                        cout << "\n\t1. ADD Element\t2. ADD Multiple Elements\n\t0. Go Back" << endl;
                        cin >> sub_choice;
                        add_operation(sub_choice);
                        break;

                case 2: system("cls");
                        cout << "\n\n\t\t*** DELETE operation selected ***" << endl;
                        cout << "\n\tChose your option" << endl;
                        cout << "\n\t1. DELETE List\n\t0. Go Back" << endl;
                        cin >> sub_choice;
                        delete_operation(sub_choice);
                        break;

                case 3: system("cls");
                        cout << "\n\n\t\t*** PRINT operation selected ***" << endl;
                        cout << "\n\tChose your operation:" << endl;
                        cout << "\n\t1. DISPLAY Linked List\t2. PRINT First Element" << endl;
                        cout << "\n\t3. PRINT Last Element\t4.  PRINT from Position" << endl;
                        cout << "\n\t5. PRINT size \n\t0. Go Back" << endl;
                        cin >> sub_choice;
                        print_operation(sub_choice);
                        break;

                case 4: system("cls");
                        cout << "\n\n\t\t*** SEARCH operation selected ***" << endl;
                        cout << "\n\t1. SEARCH Element\t2. SEARCH Position" <<endl;
                        cout << "\n\t0. Go Back" << endl;
                        cin >> sub_choice;
                        search_operation(sub_choice);
                        break;

                case 0: system("cls");
                        system("color 4");
                        cout << "\n\n\t\t*** ADT WILL NOW EXIT ***" << endl;
                        exit(0);

                default: goto menu_choice;
            }
        }

#endif // INTERFACE_H_INCLUDED
