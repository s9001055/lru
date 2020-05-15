#include <stdio.h>
#include <stdlib.h>

#define char	int8_t
#define int 	int32_t
#define long	int64_t

#define nodeCount 10
void *head = NULL; 
int32_t numOfNode = 0;

typedef struct linkNode{
	int32_t key;
	struct linkNode *next;
}linkNode;

void victim()
{
	struct linkNode *victNode = head;
	struct linkNode *prevNode;
	while (victNode -> next != NULL){
		prevNode = victNode;
		victNode = victNode -> next;
	}
	prevNode -> next = NULL;
	free(victNode);
	numOfNode -= 1;
}

void insertNode(int32_t key)
{
	if (numOfNode == nodeCount)
		victim();
	
	struct linkNode *newNode = malloc(sizeof(linkNode));
	newNode -> key = key;
	newNode -> next = head;
	head = newNode;
	numOfNode++;
}

void moveToMru(struct linkNode *keyNode, struct linkNode *prevNode)
{
	prevNode -> next = keyNode -> next;
	keyNode -> next = head;
	head = keyNode;
}

int32_t findNode(int32_t key)
{
	struct linkNode *keyNode = head;
	struct linkNode *prevNode = head;
	while (keyNode != NULL){
		if (keyNode -> key == key){
			moveToMru(keyNode, prevNode);
			return 0;
		}
		prevNode = keyNode;
		keyNode = keyNode -> next;
	}
	insertNode(key);
	return 0;
}

int main()
{
	return 0;
}

/*
void testPrintLRU()
{
	struct linkNode *thisNode;
	
	thisNode = head;
	while (thisNode != NULL){
		printf("%d -> ",thisNode -> key);
		thisNode = thisNode -> next;
	}
	printf("NULL\n");
}

int main()
{
	int input;
	while(1){
		printf("input your key\n");
		scanf("%d",&input);
		findNode(input);
		testPrintLRU();
	}
}
*/
