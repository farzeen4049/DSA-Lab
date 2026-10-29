#include <stdio.h>
#define SIZE 10

int q[SIZE];
int front =0,rear=0;

void insertq(int item)
{
  if((rear+1)%SIZE==front)
  printf("Queue is full \n");
  else
  {
  rear=(rear+1)%SIZE;
  q[rear]=item;
  printf("inserted %d\n", item);
  }
  }
  void deleteq(){

if(front==rear)
printf("Queue is empty");
else
{
front=((front+1)%SIZE);
printf("Deleted %d\n",q[front]);
}
}

void searchq(int item)
{
int i=(front+1)%SIZE;
int pos=1;

while(i !=(rear+1)% SIZE)
{
if(q[i]==item)
{
printf("Found at position %d\n",pos);
return;
}

i=(i+1)%SIZE;
pos++;
}

printf("Not found \n ");
}

int main(){
int item,opt=0;

while(opt !=4)
{
printf("\n1.Insert \n");
printf("\n2.Deletion\n");
printf("\n3.Search\n");
printf("\n4.Exit \n");
printf("Option : ");
scanf("%d",&opt);

switch(opt)
{ 

 case 1:
 printf("Data : ");
 scanf("%d",&item);
 insertq(item);
 break;
 
 case 2 :
 deleteq();
 break;
 
 case 3:
 printf("Number to Search : ");
 scanf("%d",&item);
 searchq(item);
 break;
 
 case 4:
 printf("Program ended\n");
 break;
 
 default:
 printf("invalid option/n");
 }
 }
 
 return 0;
 }
 
 
 
 



