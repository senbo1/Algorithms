#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node(int data): data(data) {};
};

void insert(Node** headRef, int data) {
  Node* newNode = new Node(data);
  newNode->next = *headRef;
  *headRef = newNode;
}

void insertN(Node** headRef, int data, int n) {
  Node* newNode = new Node(data);
  if(n == 1) {
    newNode->next = *headRef;
    *headRef = newNode;
  }
  Node* temp = *headRef;
  for(int i = 1; i < n - 1;i++) {
    temp = temp->next;
  }
  newNode->next = temp->next;
  temp->next = newNode;
}

void deleteNode(Node** headRef, int n) {
  Node* temp = *headRef;
  if(n == 1) {
    *headRef = (*headRef)->next;
    delete temp;
  }
  for(int i = 1; i < n - 1; i++) {
    temp = temp->next;
  }
  Node* nNode = temp->next;
  temp->next = nNode ->next;
  delete nNode;
}

void print(Node* head) {
  while(head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  Node* head = NULL;
  insert(&head, 4); insert(&head, 3); insert(&head, 1); 
  print(head);
  insertN(&head, 2, 2);
  insertN(&head, 69, 3);
  print(head);
  deleteNode(&head, 3);
  print(head);
}