#include<stdio.h>
#define MAX 10
void degree(int adj[][MAX],int x,int n)
{
	int i,incount=0,outcount=0;
	for(i=0;i<n;i++)
	{
		if(adj[x][i]==1)
			outcount++;
		if(adj[i][x]==1)
			incount++;
	}
	printf("\n the in degree of node%d is=%d",x,incount);
	printf("\n the out degree of node %d is=%d",x, outcount);
	printf("\n total degree of node %d is=%d", x,incount+outcount);
}
int main()
{
int adj[MAX][MAX],n,i,j;
setbuf(stdout,NULL);
printf("Enter the total no of nodes in graph");
scanf("%d", &n);
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		printf("enter edge from %d to %d,(1:edge 0:no edge) \n",i,j);
		scanf("%d",&adj[i][j]);
	}
}
for(i=0;i<n;i++)
{
		degree(adj,i,n);
}
 return 0;
}