#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct List
{
    struct Node *head;
};
struct Node *create()
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the Data: ");
    scanf("%d", &t->data);
    t->next = NULL;
    return t;
}
void push(struct List *list)
{
    struct Node *te = create();
    if (list->head == NULL)
    {
        list->head = te;
    }
    else
    {
        struct Node *q = list->head;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = te;
    }
}

void pop(struct List *list)
{
    if (list->head == NULL)
    {
        printf("EMPTY LIST");
    }
    else if (list->head->next == NULL)
    {
        struct Node *t = list->head;
        printf("Deleted Element: %d", t->data);
        list->head = NULL;
        free(t);
    }
    else
    {
    	struct Node *t=list->head->next;
    	struct Node *p=list->head;
    	 while(t->next!=NULL)
    	  {
    	  	p=t;
    	  	t=t->next;
    	  }
    	  p->next=NULL;
    	  printf("Deleted element is  %d: ",t->data);
    	  free(t);
    }
    getch();
}
void display(struct List* list)
{
    if(list->head == NULL)
    {
        printf("Empty List");
    }
    else
    {
        struct Node* p = list->head;
        while(p != NULL)
        {
            printf("\t%d", p->data);
            p = p->next;
        }
    }
    getch();
}
int main()
{ 
    struct List *head=NULL;
    int ch;
    do
    {
     printf("\nEnter your choice \n1 Push \n2 Pop  \n3 Display \n4 Exit \n");
        scanf("%d",&ch);
        switch(ch)
        {
             case 1:
                     push(head);
                     break;
             case 2:
                     pop(head);
                     break;
             case 3:
                     display(head);
                     getch();
                     break;
             case 4:
                     exit (0);
             default:
                {
                   printf("Invalid choice");
                   getch();
                } 
        }   
    }while(1);
}