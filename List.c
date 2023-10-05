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

void insertB(struct List *list)
{
    struct Node *temp = create();
    temp->next = list->head;
    list->head = temp;
}

void deleteB(struct List *list)
{
    if (list->head == NULL)
    {
        printf("Empty List");
    }
    else
    {
        struct Node *p = list->head;
        printf("Deleted element is %d", p->data);
        list->head = list->head->next;
        free(p);
    }
}

void insertE(struct List *list)
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

void deleteE(struct List *list)
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
void deleteC(struct List *list)
           {
               int ele;
                if(list->head==NULL)
                   {
                    printf("Empty list");
                    getch();
                   }
                 else
                     {
                         printf("Enter the data to be deleted ");                         
                         scanf("%d",&ele);
                       if(list->head->data==ele)
                         {
                              struct Node *t=list->head;
                              list->head=list->head->next;
                              free(t);
                         }
                       else
                        {
                         struct  Node *t=list->head->next;
                        struct  Node *p=list->head;
                           while(t!=NULL)
                             {
                                  if(t->data==ele)
                                      {    
                                        p->next=t->next;
                                        free(t);
                                        break;
                                      }
                              p=t;
                              t=t->next;
                             }    
                         if(t==NULL)
                            {
                             printf("%d IS NOT PRESENT",ele);         
                             getch();
                            }
                        }
                    }
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
     printf("\nEnter your choice \n 1 InsertB \n 2 DeleteB \n 3 InsertE \n 4 DeleteE \n 5 DeleteC \n 6 Display \n 7 Exit \n");
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
                     deleteC(head);
                     break;
             case 6:
                     display(head);
                     getch();
                     break;
             case 7:
                     exit (0);
             default:
                {
                   printf("Invalid choice");
                   getch();
                } 
        }   
    }while(1);
}