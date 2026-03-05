#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct 
{
	double value;
	struct Node* pNext;
}Node;


Node *createNode(double newValue)
{
	Node *newNode = malloc(sizeof(*newNode));
	if (newNode == NULL)
	{
		printf("Falscher rückgabewert!!!");
		return -1;
	}
	else
	{
		newNode->value = newValue;
		return newNode;
	}
}


int main()
{
	Node* head = NULL;
	Node* temp = NULL;
	
	int randomNumber[50];
	srand(time(NULL));
	int random = rand();

	for (int i = 0; i <= 50; i++)
	{
		randomNumber[i] = rand();
		Node *new = createNode(rand());
		if (head == NULL)
		{
			head = new;
			temp = new;
		}
		else
		{
			temp->pNext = new;
			temp = new;
		}
	}





}