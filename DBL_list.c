#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
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
    t->prev = NULL;
    return t;
}
void insertB(struct List *list)
{
    struct Node *t = create();
    if(list->head==NULL)
     {
     	list->head=t;
     }
     else
     {
        t->next = list->head;
        list->head->prev=t;
        list->head = t;
     }
}
void insertE(struct List *list)
{
        struct Node *t = create();
        if(list->head==NULL)
         {
         	list->head=t;
         }
         else
         {
         	 struct Node *p= list->head;
         	 while(p->next!=NULL)
         	 {
         	 	p=p->next;
         	 }
         	 p->next=t;
         	 t->prev=p;
         }
}
void deleteB(struct List *list)
{
	struct Node *p=list->head;
	if(list->head==NULL)
	{
		printf("List is Empty \n");
		return;
	}
	list->head=list->head->next;
	if(list->head!=NULL)
	{
		list->head->prev=NULL;		
	}
	printf("%d is deleted ",p->data);
	free(p);	   
}
void deleteE(struct List *list)
{
	struct Node *p= list->head;
	if(list->head==NULL)
	{
		printf("List is Empty \n");
		return;
	}
	if(list->head->next==NULL)
	{
		printf("%d is deleted ",list->head->data);
		free(list->head);
		list->head=NULL;
		return;
	}
         	 while(p->next!=NULL)
         	 {
         	 	p=p->next;
         	 }
         	 printf("%d is deleted ",list->head->data);
         	 p->prev->next=NULL;
         	 free(p);
}
void display(struct List *list)
{
	struct Node *p= list->head;
	if(list->head==NULL)
	{
		printf("List is Empty \n");
	}	
         	 while(p!=NULL)
         	 {
         	 	printf("%d -> ", p->data);
         	 	p=p->next;
         	 }
         	 
}
int main()
{ 
    struct List *head=NULL;
    int ch;
    do
    {
     printf("\nEnter your choice \n 1 InsertB \n 2 DeleteB \n 3 InsertE \n 4 DeleteE \n 5 Display \n 6 Exit \n");
        scanf("%d",&ch);
        switch(ch)
        {
             case 1:
                     insertB(head);
                     break;
             case 2:
                     deleteB(head);
                     break;
             case 3:
                     insertE(head);
                     break;
             case 4:
                     deleteE(head);
                     break;
             case 5:
                     display(head);
                     getch();
                     break;
             case 6:
                     exit (0);
             default:
                {
                   printf("Invalid choice");
                   getch();
                } 
        }   
    }while(1);
}