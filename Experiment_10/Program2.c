#include<stdio.h>
#include<stdlib.h>
#define size 7

struct n
{
    int d;
    struct n *next;
};

struct n *chain[size];

void init()
{
    int i;
    for(i = 0; i < size; i++)
    chain[i] = NULL;
}

void remove_key(int key)
{
    int index=key%size;
    struct n *temp=chain[index],*point;
    if(chain[index]->d==key)
    chain[index]=NULL;
    else
    {
        while(temp->next!=NULL)
        {
            if(temp->next->d==key)
            {
                point=temp->next;
                temp->next=point->next;
                free(point);
            }
            temp=temp->next;
        }
    }
}
void insert(int value)
{
    struct n *newNode =(struct n*)malloc(sizeof(struct n));
    newNode->d = value;
    newNode->next = NULL;
    int key = value % size;
    if(chain[key] == NULL)
    chain[key] = newNode;
    else
    {
        struct n *temp = chain[key];
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void search(int x)
{
    
    int i,flag=0;
    for(i = 0; i < size; i++)
    {
        struct n *temp = chain[i];
        while(temp)
        {
            if(temp->d==x)
            {
                flag=1;
                break;
            }
            temp = temp->next;
        }
        if(flag)
        break;
    }
    if(flag)
    printf("Element exists\n");
    else
    printf("Element does not exist\n");
}

void print()
{
    int i;
    for(i = 0; i < size; i++)
    {
        struct n *temp = chain[i];
        printf("chain[%d]-->",i);
        while(temp)
        {
            printf("%d -->",temp->d);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    init();
    int op,x;
    do
    {
      printf("1.Insert \n2.Delete \n3.Search \n4.Display \n0.Exit \nEnter your option: ");
      scanf("%d",&op);
      switch(op)
      {
         case 0:
         break;
         case 1:
         printf("Enter the element you want to insert\n");
         scanf("%d",&x);
         insert(x);
         break;
         case 2:
         printf("Enter the element you want to delete\n");
         scanf("%d",&x);
         remove_key(x);
         break;
         case 3:
         printf("Enter the element you want to search\n");
         scanf("%d",&x);
         search(x);
         break;
         case 4:
         print();
         break;
         default:printf("Invalid input re enter\n");
         break;
      }
    }
	while(op!=0);  
    return 0;
}
