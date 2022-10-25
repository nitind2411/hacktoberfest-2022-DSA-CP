// Recursive C++ program to search
// an element in linked list
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int key;
	struct Node* next;
};

/* Given a reference (pointer to pointer) to the head
of a list and an int, push a new node on the front
of the list. */
void push(struct Node** head_ref, int new_key)
{
	/* allocate node */
	struct Node* new_node
		= (struct Node*)malloc(sizeof(struct Node));

	/* put in the key */
	new_node->key = new_key;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Checks whether the value x is present in linked list */
bool search(struct Node* head, int x)
{
	// Base case
	if (head == NULL)
		return false;

	// If key is present in current node, return true
	if (head->key == x)
		return true;

	// Recur for remaining list
	return search(head->next, x);
}

/* Driver code*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;
	int x = 21;

	/* Use push() to construct below list
	14->21->11->30->10 */
	push(&head, 10);
	push(&head, 30);
	push(&head, 11);
	push(&head, 21);
	push(&head, 14);

	// Function call
	search(head, 21) ? cout << "Yes" : cout << "No";
	return 0;
}

// This code is contributed by SHUBHAMSINGH10
