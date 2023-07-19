#include <iostream>
#include <list>
#include <cmath>
#include <unordered_map>
#include <queue>
#include <math.h>
using namespace std;
int main()
{

    // Definition for a binary tree node.
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class Solution
    {
    public:
        void parent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &m)
        {
            queue<TreeNode *> q;
            q.push(root);
            while (q.empty() != true)
            {
                // BFS to get all the parents of all the coressponding nodes//
                TreeNode *front = q.front();
                q.pop();
                if (front == root)
                {
                    m[front] = NULL;
                }
                if (front->left != NULL)
                {
                    q.push(front->left);
                    m[front->left] = front;
                }
                if (front->right != NULL)
                {
                    q.push(front->right);
                    m[front->right] = front;
                }
            }
        }
        void rec(unordered_map<TreeNode *, TreeNode *> m, unordered_map<TreeNode *, bool> &visited, TreeNode *target, vector<int> &ans, int k)
        {
            queue<TreeNode *> q;
            q.push(target);
            visited[target] = true;
            int count = 0;
            while (q.empty() != true && count < k)
            {
                int size = q.size();
                for (int x = 0; x < size; x++)
                {
                    TreeNode *front = q.front();
                    q.pop();
                    if (front != NULL && front->left != NULL)
                    {
                        if (visited.count(front->left) == false)
                        {
                            q.push(front->left);
                            visited[front->left] = true;
                        }
                    }
                    if (front != NULL && front->right != NULL)
                    {
                        if (visited.count(front->right) == false)
                        {
                            q.push(front->right);
                            visited[front->right];
                        }
                    }
                    if (visited.count(m[front]) == false)
                    {
                        q.push(m[front]);
                        visited[m[front]] = true;
                    }
                }

                count++;
            }
            while (q.empty() != true)
            {
                if (q.front() != NULL)
                {
                    ans.push_back(q.front()->val);
                }
                q.pop();
            }
        }
        vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
        {
            unordered_map<TreeNode *, TreeNode *> m;
            unordered_map<TreeNode *, bool> visited;
            parent(root, m);
            if (m.size() == 1)
            {
                return {};
            }
            vector<int> ans;
            rec(m, visited, target, ans, k);
            return ans;
        }
    };
}