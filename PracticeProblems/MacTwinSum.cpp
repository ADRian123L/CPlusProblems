#include <iostream>

int main (void)
{
	return 0;
}

struct ListNode {
	int val; 
	struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// Returns the number of nodes:
int numberOfNodes_2 (struct ListNode* head)
{   
    int counter = 0;
    for (; head != NULL; head = head -> next, ++counter)
        ;
    return counter;
}

// Returns a node at the indicated index:
int Xnode (struct ListNode* head, int index)
{
    for (int i = 0; head != NULL && (i < index); head = head -> next, ++i)
        ;
    return head -> val;
}

int pairSum_2(struct ListNode* head){
    int largestSum = 0;
    int nodeSize = numberOfNodes_2 (head);
    int numTwin = nodeSize / 2;
    struct ListNode *p = head;

    for (int i = 0, tmp; i < numTwin; ++i, p = p -> next)
    {
        tmp = p -> val + Xnode(p, (nodeSize - 1) - (i * 2));
        if (tmp > largestSum)
            largestSum = tmp;
    }
    return largestSum;
}

// Second solution:
// Returns the number of nodes:
int numberOfNodes (struct ListNode* head)
{   
    int counter = 0;
    for (; head != NULL; head = head -> next, ++counter)
        ;
    return counter;
}

void ListOfPointer (struct ListNode *head, struct ListNode *list[], const int * nodeSize)
{
	for (int i = 0; head != NULL && i < *nodeSize; ++i, head = head -> next)
		list[i] = head;
} 	

int pairSum (struct ListNode* head)
{
	int largestSum = 0;
	int nodeSize = numberOfNodes (head);
	int numTwin = nodeSize / 2;
	
	struct ListNode* list[nodeSize];
	ListOfPointer (head, list, &nodeSize);

	for (int i = 0, tmp; i < numTwin; ++i)
	{
		tmp = (list[i] -> val) + (list[nodeSize - 1 - i] -> val);
		if (tmp > largestSum)
			largestSum = tmp;
	}
	return largestSum;
}	
