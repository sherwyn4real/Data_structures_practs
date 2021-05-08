#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define initial 1
#define waiting 2
#define visited 3
#define DFSvisited 4
int n;
int adj[MAX][MAX];
int state[MAX];
void create_graph();
void BF_traversal();
void BFS(int v);
void DF_traversal();
void DFS(int v);
int queue[MAX], front=-1, rear=-1;
int stack[MAX], top=-1;
void insert(int vertex);
int del();
int isEmpty_queue();
void push(int vertex);
int pop();
int isEmpty_stack();

int main()
{
	create_graph();
	BF_traversal();
	DF_traversal();
}

void create_graph()
{
	int max_edges,i,j,origin,destin;
	printf("Enter the no of vertices: ");
	scanf("%d",&n);
	max_edges=n*(n-1);
	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edge %d (-1 -1 to quit):  ",i);
		scanf("%d %d",&origin,&destin);
		if(origin==-1 && destin==-1)
			break;
		if(origin>=n || destin>=n || origin<0 || destin<0)
		{
			printf("Invalid vertex\n");
			i--;	
		}
		else
		{
			adj[origin][destin]=1;
		}
	}	
	printf("\n");	
}

void BF_traversal()
{
	int v;
	for(v=0;v<n;v++)
		state[v]=initial;
	printf("Enter starting vertex for BF traversal: ");
	scanf("%d",&v);
	printf("BFS traversal is: \n");
	BFS(v);
	for(v=0;v<n;v++)
		if(state[v]==initial)
			BFS(v);	
}
void BFS(int v)
{
	int i;
	insert(v);
	state[v]=waiting;
	while(!isEmpty_queue())
	{
		v=del();
		printf("%d  ",v);
		state[v]=visited;
		for(i=0;i<n;i++)
		{
			if(adj[v][i]==1 && state[i]==initial)
			{
				insert(i);
				state[i]=waiting;
			}
		}
	}
	printf("\n");
}

void insert(int vertex)
{
	if(rear==MAX-1)
		printf("Queue overflow\n");
	else
	{
		if(front==-1)
			front=0;
		rear=rear+1;
		queue[rear]=vertex;		
	}	
}

int del()
{
	int item;
	if(front==-1 || front>rear)
	{
		printf("Queue underflow\n");
		return;
	}
	item=queue[front];
	front=front+1;
	return item;
}
int isEmpty_queue()
{
	if(front==-1 || front>rear)
		return 1;
	else
		return 0;
}

void DF_traversal()
{
	int v;
	for(v=0;v<n;v++)
		state[v]=initial;
	printf("enter starting vertex for DF traversal: ");
	scanf("%d",&v);
	printf("DFS traversal is: \n");
	DFS(v);
	for(v=0;v<n;v++)
	{
		if(state[v]==initial)
			DFS(v);	
	}
}

void DFS(int v)
{
	int i;
	push(v);
	while(!isEmpty_stack())
	{
		v=pop();
		if(state[v]==initial)
		{
			printf("%d  ",v);
			state[v]= DFSvisited;
		}
		for(i=n-1;i>=0;i--)
		{
			if(adj[v][i]==1 && state[i]==initial)
				push(i);
		}
	}
}

void push(int v)
{
	if(top==MAX-1)
		printf("Stack overflow\n");
	else
	{
		top=top+1;
		stack[top]=v;	
	}	
}

int pop()
{
	int v;
	if(top==-1)
	{
		printf("stack underflow\n");
		return;
	}
	v=stack[top];
	top=top-1;
	return v;
}
int isEmpty_stack()
{
	if(top==-1)
		return 1;
	else
		return 0;	
}
