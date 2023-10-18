#include <iostream>
using namespace std;
#include <unordered_map>
int main()
{

    // Definition for a Node.
    class Node
    {
    public:
        int val;
        Node *next;
        Node *random;

        Node(int _val)
        {
            val = _val;
            next = NULL;
            random = NULL;
        }
    };

    class Solution
    {
    public:
        void rec1(unordered_map<Node *, int> &m1, Node *head)
        {
            Node *temp = head;
            int a = 0;
            while (temp != NULL)
            {
                m1[temp] = a;
                a++;
                temp = temp->next;
            }
        }
        Node *copyRandomList(Node *head)
        {
            unordered_map<Node *, int> m1;
            unordered_map<int, Node *> m2;
            rec1(m1, head);
            if (head == NULL)
            {
                return NULL;
            }
            Node *newhead = new Node(head->val);
            m2[0] = newhead;
            Node *temp = head->next;
            int a = 1;
            Node *tail = newhead;
            while (temp != NULL)
            {
                Node *newnode = new Node(temp->val);
                m2[a] = newnode;
                a++;
                newhead->next = newnode;
                newhead = newnode;
                temp = temp->next;
            }
            Node *temp2 = head;
            Node *temp3 = tail;
            while (tail != NULL)
            {
                if (temp2->random != NULL)
                {
                    tail->random = m2[m1[temp2->random]];
                }
                else
                {
                    tail->random = NULL;
                }
                tail = tail->next;
                temp2 = temp2->next;
            }

            return temp3;
        }
    };
}
