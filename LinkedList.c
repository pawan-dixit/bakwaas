#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int data;
  struct Node* next;
};
void insertAtBeginning(struct Node **ref,int x)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    if ( *ref == NULL)
    {
        *ref = newNode;
        newNode->next = NULL;
        return;
    }
    newNode->next = *ref;
    *ref = newNode;
}
void insertAtEnd(struct Node **ref,int x)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *ref;
    newNode->data = x;
    if ( *ref == NULL)
    {
        *ref = temp;
        newNode->next = NULL;
        return;
    }
    while ( temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
}
void insertAfter(struct Node** ref,int y,int x)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *ref;
    if ( *ref == NULL )
    {
        return;
    }
    for(int i=1;i<y;i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->data = x;
}
void Print(struct Node **ref)
{
    struct Node* temp = *ref;
    if ( temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    struct Node* head = NULL;
    insertAtBeginning(&head,5);
    insertAtEnd(&head,8);
    insertAtEnd(&head,20);
    insertAtBeginning(&head,4);
    insertAfter(&head,2,10);
    Print(&head);
    return 0;
}
