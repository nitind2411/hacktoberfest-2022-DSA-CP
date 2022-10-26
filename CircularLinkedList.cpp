// C++ in circular linked list 

#include <iostream>
using namespace std;

struct Node {
  int data;
  struct Node* next;
};

struct Node* AddingToEmp(struct Node* block, int data) {
  if (block != NULL) return block;
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  block = newNode;
  block->next = block;
  return block;
}

struct Node* AddingToFront(struct Node* block, int data) {
  if (block == NULL) return AddingToEmp(block, data);
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = block->next;
  block->next = newNode;
  return block;
}

struct Node* AddingToEnd(struct Node* block, int data) {
  if (block == NULL) return AddingToEmp(block, data);
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = block->next;
  block->next = newNode;
  block = newNode;
  return block;
}

// inserting a node after specific node
struct Node* AddingAfter(struct Node* block, int data, int item) {
  if (block == NULL) return NULL;
  struct Node *newNode, *p;
  p = block->next;
  do {
  // if the item is found, place newNode after it
  if (p->data == item) {
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = p->next;
    p->next = newNode;

    // if p is the last node, make newNode as the last node
    if (p == block) block = newNode;
    return block;
  }
  p = p->next;
  } while (p != block->next);
  cout << "\nThe given node is not present in the list" << endl;
  return block;
}

// deleting a node
void DelNode(Node** block, int key) {
  if (*block == NULL) return;
  if ((*block)->data == key && (*block)->next == *block) {
  free(*block);
  *block = NULL;
  return;
  }

  Node *temp = *block, *d;

  // if block is to be deleted
  if ((*block)->data == key) {
  while (temp->next != *block) temp = temp->next;
  temp->next = (*block)->next;
  free(*block);
  *block = temp->next;
  }

  while (temp->next != *block && temp->next->data != key) {
  temp = temp->next;
  }

  // if node to be deleted was found
  if (temp->next->data == key) {
  d = temp->next;
  temp->next = d->next;
  free(d);
  }
}

void Traversing(struct Node* block) {
  struct Node* p;

  if (block == NULL) {
  cout << "The list is empty" << endl;
  return;
  }
  p = block->next;
  do {
  cout << p->data << " ";
  p = p->next;
  } while (p != block->next);
}

int main() {
  struct Node* block = NULL;

  block = AddingToEmp(block, 7);
  block = AddingToEnd(block, 9);
  block = AddingToFront(block, 3);
  block = AddingAfter(block, 17, 3);
  Traversing(block);
  DelNode(&block, 9);
  cout << endl;
  Traversing(block);
  return 0;
}
