#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int vert = 3, i, j;
int arr[10][10];

struct node
{
	int data;
	struct node *next;
} *h[10], *temp, *ptr;

void Accept();
void Display();
// void Degree();
void Adjacency_List();
void Display_List();
struct node *getnode(int);
struct node *findlast(struct node *h);

int main()
{
	int ch;
	printf("\nMenu");
	printf("\n1.Accept");
	printf("\n2.Display");
	printf("\n3.Convert To Adjacency List");
	printf("\n4.Dispaly graph in adjacency list form");
	printf("\n5.Exit");
	while (1)
	{
		printf("\nEnter your choice");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			Accept();
			break;
		case 2:
			Display();
			break;
		case 3:
			Adjacency_List();
			break;
		case 4:
			Display_List();
			break;
		case 5:
			exit(0);
		}
	}
}

void Accept()
{
	int num;
	printf("\nEnter No. of Vertices: ");
	scanf("%d", &vert);

	for (i = 0; i < vert; i++)
	{
		for (j = 0; j < vert; j++)
		{
			printf("\nEnter value for a[%d][%d]", i, j);
			scanf("%d", &arr[i][j]);
		}
	}
}

void Display()
{
	printf("\nTwo dimensional array\n");
	for (i = 0; i < vert; i++)
	{
		printf("\tV%d", i);
	}

	for (i = 0; i < vert; i++)
	{
		printf("\nV%d\t", i);
		for (j = 0; j < vert; j++)
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
}

void Adjacency_List()
{
	int num;
	for (i = 0; i < vert; i++)
		h[i] = NULL;
	for (i = 0; i < vert; i++)
	{
		for (j = 0; j < vert; j++)
		{
			printf("\nEnter value for a[%d][%d]", i, j);
			scanf("%d", &num);
			if (num == 1)
			{
				temp = getnode(j);
				if (h[i] == NULL)
				{
					h[i] = temp;
				}
				else
				{
					ptr = findlast(h[i]);
					ptr->next = temp;
				}
			}
		}
		// display_list();
	}
}

void Display_List()
{
	for (i = 0; i < vert; i++)
	{
		ptr = h[i];
		printf("\nV%d::", i);
		while (ptr != NULL)
		{
			printf("V%d---->", ptr->data);
			ptr = ptr->next;
		}
		printf("NL");
	}
}

struct node *getnode(int i)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->next = NULL;
	temp->data = j;
	return (temp);
}

struct node *findlast(struct node *h)
{
	struct node *temp;
	temp = h;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp);
}
