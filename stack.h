#ifndef STACK_H
#define STACK

typedef struct Node
{
    unsigned int data;
    Node* next;
} Node;

void insertHead(Node** head, unsigned int value);
int removeHead(Node** head); 
bool isEmpty(Node* head);
void freeL(Node** head);

#endif // 
