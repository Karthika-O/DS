#include<stdio.h>
#include<conio.h>
#define n 10
void main()
{
   int i,j,k,t,nu,na,nb;
   int u[100],a[100],b[100];
   int bit_u[n],bit_a[n],bit_b[n],union_set[n],intersect_set[n],differ_a[n];
   clrscr();
   printf("Enter the size of Universal array");
   scanf("%d",&nu);
   printf("Enter elements of universal set");
   for(i=0;i<nu;i++)
   {
     scanf("%d",&u[i]);
   }
   printf("Enter the size of Set A");
   scanf("%d",&na);
   printf("Enter elements of Set A");
   for(i=0;i<na;i++)
   {
     scanf("%d",&a[i]);
   }
   printf("Enter the size of Set B");
   scanf("%d",&nb);
   printf("Enter elements of Set B");
   for(i=0;i<nb;i++)
   {
     scanf("%d",&b[i]);
   }
   for(i=0;i<n;i++)
   {
      if(u[i]!=-1)
      {
	bit_u[i]=1;
      }
   }
   printf("\n Bit Representation of Universal set \n");
   for(i=0;i<n;i++)
   {
    printf("%d\t",bit_u[i]);
   }
   printf("\n");
   for(i=0;i<n;i++)
   {
     t=0;
     for(j=0;j<n;j++)
     {
       if(a[j]==u[i])
       {
       t=1;
       break;
       }
     }
     if(t==1)
     {
       bit_a[i]=1;
     }
     else
     {
       bit_a[i]=0;
     }
   }
   printf("The bit representation of set A \n");
   for(i=0;i<n;i++)
   {
   printf("%d\t",bit_a[i]);
   }
   printf("\n");

   for(i=0;i<n;i++)
   {
      t=0;
      for(j=0;j<n;j++)
     {
       if(b[j]==u[i])
       {
       t=1;
       break;
       }
     }
     if(t==1)
     {
       bit_b[i]=1;
     }
     else
     {
       bit_b[i]=0;
     }
   }
   printf("The bit representation of set B \n");
   for(i=0;i<n;i++)
   {
   printf("%d\t",bit_b[i]);
   }
   printf("\n");

   for(i=0;i<n;i++)
   {
   if(bit_a[i]==1 || bit_b[i]==1)
   {
   union_set[i]=1;
   }
   else
   {
   union_set[i]=0;
   }
   }
   printf("\n Set of A Union B is \n");
   for(i=0;i<n;i++)
   {
     printf("%d\t",union_set[i]);
   }
   printf("\n");

   for(i=0;i<n;i++)
   {
   if(bit_a[i]==1 && bit_b[i]==1)
   {
   intersect_set[i]=1;
   }
   else
   {
   intersect_set[i]=0;
   }
   }
   printf("\n Set of A intersect B is \n");
   for(i=0;i<n;i++)
   {
     printf("%d\t",intersect_set[i]);
   }
   printf("\n");

   for(i=0;i<n;i++)
   {
   if(bit_a[i]==1 && bit_b[i]==0)
   {
   differ_a[i]=1;
   }
   else
   {
   differ_a[i]=0;
   }
   }
   printf("\n Set of A - B is \n");
   for(i=0;i<n;i++)
   {
     printf("%d\t",differ_a[i]);
   }
   printf("\n");
getch();
}
