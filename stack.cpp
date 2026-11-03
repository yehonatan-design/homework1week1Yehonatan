#include "stack.h"
#include <iostream>

// a function to insert a new node at the head of the list
//input: head - pointer to the head of the list, value - value to be inserted
//output: none
void insertHead(Node** head, int value)
{
    Node* newNode = new Node(); 
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

//a fumction to remove the head of the list and return its value
//input: head - pointer to the head of the list
//output: value of the removed node, or -1 if the list is empty
int removeHead(Node** head)
{
    if (isEmpty(*head)) 
    {
        return -1; 
    }

    Node* temp = *head;        
    int value = temp->data;
    *head = (*head)->next;
    delete temp;
    return (int)value;
}

//a fumction to check if the list is empty
//input: head - pointer to the head of the list
//output:  if the list is empty- true, else false
bool isEmpty(Node* head)
{
    return head == NULL;
}

//a  fumction to free the entire list
//input: head - pointer to the head of the list
//output: none
void freeL(Node** head)
{
    while (!isEmpty(*head))
    {
        removeHead(head);
    }
}