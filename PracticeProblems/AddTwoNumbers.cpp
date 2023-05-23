#include <iostream>

int main(void)
{
	return 0;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
	int val;
	ListNode *next;
};
// Second solution:

class Solution {
public:
	void AddList (ListNode*& l1, ListNode*& l2, ListNode*& head);
	ListNode* Next (ListNode* list);
	int Val (ListNode* list);	
	bool Mem (ListNode* l1, ListNode* l2);

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* head = NULL;
	AddList (l1, l2, head);
	return head;	
    }
};

void Solution::AddList (ListNode*& l1, ListNode*& l2, ListNode*& head)
{
	// Allocate mem for the first node:
	head = new ListNode;
	ListNode *p = head, *q = head;
	
	int carryOut = 0, tmp;
	for (; !(l1 == NULL && l2 == NULL); l1 = Next(l1), l2 = Next(l2), q = p)
	{
		if (carryOut == 1)
			tmp = Val(l1) + Val(l2) + 1;
		else
			tmp = Val(l1) + Val(l2); 
		// Check if there is a carry bit:
		if (tmp > 9)
		{
			carryOut = 1;
			tmp = tmp % 10;
		}
		else
			carryOut = 0;
		
		// Assign the value to head:
		p -> val = tmp;	
		// Allocate more mem is neccesarry:
		if (Mem(l1, l2))
			p = new ListNode;
		// Point q to p:
		q -> next = p;
	}
	p -> next = NULL;
}

bool Solution::Mem (ListNode* l1, ListNode* l2)
{
	if (l1 == NULL || l2 == NULL)
	{
		if (l1 == NULL)
		{
			if (l2 -> next == NULL)
				return false;
			else 
				return true;
		}
		else if (l2 == NULL)
		{
			if (l1 -> next == NULL)
				return false;
			else
				return true;
		}
	}
	if (l1 -> next == NULL && l2 -> next == NULL)
		return false;
	return false;	
}

ListNode* Solution::Next (ListNode* list)
{
	if (list == NULL)
		return NULL;
	if (list -> next == NULL)
		return NULL;
	else
		return list -> next;
}

int Solution::Val (ListNode* list)
{
	if (list == NULL)
		return 0;
	else
		return list -> val;
}	
