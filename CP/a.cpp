#include <iostream>
#include <cmath>
using namespace std;
#include <vector>
#include <numeric>
class Node
{
public:
  int val;
  Node *next;
  Node(int f)
  {
    val = f;
    this->next = NULL;
  }
};
void insertAtHead(Node *&head, int val)
{
  Node *newnode = new Node(val);
  newnode->next = head;
  head = newnode;
  return;
}
void deletion(int key, Node *&head)
{
  Node *temp = head;
  Node *prev = NULL;
  while (temp != NULL)
  {
    if (temp->val == key && prev == NULL)
    {
      head = temp->next;
      temp = temp->next;
    }
    else if (temp->val == key && prev != NULL)
    {
      prev->next = temp->next;
      temp = temp->next;
    }
    else if (temp->val != key)
    {
      prev = temp;
      temp = temp->next;
    }
  }
}
void insertAttail(Node *&tail, int val)
{
  Node *newnode = new Node(val);
  tail->next = newnode;
  tail = newnode;
}
void traverse(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;
}
int main()
{
  Node *head = new Node(1);
  Node *tail = head;
  traverse(head);
  insertAtHead(head, 2);
  insertAtHead(head, 3);

  insertAtHead(head, 4);
  insertAtHead(head, 5);
  insertAttail(tail, 67);

  traverse(head);
}
