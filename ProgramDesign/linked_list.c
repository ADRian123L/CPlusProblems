#include <stdio.h>
#include <stdlib.h>

struct node *add_to_list(struct node *list, int n);
struct node *search_list(struct node *list, int n);
struct node *delete_from_list(struct node *list, int n);
void print_list(struct node *list);
int duplicates(struct node *list);
void clear_list(struct node *list);
struct node *find_largest(struct node *list);

struct node {
	int value;          /* data stored in the node  */
	struct node *next;  /* pointer to the next node */
};

int main()
{

 	struct node *first = NULL;

	/* inserting nodes */
	first = add_to_list(first, 3);
	first = add_to_list(first, 64);
	first = add_to_list(first, 98);
	first = add_to_list(first, 3);
        first = add_to_list(first, 64);
	first = add_to_list(first, 3);
	first = add_to_list(first, 136);

	print_list(first);
	
	//add code here
	struct node *p;
	p = find_largest(first);
	printf("The address of the largest value: %p\n", p);
	printf("And the value is: %d\n", p -> value);
 	
	
	clear_list(first);
	return 0;

}

struct node *add_to_list(struct node *list, int n)
{
	  struct node *new_node;
	
	  new_node = malloc(sizeof(struct node));
	  if (new_node == NULL) {
	    printf("malloc failed in add_to_list\n");
	    return list;
	  }
	  new_node->value = n;
	  new_node->next = list;
	  return new_node;
}

struct node *search_list(struct node *list, int n)
{
	  struct node *p;
	
	  for (p = list; p != NULL; p = p->next)
	    if (p->value == n)
	      return p;
	  return NULL;
}

void print_list(struct node *list)
{
	struct node *p;
	for(p= list; p!=NULL; p = p->next)
		printf("%d\t", p->value);
	printf("\n");
}


void clear_list(struct node *list)
{
  struct node *p;
  while(list != NULL)
  {
	 p = list;
     list = list->next;
     if( p!= NULL)
           free(p);
  }
}

struct node *find_largest(struct node *list)
{
	if (list == NULL)
		return NULL;

	struct node *p = list;
	struct node *largest = list;
	// Locate the largest:
	for (; p != NULL; p = p -> next)
		if (p -> value > largest -> value)
			largest = p;

	return largest;
}

int duplicates(struct node *list){
       //add code here

       return 0;

}
