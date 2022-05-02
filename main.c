#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *next;
    int data;

};

int main(){
    struct Node *head=(struct Node*) malloc (sizeof(struct Node));
    for (int i = 0; i < 10; i++)
    {
        head->next=(struct Node*) malloc (sizeof(struct Node));
        head->data=i;
        printf("\n%d",head->data);
        head=head->next;
    }
    
}