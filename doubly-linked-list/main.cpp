//
//  main.cpp
//  doubly-linked-list
//
//  Created by Yash Adukia on 3/19/16.
//  Copyright © 2016 Yash Adukia. All rights reserved.
//



#include <iostream>
using namespace std;
# define NEWLINE '\n'

void display();
void insertAtBeginning(int data);
void insertAtAnyPosition(int pos, int data);
void insertAtEnd(int data);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    insertAtBeginning(8);
    insertAtBeginning(6);
    insertAtBeginning(5);
    insertAtAnyPosition(3, 7);
    display();
    return 0;
}


struct Node
{
    int data;
    Node *prev;
    Node *next;
} *head = NULL;

void display()
{
    if (head == NULL)
    {
        cout<<"Linked List is empty"<<NEWLINE;
    }
    else
    {
        Node *temp = new Node();
        temp = head;
        
        cout<<"Printing in straight order"<<NEWLINE;
        
        while (temp->next != NULL)
        {
            cout<<temp->data<<"-->";
            temp = temp->next;
        }
        cout<<temp->data<<NEWLINE;
        
        
        cout<<"Printing in reverse order"<<NEWLINE;
        
        while (temp->prev != NULL)
        {
            cout<<temp->data<<"-->";
            temp = temp->prev;
        }
        cout<<temp->data<<NEWLINE;
    }
}



void insertAtBeginning(int data)
{
    cout<<"Inserting data at beginning"<<NEWLINE;
    
    Node *temp = new Node();
//    head = temp;
    
    if (head == NULL)
    {
        head = temp;
        head->prev = NULL;
        head->data = data;
        head->next = NULL;
    }
    else
    {
        temp->prev = NULL;
        temp->data = data;
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtEnd(int data)
{
    
}

void insertAtAnyPosition(int pos, int data)
{
    Node *temp = new Node();
    Node *prevTemp = new Node();
    Node *newNode = new Node();
    temp = head;
    int count = 1;
    
    if (head == NULL || pos == 1 || pos == 0)
    {
        cout<<"sending to beginning...."<<NEWLINE;
        insertAtBeginning(data);
    }
    else
    {
//        temp = head;
        while (count < pos)
        {
            if (temp->next == NULL)
            {
                if (pos > count+1)
                {
                    cout<<"Invalid Position"<<NEWLINE;
                    break;
                }
                else
                {
                    cout<<"This is the end of the list"<<NEWLINE;
                    insertAtEnd(data);
                    break;
                }
            }
            else
            {
                prevTemp = temp;
                temp = temp->next;
                count++;
            }
        }
        prevTemp->next = newNode;
        newNode->prev = prevTemp;
        newNode->data = data;
        newNode->next = temp;
        temp->prev = newNode;
    }
}
