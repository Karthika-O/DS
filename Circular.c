// program to implement circular queue
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
int data[MAX];
int front=-1,rear=-1;
void insert()
{
    if((rear+1)%MAX==front)
       {
          printf("overflow");
       }
    else
         {
            rear=(rear+1)%MAX;
            printf("Enter the data ");
           scanf("%d",&data[rear]);
            if(front==-1)
                   front=0;        
         }
         getch();
}
void delet()
{
    if(front==-1)
           printf("underflow");
    else
    {
          printf("Deleted element is %d ",data[front]);
          if(front==rear)
                {
                  front=-1;
                  rear=-1;
                }
          else
               front=(front+1)%MAX;
    }
    getch();
}
void display()
{
	int i;
    if(front==-1)
           printf("underflow");
    else
    {
        if(front<=rear)
        {
        printf("Elements are ");
        for(i=front;i<=rear;i++)
                    printf("%d\t",data[i]);
        }
        else
        {
        	printf("Elements are ");
            for(i=front;i<=MAX+rear;i++)
                    printf(" %d\t",data[i%MAX]);
        }
    }
    getch();
}
void main()
 {
     int ch;
     do
     {
         printf("\nEnter your choice \n 1.Insert \n 2.Delete \n 3.Display \n 4.Exit \n");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1:
                    insert();
                    break;
             case 2:
                    delet();
                    break;
              case 3:
                     display();
                     break;
              case 4:
                     exit(0);
               default:
                     {
                         printf("Invalid choice");
                         getch();
                     }
         }
     }while(1);
 }
