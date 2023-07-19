#include <iostream>
#include <math.h>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    // Definition for singly-linked list.
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    class Solution
    {
    public:
        vector<int> rec(ListNode *head)
        {
            vector<int> v;
            ListNode *temp = head;
            while (temp != NULL)
            {
                v.push_back(temp->val);
                temp = temp->next;
            }
            reverse(v.begin(), v.end());
            return v;
        }
        void build_stack(stack<int> &s1, stack<int> &s2, vector<int> v)
        {
            for (int x = 0; x < v.size(); x++)
            {
                if (s1.empty() == true)
                {
                    s1.push(v[x]);
                    s2.push(v[x]);
                }
                else
                {
                    s1.push(v[x]);
                    s2.push(max(s1.top(), s2.top()));
                }
            }
        }
        void build_vector(stack<int> &s1, stack<int> &s2, ListNode *head, vector<ListNode *> &v2)
        {
            ListNode *curr = head;
            while (curr != NULL)
            {
                int value = s1.top();
                int maxi = s2.top();
                if (value == maxi)
                {
                    // True value must be kept//
                    v2.push_back(curr);
                }
                curr = curr->next;
                s1.pop();
                s2.pop();
            }
        }
        ListNode *removeNodes(ListNode *head)
        {
            stack<int> s1;
            stack<int> s2;
            vector<int> v;
            v = rec(head);
            build_stack(s1, s2, v);
            vector<ListNode *> v2;
            build_vector(s1, s2, head, v2);
            ListNode *temp1 = v2[0];
            ListNode *temp2 = temp1;
            if (v2.size() == 0)
            {
                return NULL;
            }
            if (v2.size() == 1)
            {
                ListNode *temp3 = v2[0];
                return temp3;
            }
            for (int x = 1; x < v2.size(); x++)
            {
                temp1->next = v2[x];
                temp1 = temp1->next;
                if (x == v2.size() - 1)
                {
                    temp1 = NULL;
                }
            }
            return temp2;
        }
    };
}