#include<stdio.h>
#include<stdlib.h>

#define MAX 100
int adj[MAX][MAX];
int n, graph_type,max_e;
unsigned int e=0;

void insert_edge(int,int);
void del_edge(int,int);
void display();

int main()
{
	int origin,destin,i,j,c;
	start:
	printf("Select the type of graph\n");
	printf("1.Undirected	2.Directed\n");
	scanf("%d",&graph_type);
	printf("\n\n");
	if(graph_type == 1 || graph_type == 2)
		{
			
		
			printf("Enter number of vertices\n");
			scanf("%d",&n);
			
			if(graph_type ==1)
				max_e=n*(n-1)/2;
				
			else
				max_e=n*(n-1);
			
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					adj[i][j]=0;
			printf("\n\n");
				
			do
			{
				printf("1.Insert an Edge\n");
				printf("2.Delete an Edge\n");
				printf("3.Display\n");
				printf("0.Exit\n");
				printf("Enter your choice : ");
				scanf("%d",&c);
				switch(c)
				{
					case 1:
					printf("Enter an Edge to be inserted : ");
					scanf("%d %d",&origin,&destin);
					insert_edge(origin,destin);
					break;
				
					case 2:
					printf("Enter an edge to be deleted : ");
					scanf("%d %d",&origin,&destin);
					del_edge(origin,destin);
					break;
					
					case 3:
					display();
					break;
					
					default: if(c)
							printf("Wrong choice\n");
							else
							break;
					}
			}while(c!=0);
			
		}
	else
	{
		printf("Invalid.Please select the right option\n\n");
			goto start;
		}
}

void insert_edge(int o, int d)
{
	if(e>max_e)
		{
			printf("Edges maxed out\n\n");
		return;
	}
		
	if(o<0 || o>=n)
		{
			printf("origin vertex doesnt exist\n\n");
			return;
		}
		
	if(d<0 || d>=n)
		{
			printf("Destination vertex doesnt exist\n\n");
			return;
		}
	
	adj[o][d]=1;
	
	if(graph_type==1)
		{
		adj[d][o]=1;
		e++;
	}
	printf("Edge inserted successfully\n\n");
	e++;
}

void del_edge(int o, int d)
{
	if(o<0 || o>=n)
		{
			printf("origin vertex doesnt exist\n");
			return;
		}
		
	if(d<0 || d>=n)
		{
			printf("Destination vertex doesnt exist\n");
			return;
		}
	
	adj[o][d]=0;
	
	if(graph_type==1)
		{
			adj[d][o]=0;
			e--;
		}
		
	printf("Edge deleted successfully\n\n");
	e--;
}
	
void display()
{
	int i,j;
	
	for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
			printf("%d ",adj[i][j]);
	printf("\n");
	}
	
printf("\n\n\n");
}
		
	
