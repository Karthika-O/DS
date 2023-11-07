#include<stdio.h>
#include<conio.h>
int LinearSearch(int a[],int n,int x)
{
 int i;
 for(i=0;i<n;i++)
 {
 if(a[i]==x)
  {
   return i;
   }
 }
 return -1;
 }
 int BinarySearch(int a[],int n,int x)
 {
  int temp,low=0,high=n-1,mid,i,j;
  for(i=0;i<n;i++)
  {
   for(j=i+1;j<n;j++)
   {
   if(a[i]>a[j])
   {
   temp=a[i];
   a[i]=a[j];
   a[j]=temp;
   }
   }
   }
  while(low<=high)
  {
    mid=(low+high)/2;
    if(a[mid]==x)
	 return mid;
    else if(a[mid]<x)
	 low=mid+1;
    else
	 high=mid-1;
  }
  return -1;
 }
 void display(int a[],int n)
 {
   int i;
    for(i=0;i<n;i++)
     {
      printf("\t%d",a[i]);
     }
     getch();
 }
 int main()
 {
 int n,a[100],i,x,linearResult=0,binaryResult=0,choice;
 printf("\nEnter the size of the Array ");
 scanf("%d",&n);
 printf("Enter the elements in the array ");
 for(i=0;i<n;i++)
 {
 scanf("%d",&a[i]);
 }
 printf("MENU\n1.LINEAR SEARCH\n2.BINARY SEARCH\n3.Display\n4.Exit\n");
 do
 {
 printf("\nEnter your choice ");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
       printf("Enter the element to search ");
       scanf("%d",&x);
       linearResult=LinearSearch(a,n,x);
       printf("Performing Linear Search\n");
       if(linearResult!=-1)
	    printf("Element %d found at index %d",x,linearResult);
       else
	    printf("Element not found");
       break;

 case 2:
       printf("Enter the element to search ");
       scanf("%d",&x);
       binaryResult=BinarySearch(a,n,x);
       printf("Performing Binary Search\n");
       if(binaryResult!=-1)
	    printf("Element %d found at index %d",x,binaryResult);
       else
	    printf("Element not found");
       break;
 case 3:
       display(a,n);
       break;
 case 4:
	exit(0);
 default:
      {
      printf("Invalid choice");
      }
 }
 getch();
 }while(1);
 return 0;
 }