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

  //search by value
  void searchByValue(int value){
    Node *curr = head;
    int pos = 1;
    while(curr->data != value && curr != NULL){
        curr = curr->next;
        pos += 1;
    }
    if(curr == NULL)
        cout<<"\nValue has not been found\n";
    else{
        cout<<"\nValue has been found at position "<<pos<<"\n";
    }
  }

  //search by pos
  void searchByPos(int pos){
    Node *curr = head;
    int count = 1;
    while(count != pos && curr != NULL){
        curr = curr->next;
        count += 1;
    }
    if(curr == NULL)
        cout<<"\nValue has not been found\n";
    else{
        cout<<"\n"<<curr->data<<"Value has been found at pos:\n";
    }
  }

  //delete by value
  void deleteByValue(int value){
    Node *curr = head;
    while(curr->next->data != value && curr != NULL){
        curr = curr->next;
    }
    if(curr == NULL)
        cout<<"\nValue has not been found\n";
    else{
        curr->next = curr->next->next;
        cout<<"\nValue has been deleted successfully\n";
    }
  }

  //delete by pos
  void deleteByPos(int pos){
      Node *curr = head;
      int count = 1;
      while(pos != count-1 && curr != NULL){
          curr = curr->next;
      }
      if(curr == NULL)
          cout<<"\nInvalid Position\n";
      else
          curr->next = curr->next->next;
          cout<<"\nValue has been deleted successfully\n";
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
  char ch = 'y';
  int choice;
  do{
    cout<<"\n------------------------\n";
    cout<<"1. Create a Singly Linked List\n";
    cout<<"2. Insert at begin\n";
    cout<<"3. Insert at end\n";
    cout<<"4. Insert at given position\n";
    cout<<"5. Delete by value\n";
    cout<<"6. Delete by position\n";
    cout<<"7. Display all element\n";
    cout<<"8. Search by value\n";
    cout<<"9. Search by position\n";
    cout<<"\n------------------------\n";
  
    cout<<"Enter a choice:";
    cin>>choice;
    switch(choice){
      case 1:{
        cout<<"\nList has been created\n";
        break;
      }
      case 2:{
        int val;
        cout<<"\nEnter a value to be inserted: ";
        cin>>val;
        sll.insert(val,0);
        cout<<"\nValue has been inserted successfully\n";
        break;
      }

      case 3:{
        int val;
        cout<<"\nEnter a value to be inserted: ";
        cin>>val;
        sll.insert(val,-1);
        cout<<"\nValue has been inserted successfully\n";
        break;
      }

      case 4:{
        int val, pos;
        cout<<"\nEnter a value  and position: ";
        cin>>val>>pos;
        sll.insert(val,pos);
        cout<<"\nValue has been inserted successfully\n";
        break;
      }

      case 5:{
        int val;
        cout<<"\nEnter a value to be deleted: ";
        cin>>val;
        sll.deleteByValue(val);
        break;
      }
      case 6:{
        int pos;
        cout<<"\nEnter a pos: ";
        cin>>pos;
        sll.deleteByPos(pos);
        break;
      }
      case 7:{
        cout<<"\nFollowing are the elements of the list:\n";
        sll.traverse();
        break;
      }
       case 8:{
          int value;
          cout<<"\nEnter a value to be searched: \n";
          cin>>value;
          sll.searchByValue(value);
        break;
      }
       case 9:{
          int pos;
          cout<<"\nEnter a position to be searched: \n";
          cin>>pos;
          sll.searchByPos(pos);
        break;
      }
      default:
        cout<<"\nInvalid position\n";
        break;
    }
    cout<<"\nDo you want to continue[Y/N]: ";
    cin>>ch;
  }while(ch == 'y' || ch == 'Y');
    
  return 0;
}
