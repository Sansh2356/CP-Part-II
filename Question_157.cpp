#include <iostream>
#include <unordered_map>
#include <set>
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
void insert_at_head(Node *&head, int f)
{
    if (head == NULL)
    {
        Node *newnode = new Node(f);
        head = newnode;
        return;
    }
    else
    {
        Node *newnode = new Node(f);
        newnode->next = head;
        head = newnode;
        return;
    }
}
void check_size(Node *&head)
{
    Node *temp = head;
    int k = 0;
    set<int> s;
    while (temp != NULL)
    {
        s.insert(temp->val);
        temp = temp->next;
        k++;
    }
    if (s.find(k) == s.end())
    {
        cout << "Error encountered" << endl;
        return;
    }
}

int main()
{
    Node *head = NULL;
    insert_at_head(head, 1);
    insert_at_head(head, 2);
    insert_at_head(head, 3);
    check_size(head);
}