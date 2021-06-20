#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
typedef struct Heap
{ int data;
struct Heap *next;
}node;
node *create();
void main()
{
int choice,val,a;
node *head;
void display(node *);
node *search(node *,int);
node *insert(node *);
void dele(node **);
head=NULL;
do
{
printf("\n ----------------------------------------------------------------------------------");
printf("\n *****Program to perform various operations on heap *******");
printf("\n ----------------------------------------------------------------------------------");
printf("\n1.Create");
printf("\n2.Display");
printf("\n3.Insert an element in a list");
printf("\n4.Delete an element from list");
printf("\n5.Quit");
printf("\nEnter Your Choice(1-5):- ");
scanf("%d",&choice);
switch(choice)
{ case 1:head=create();
break;
case 2:display(head);
break;
case 3:head=insert(head);
break;
case 4:dele(&head);
break;
case 5:exit(0);
default:
printf("Invalid Choice,Try again !!!");
}}
while(choice!=5);
}
node *create()
{
node *temp,*new1,*head;
int val,flag,a;
node *get_node();
temp=NULL;
flag=TRUE;
do
{
printf("\nEnter the Element:- ");
scanf("%d",&val);

new1=get_node();
if(new1==NULL)
printf("\nMemory is not allocated");
new1-> data=val;
if (flag==TRUE)/* Executed only for the first time*/
{
head=new1;
temp=head;
flag=FALSE;
} else
{

temp->next=new1;
temp=new1;
}
printf("\nDo you want to enter more elements?(1 for Yes/0 for No):-");
scanf("%d",&a);
}while(a==1);
printf("\nThe list is created");
return head;
}
node *get_node()
{
node *temp;
temp=(node*)malloc(sizeof(node));
//using the mem. Allocation function
temp->next=NULL;
return temp;
}
void display(node*head)
{
node *temp;
temp=head;
if(temp==NULL)
{
printf("\nThe list is empty\n");
return;
}
while(temp!= NULL)
{
printf("%d->",temp-> data);
temp=temp->next;
}
printf("NULL");
}
node *search(node *head,int key)
{
node *temp;
int found;
temp=head;
if (temp==NULL)
{
printf("The list is empty\n");
return NULL;
}
found=FALSE;
while((temp!=NULL)&&(found==FALSE))
{ if(temp->data != key)
temp = temp->next;
else
found = TRUE;
} if(found == TRUE)
{
printf("\nThe Elements is present in the list\n");
return temp;
} else
printf("\nThe Element is not present in the list\n");
return NULL;
}
node *insert(node *head)
{ int choice;
node insert_head(node);
void insert_after(node*);
void insert_last(node*);
printf("\n1.Insert a node as a head node");
printf("\n2.Insert a node as a last node");
printf("\n3.Insert a node as at the intermediate position in the list ");
printf("\nEnter your choice for insertion of node ");
scanf("%d",&choice);
switch(choice)
{ case 1:head =
insert_head(head);
break;
case 2:insert_last(head);
break;
case 3:insert_after (head);
break;
}
return head;
}

node *insert_head(node*head)
{
node *New,*temp;
New = get_node();
printf ("\nEnter the element which you want to insert :-");
scanf("%d",&New->data);
if(head == NULL)
head = New;
else
{ temp=head;
New->next = temp;
head= New;
}
return head;
}

void insert_last(node *head)
{
node *New,*temp;
New = get_node();
printf ("\nEnter the element which you want to insert :-");
scanf("%d",&New->data);
if(head == NULL)
{
head = New;
} else
{ temp=head;
while(temp->next!=NULL)
temp=temp->next;
temp->next=New;
New->next=NULL;
}}
void insert_after(node *head)
{ int key;
node *New,*temp;
New = get_node();
printf("\nEnter the element after which you want to insert :- ");
scanf("%d",&key);
temp=head;
do
{ if(temp->data==key)
{
printf ("\nEnter element which you want to insert:- ");
scanf("%d",&New->data);
New->next=temp->next;
temp->next=New;
return;
} else
temp=temp->next;
}while(temp!=NULL);
}
node *get_prev(node *head,int val)
{
node *temp,*prev;
int flag;
temp = head;
if(temp == NULL)
return NULL;
flag = FALSE;
prev = NULL;
while(temp!=NULL && !flag)
{ if(temp->data!=val)
{
prev = temp;
temp = temp->next;
} else
flag = TRUE;
} if(flag)

return prev;
else
return NULL;
}
void dele(node **head)
{ int key;
node *New,*temp, *prev;
temp=*head;
if (temp== NULL)
{
printf ("\nThe list is empty\n ");
return;
}
printf("\nENTER the Element you want to delete:-");
scanf("%d",&key);
temp= search(*head,key);
if(temp !=NULL)
{
prev = get_prev(*head,key);
if(prev != NULL)
{
prev ->next = temp-> next;
free(temp);
} else
{
*head = temp->next;
free(temp); // using the mem. Dellocation function
}
printf("\nThe Element is deleted\n");
}}
