#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct
{
	double value;
	struct Node* pNext;
}Node;


Node* createNode(double newValue)
{
	Node* newNode = malloc(sizeof(*newNode));
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

	int randomNumber[51];
	srand(time(NULL));
	int random = rand();



	printf("hallo");
	for (int i = 0; i <= 50; i++)
	{
		randomNumber[i] = rand();
		Node* new = createNode(rand());
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
	printf("zweites hallo");
	for (int i = 50	; i >= 4; i--)
	{
		randomNumber[i] = randomNumber[i - 1];
	}
	randomNumber[3] = random;
	printf("\n\n%d", randomNumber[3]);


	Node* new = createNode(rand());
	temp = head->pNext;
	new->pNext = temp->pNext;
	temp->pNext = new;

	for (int i = 0; i < 51; i++)
	{
		printf("\n\n %d", randomNumber[i]);
	}
	
	Node* ausgabe = head;
	while (ausgabe != NULL)
	{
		printf("\n\n %f", ausgabe->value);
		ausgabe = ausgabe->pNext;
	}

	while (temp != NULL)
	{
		temp = head;
		head = head->pNext;
		free(temp);
	}
	free(new);
}





}