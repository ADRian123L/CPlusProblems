#include <iostream>
#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

int main (void)
{
	return 0;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
        if (list1 == NULL)
            return list2;
        else if (list2 == NULL)
            return list1;

        struct ListNode *head, *p;
        // Set head to smallest of the starting two nodes:
        if (list1 -> val <= list2 -> val)
        {
            head = list1;
	        list1 = list1 -> next;
        } 
        else
        {
            head = list2;
	        list2 = list2 -> next;
        }
  
        // Merge the linked list:
        p = head;
        while (p != NULL && ((list1 != NULL) || (list2 != NULL)))
        {
            if (list1 != NULL && list2 != NULL)
            {
                if (list1 -> val <= list2 -> val)
                {
                    p -> next = list1;
		    p = list1;
                    (list1 != NULL) ? (list1 = list1 -> next): (list1);
                }
                else
                {
                    p -> next = list2;
		    p = list2;
                    (list2 != NULL) ? (list2 = list2 -> next): (list2);
                }
            }
            else if (list1 != NULL)
            {
                p -> next = list1;
		p = list1;
                (list1 != NULL) ? (list1 = list1 -> next): (list1);
            }
            else
            {
                p -> next = list2;
		p = list2;
                (list2 != NULL) ? (list2 = list2 -> next): (list2);
            }
        }
        return head;
} 
