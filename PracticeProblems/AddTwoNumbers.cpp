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
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:

	
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	int L1 {getInts(l1)}, L2 {getInts(l2)};	
	int sum {L1 + L2};
	
	ListNode *head;
	Solution::void setLink (head, sum);	
	return head; 
    
    }
};

Solution::int getLength(ListNode* head)
{
	int length {0};
	for (; head != NULL; head = head -> next, ++length)
		;
	return length;
}

Solution::void copyInt (ListNode* head, int* array)
{
	for (; head != NULL; head = head -> next)
		array++ = head -> val;
}

Solution::int powten (int expo)
{
	if (expo == 0)
		return 1;
	int result = 1;
	for (int i = 0; i < expo; ++i)
		result *= 10;
	return result;
}
Solution::int getInt (ListNode* head, int &number)
{
	int length = Solution::getLength (head);
	int array[length] {0};	
	Solution::copyInt (head, array);
	number = 0;
	for (int i = 0; i < length; ++i)
		number += array[i] * Solution::powten(i);	
	return length;
}
// Second solution:

Solution::int getInts (ListNode* head)	
{
	int number {0};
	for (int i = 1; head != NULL; head = head -> next, i *= 10)
		number += (head -> val) * i;
		
	return number;
}

Solution::int numsInt (int num)
{
	if (num < 10)
		return 1;

	int length {0};
	for (; num > 0; ++length) 
		num =/ 10;

	return length;	
}

Solution::void setLink (ListNode* head, int& num)
{
	int length = Solution::numsInt (num);
	head = new ListNode[length];
	ListNode *p = head, *q {NULL};
	for (int i {10}, j {1}, count {0}; q = p count < length; ++count, i *= 10, j *= 10, p = p -> new)
	{
		p -> val = static_cast<int> (num % i) / j; 
		if (q != NULL)
			q -> next = p;	
	}
	p -> next = NULL;			
}
