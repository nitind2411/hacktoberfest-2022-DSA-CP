// Linked list in C++

#include <stdlib.h>
#include <iostream>
using namespace std;

// Create a node
struct Node {
  int data;
  struct Node* next;
};

void insertAtBeg(struct Node** head_at, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  // insert the data
  new_node->data = new_data;
  new_node->next = (*head_at);
  (*head_at) = new_node;
}

void insertAft(struct Node* pre_node, int new_data) {
  if (pre_node == NULL) {
  cout << "previous node cannot be equal to NULL";
  return;
  }

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = pre_node->next;
  pre_node->next = new_node;
}

// Insert at end
void insertAtEnd(struct Node** head_at, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *head_at; 
  new_node->data = new_data;
  new_node->next = NULL;

  if (*head_at == NULL) {
  *head_at = new_node;
  return;
  }

  while (last->next != NULL) last = last->next;
  last->next = new_node;
  return;
}

void delNode(struct Node** head_at, int key) {
  struct Node *temp = *head_at, *prev;

  if (temp != NULL && temp->data == key) {
  *head_at = temp->next;
  free(temp);
  return;
  }

  while (temp != NULL && temp->data != key) {
  prev = temp;
  temp = temp->next;
  }

  // If the key is not present
  if (temp == NULL) return;
  prev->next = temp->next;
  free(temp);
}

bool searchingNode(struct Node** head_at, int key) {
  struct Node* cur = *head_at;

  while (cur != NULL) {
  if (cur->data == key) return true;
  cur = cur->next;
  }
  return false;
}

// Sorting linked list
void SortingList(struct Node** head_at) {
  struct Node *cur = *head_at, *index = NULL;
  int temp;

  if (head_at == NULL) {
  return;
  } 
  else {
  while (cur != NULL) {
    index = cur->next;

    while (index != NULL) {
    if (cur->data > index->data) {
      temp = cur->data;
      cur->data = index->data;
      index->data = temp;
    }
    index = index->next;
    }
    cur = cur->next;
  }
  }
}


void display(struct Node* node) {
  while (node != NULL) {
  cout << node->data << " ";
  node = node->next;
  }
}

// Driver program
int main() {
  struct Node* head = NULL;

  insertAtEnd(&head, 1);
  insertAtBeg(&head, 2);
  insertAtBeg(&head, 5);
  insertAtEnd(&head, 7);
  insertAft(head->next, 9);

  cout << "Linked list: ";
  display(head);

  cout << "\nAfter deleting an element: ";
  delNode(&head, 2);
  display(head);

  int find = 1;
  if (searchingNode(&head, find)) {
  cout << endl << find << " is found";
  } else {
  cout << endl << find << " is not found";
  }

  SortingList(&head);
  cout << "\nList is Sorted= ";
  display(head);
}
