#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int f)
    {
        this->val = f;
        this->next = NULL;
    }
};
void insert_at_head(Node *&head)
{
    cout << "Enter data to be inserted" << endl;
    int data;
    cin >> data;
    Node *newnode = new Node(data);
    head->next = newnode;
    head = newnode;
    newnode->next = NULL;
}
void insert_at_tail(Node *&tail)
{
    int data;
    cout << "Enter data to be inserted at tail" << endl;
    cin >> data;
    Node *newnode = new Node(data);
    newnode->next = tail;
    tail = newnode;
}
void print(Node *head)
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
    Node *head = NULL;
    int data;
    cin >> data;
    head = new Node(data);
    head->next = NULL;
    Node *tail = head;
    insert_at_head(head);
    insert_at_head(head);
    insert_at_head(head);
    insert_at_head(head);
    insert_at_head(head);
    insert_at_head(head);
    insert_at_tail(tail);
    insert_at_tail(tail);
    print(tail);
}
