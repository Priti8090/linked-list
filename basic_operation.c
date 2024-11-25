#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *first=0,*last=0,*newnode=0;

void creat(struct node *newnode)
{
    if(last==0)
    {
        last=newnode;
        first=newnode;
    }
    else
    {
        last->next=newnode;
        last=newnode;
    }
}
void min()
{
   struct node *t;
    t=first;
  int  p=t->data;
    while(t!=0)
    {
        if(p>t->data)
        p=t->data;
        t=t->next;
    }
     
    printf("Min=%d",p);
    
}
void max()
{
   struct node *t;
    t=first;
  int  p=t->data;
    while(t!=0)
    {
        if(p<t->data)
        p=t->data;
        t=t->next;
    }
     
    printf("Max=%d",p);
    
}
void travers()
{
    struct node *p;
    p=first;
    while(p!=0)
    {
        printf(" %d->",p->data);
        p=p->next;
    }
}
void delet_at_first()
{
    struct node *p,*t;
    t=first;
    if(last==0)
    {
        printf("no element in the list!!");
        return 0;
    }
    else if(last==first)
    {
        free(t);
    }
    else
    {
    first=first->next;
    free(t);
    }
}
void delet_at_last()
{
    struct node *p,*t;
    p=first;
     if(last==0)
    {
        printf("no element in the list!!");
        return 0;
    }
    else if(last==first)
    {
        free(first);
    }
    else
    {
    while(p->next!=NULL)
    {
        t=p;
        p=p->next;
    }
    t->next=NULL;
    free(p);
    }
}
void insert_at_first()
{
     struct node *p;
     p=first;
       p=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data to insert:");
      scanf("%d",&p->data);
      p->next=0;
      if(last==0)
      last=first=p;
      else
      {
          p->next=first;
          first=p;
      }
      
}
void insert_at_between()
{
     struct node *p,*t;
    t=first;
    int a;
    printf("Enter data after which data to be insert:-\n");
    scanf("%d",&a);
    while(t!=0 && a!=t->data)
    {
        t=t->next;
    }
    if(t==0)
    printf("Data is not found in the list !!\n");
    else
    {
         p=(struct node*)malloc(sizeof(struct node));
         printf("Enter data to insert:-\n");
         scanf("%d",&p->data);
         p->next=t->next;
         t->next=p;
    }
    
}
void insert_at_last()
{
    struct node *newnode;
    printf("Enter the data to insert:");
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(last==0)
    first=last=newnode;
    else
    {
        last->next=newnode;
        last=newnode;
    }
}
void search()
{
     struct node *p,*t;
    p=t=first;
    int m,k=0;
    printf("Enter data to be search:-\n");
    scanf("%d",&m);
    if(last==0)
    printf("There are no node !!");
    else
    {
    while(p!=0 && m!=p->data)
    {
        k++;
        p=p->next;
    }
    printf("Searching is successfully done !!\n");
    if(p==0)
    printf("Searched data not found in the list !!");
    else
    {
        printf("Searched data is found at *_ %dth_* position:",k+1);
    }
  }
    
}
void delet_at_between()
{
    struct node *p,*t;
    p=t=first;
    printf("\n\nEnter data after which you want to deleted data:- ");
    int j;
    scanf("%d",&j);
    if(p==0)
    {
        printf("there are no node ");
    }
    else if(j==first)
    delet_at_first();
    else
    {
        while(j!=p->data)
    {
        p=p->next;
    }
    t=p->next;
    p->next=t->next;
    free(t);
    }
}
void main_menu()
{
    printf("\n\n     ************************************************************************************\n");
    printf("     *****************WELCOME TO LINKED LIST WORLD **************************************\n");
    printf("     ************************************************************************************\n\n");
    printf("    Enter 1 for creat a node:\n");
    printf("    Enter 2 for traverse:\n");
    printf("    Enter 3 for delete at first:\n");
    printf("    Enter 4 for delete at last:\n");
    printf("    Enter 5 for delete at between node:\n");
    printf("    Enter 6 for insert at last:\n ");
    printf("   Enter 7 for insert at first:\n");
    printf("    Enter 8 for insert data at between:\n");
    printf("    Enter 9 for find max term:\n");
    printf("    Enter 10 for find min term:\n");
    printf("    Enter 11 for search any data:\n");
    printf("    Enter 12 for Exit:\n");
    printf("                                                     **** MADE BY PRITI ****\n");
    
}
int main()
{
    int n;
    while(1)
    {
    main_menu();
    scanf("%d",&n);
switch(n)
{
    case 1:{
                  printf("Enter data for creat node:\n");
                    printf("Enter 0 for Exit:\n");

    while(1)
    {
     struct node *newnode=(struct node*)malloc(sizeof(struct node));
     scanf("%d",&newnode->data);
     newnode->next=NULL;
      if(newnode->data==NULL)
     break;
     creat(newnode);
    
    }
            }
            break;
            case 2: travers();
            break;
            case 3: delet_at_first();
            break;
            case 4: delet_at_last();
            break;
            case 5: delet_at_between();
            break;
            case 6:insert_at_last();
            break;
            case 7:insert_at_first();
            break;
           case 8:insert_at_between();
           break;
           case 9:max();
           break;
            case 10:min();
           break;
            case 11:search();
           break;
           case 12:return 0;
    }
 }
    return 0;
}

