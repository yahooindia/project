# include <stdio.h>
# include <conio.h>
# include <string.h>
# define null 0
int size=0;
void insert();
void del();
int search(char lab[]);
void display();
struct symbtab
{
          char label[10];
          int addr;
          struct symtab *next;
};
struct symbtab *first,*last;
void main()
{
          int op;
          int y;
          char la[10];

          do
          {
                   printf("\nSYMBOL TABLE IMPLEMENTATION\n");
                   printf("1. INSERT\n");
                   printf("2. DISPLAY\n");
                   printf("3. DELETE\n");
                   printf("4. SEARCH\n");
                   printf("5. END\n");
                   printf("Enter your option : ");
                   scanf("%d",&op);
                   switch(op)
                   {
                             case 1:
                             insert();
                             display();
                             break;
                             case 2:
                             display();
                             break;
                             case 3:
                             del();
                             display();
                             break;
                             case 4:
                             printf("Enter the label to be searched : ");
                             scanf("%s",la);
                             y=search(la);
                             if(y==1)
                             {
                             printf("The label is present in the symbol Table");
                             }
                             else
                             {
                             printf("The label is not found in the symbol table");
                             }
                             break;
                             case 5:
                             break;
                   }

          }
          while(op<5);
          getch();
}
void insert()
{
          int n;
          char l[10];
          printf("Enter the label : ");
          scanf("%s",l);
          n=search(l);
          if(n==1)
          {
          printf("The label already exists. Duplicate cant be inserted\n");
          }
          else
          {
                   struct symbtab *p;
                   p=malloc(sizeof(struct symbtab));
                   strcpy(p->label,l);
                   printf("Enter the address : ");
                   scanf("%d",&p->addr);
                   p->next=null;
                   if(size==0)
                   {
                             first=p;
                             last=p;
                   }
                   else
                   {
                             last->next=p;
                             last=p;
                   }
                   size++;
          }

}
void display()
{
          int i;
          struct symbtab *p;
          p=first;
          printf("LABEL\tADDRESS\n");
          for(i=0;i<size;i++)
          {
                   printf("%s\t%d\n",p->label,p->addr);
                    p=p->next;
          }

}
int search(char lab[])
{
          int i,flag=0;
          struct symbtab *p;
          p=first;
          for(i=0;i<size;i++)
          {
                   if(strcmp(p->label,lab)==0)
                   {
                             flag=1;
                   }
                   p=p->next;
          }
          return flag;
}

void del()
{
          int a;
          char l[10];
          struct symbtab *p,*q;
          p=first;
          printf("Enter the label to be deleted\n");
          scanf("%s",l);
          a=search(l);
          if(a==0)
          {
                   printf("Label not found\n");
          }
          else
          {
                   if(strcmp(first->label,l)==0)
                   {
                             first=first->next;
                   }
                   else if(strcmp(last->label,l)==0)
                   {
                             q=p->next;
                             while(strcmp(q->label,l)!=0)
                             {
                                      p=p->next;
                                      q=q->next;
                             }
                             p->next=null;
                             last=p;
                   }
                   else
                   {
                             q=p->next;
                             while(strcmp(q->label,l)!=0)
                             {
                                      p=p->next;
                                      q=q->next;
                             }
                             p->next=q->next;
                   }
                   size--;
          }
}
