#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int data) {
    this->data = data;
    next = NULL;
  }
};

class SinglyLinkedList {
  Node *head = NULL;

public:
  void insert(int value, int pos) {
    Node *temp = new Node(value);
    if (head == NULL) {
      head = temp;
      return;
    }
    if (pos == 0) {
      // insert at begin
      temp->next = head;
      head = temp;
    } else if (pos == -1) {
      // insert at end
      Node *curr = head;
      while (curr->next != NULL) {
        curr = curr->next;
      }
      curr->next = temp;
    } else {
      // insert at given pos
      Node *curr = head;
      int count = 1;
      while (count != pos - 1 && curr != NULL) {
        curr = curr->next;
        count += 1;
      }
      if (curr == NULL)
        cout << "Invalid Position" << endl;
      else {
        temp->next = curr->next;
        curr->next = temp;
      }
    }
  }

  // traverse Operation
  void traverse() {
    Node *curr = head;
    while (curr != NULL) {
      cout << curr->data;
      if (curr->next != NULL)
        cout << " -> ";
      curr = curr->next;
    }
    cout << endl;
  }
};

int main() {
  SinglyLinkedList sll;
  sll.insert(10, 0);
  sll.insert(20, 0);
  sll.insert(30, 0);
  sll.insert(40, 0);
  sll.insert(50, -1)
  sll.traverse();
  return 0;
}
