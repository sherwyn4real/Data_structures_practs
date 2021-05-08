
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int adj[MAX][MAX];
int n;
void create_graph();
void display();
void insert_vertex(int x);
void del_vertex(int x);
void insert_edge(int origin,int destin);
void del_edge(int origin,int destin);

int main()
{
	int choice,origin,destin,x;
	create_graph();
	printf("\n");
	while(1)
	{
		printf("1:insert vertex\n");
		printf("2:insert edge\n");
		printf("3:delete vertex\n");
		printf("4:delete edge\n");
		printf("5:display\n");
		printf("6:Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter the vertex to be inserted: ");
				scanf("%d",&x);
				insert_vertex(x);
				printf("\n");
				break;
			case 2:
				printf("Enter an edge to be inserted: ");
				scanf("%d %d",&origin,&destin);
				insert_edge(origin,destin);
				printf("\n");
				break;
			case 3:
				printf("Enter the vertex to be deleted: ");
				scanf("%d",&x);
				del_vertex(x);
				printf("\n");
				break;
			case 4:
				printf("Enter an edge to be deleted: ");
				scanf("%d %d",&origin,&destin);
				del_edge(origin,destin);
				printf("\n");	
				break;
			case 5:
				display();
				printf("\n");
				break;
			case 6:
				exit(1);
			default:
				printf("wrong choice\n");
				break;					
		}
	}
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
}

void insert_edge(int origin,int destin)
{
	if(origin<0 || origin>=n)
	{
		printf("origin vertex does not exist\n");
		return;
	}
	if(destin<0 || destin>=n)
	{
		printf("destin vertex does not exist\n");
		return;
	}
	adj[origin][destin]=1;
}

void del_edge(int origin,int destin)
{
	if(origin>=n || destin>=n || origin<0 || destin<0 || adj[origin][destin]==0)
	{
		printf("Edge does not exist\n");
		return;	
	}	
	adj[origin][destin]=0;
}

void display()
{
	int i,j;
	for(i=0;i<n; i++)
	{
		for(j=0;j<n;j++)
			printf("%d  ",adj[i][j]);
		printf("\n");	
	}
}

void insert_vertex(int x)
{
	n++;
	int i;
	for(i=0;i<n;i++)
	{
		adj[i][n-1]=0;
		adj[n-1][i]=0;
	}
}

void del_vertex(int x)
{
	int i;
	if(x>n)
	{
		printf("Vertex not present\n");
		return;
	}
	while(x<n)
	{
		for(i=0;i<n;++i)
		{
			adj[i][x]=adj[i][x+1];
		}
		for(i=0;i<n;++i)
		{
			adj[x][i]=adj[x+1][i];
		}
		n--;
	}
	
}
