#include <stdio.h>
#include <conio.h>

void unionAB(int a[10],int b[10]);
int find(int a[10],int b[10]);

void main(){
	int a[5]={1,2,3,4,5};
	int b[4]={6,7,8,9};
	int parent;
	clrscr();

	 unionAB(a,b);
	 parent=find(a,b);

	 if(parent==a[0])
		printf("Element found in set A\nRoot node = %d",parent);
	 else if(parent==b[0])
		printf("Element found in set B\nRoot node = %d",parent);
	 else
		printf("Not Found\n");

	 getch();
	 }
	 void unionAB(int a[10],int b[10])
	 {
		int i,j,k,unionAB[10];
		i=0;
		for(j=0;j<5;++j)
		{
			unionAB[i]=a[j];
			i++;

		}
		for(k=0;k<4;++k)
		{
			unionAB[i]=b[k];
			i++;
		}

		printf("A -  ");
		 for(i=0;i<5;++i)
		 {
			printf("%d ",a[i]);
		 }
		 printf("\nB -  ");
		 for(i=0;i<4;++i)
		 {
			printf("%d ",b[i]);
		 }
		printf("\nAUB -  ");
		for(i=0;i<9;++i)
		{
			printf("%d ",unionAB[i]);
		}
	  }

	 //find

	 int find(int a[10],int b[10])
	 {
		int num,i;
		printf("\nEnter the number to be searched\n");
		scanf("%d",&num);
		for(i=0;i<5;++i)
		{
			if(a[i]==num)
			{
				return a[0];
			}
		}
		for(i=0;i<4;++i)
		{
			if(b[i]==num)
			{
				return b[0];
			}

		}
		return -1;
	 }