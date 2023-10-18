#include <iostream>
using namespace std;

class node
{
public:
  int data;
  node *next;

  node(int data)
  {
    this->data = data;
    this->next = NULL;
  }

  ~node()
  {
    int value = this->data;
    if (this->next != NULL)
    {
      delete next;
      this->next = NULL;
    }
  }
};

void insert(node *&head, int d)
{
  node *temp = new node(d);
  temp->next = head;
  head = temp;
}
void insertatlast(node *&last, int d)
{
  node *temp = new node(d);
  last->next = temp;
  last = last->next;
}
int length(node *&head)
{
  node *ptr = head;
  int count = 1;
  while (ptr != NULL)
  {
    ptr = ptr->next;
    count++;
  }
  return count;
}
void middlenodehead(node *&head)
{
  int count = 1;
  node *temp = head;
  node *res = head;
  if (length(head) % 2 != 0)
  {
    while (count != (length(head) + 1) / 2)
    {
      temp = temp->next;
      count++;
    }
    head = temp;
  }
  else
  {
    while (count != (length(head)) / 2 + 1)
    {
      temp = temp->next;
      count++;
    }
    head = temp;
  }
}
void insertatpos(node *last, node *&head, int position, int d)
{
  node *temp = head;
  int count = 1;
  while (count < position - 1)
  {
    temp = temp->next;
    count++;
  }
  // Insert at Head
  if (position == 1)
  {
    insert(head, d);
    return;
  }
  // Insert at Tail
  if (temp->next == NULL)
  {
    insertatlast(last, d);
    return;
  }
  node *node_middle = new node(d);
  node_middle->next = temp->next;
  temp->next = node_middle;
}
void deletepos(int pos, node *&head, node *&tail)
{
  node *curr = head;
  node *prev = NULL;
  node *temp = head;
  int count = 1;
  if (pos == 1)
  {
    curr = curr->next;
    head = curr;
    curr = NULL;
    delete curr;
  }
  else
  {
    while (count < pos)
    {
      prev = curr;
      curr = curr->next;
      count++;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
  }
}
// int N_node(node* &tail,int pos)
// { node*temp = tail;
//   while
//   {

//   }
// }
void print(node *&head)
{
  node *ptr = head;
  while (ptr != NULL)
  {
    cout << ptr->data << " ";
    ptr = ptr->next;
  }
};
int main()
{
  node *node1 = new node(10);
  node *head = node1;
  insert(head, 11); // Insert at Head
  insert(head, 12);
  insert(head, 13);
  insert(head, 14);
  insert(head, 15);
  //print(head);
  node *last = node1;
  // insertatlast(last,9); //Insert at
   insertatpos(last,head,2,8); //Insert at Middle
    //print(head);
  // //Deletion of a Node :
 // deletepos(1, head, last);
  print(head);
   middlenodehead(head);
  
  return 0;
}