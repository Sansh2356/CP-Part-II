#include <iostream>
#include <vector>
#include<unordered_map>
#include <queue>
using namespace std;
class Node
{
public:
  int val;
  Node *left;
  Node *right;
  Node(int f)
  {
    this->left = NULL;
    this->right = NULL;
    this->val = f;
  }
};
Node *construct(int val, Node *root)
{
  // Constructing new node //
  Node *newnode = new Node(val);
  root = newnode;
  if (val == -1)
  {
    return NULL;
  }
  else
  {
    cout << "Enter the value to be enetered on left node of :" << " " << root->val << endl;
    int leftval;
    cin >> leftval;
    root->left = construct(leftval, root->left);
    cout << "Enter the value to be enetered on right node of :" << " " << root->val << endl;
    int rightval;
    cin >> rightval;
    root->right = construct(rightval, root->right);
  }
  return root;
}
void preorder(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  cout << root->val << " ";
  preorder(root->left);
  preorder(root->right);
}
void inorder(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
}
void postorder(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout << root->val << " ";
}
unordered_map<int,vector<int>> create_adj_list(vector<vector<int>>edge){
  unordered_map<int,vector<int>>adj_list;
  for(int x=0;x<edge.size();x++){
    int node1 = edge[x][0];
    int node2 = edge[x][1];
    adj_list[node1].push_back(node2);
    adj_list[node2].push_back(node1);
  }
  return adj_list;
}
int main()
{
  char ch = '[';
  if((int)'a' <=(int)ch <= (int)'z'){
    cout<<(int)'z'<<endl;
    cout<<(int)'a'<<endl;
    cout<<(int)ch<<endl;
  }
  else{
    cout<<"sadasds"<<endl;
  }
}