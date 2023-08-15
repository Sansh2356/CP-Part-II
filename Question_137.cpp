#include <iostream>
using namespace std;
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <vector>
#include <set>
class tree
{
public:
    int val;
    tree *right;
    tree *left;
    tree(int f)
    {
        this->val = f;
        this->left = NULL;
        this->right = NULL;
    }
};
tree *build_tree(tree *root)
{
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter the value to be inserted" << endl;
    int val;
    cin >> val;
    root = new tree(val);
    cout << "The value to be inserted at left of the curr node" << endl;
    int leftdata;
    cin >> leftdata;
    root->left = build_tree(root->left, leftdata);
    cout << "The value to be  entered at the right of the curr node" << endl;
    int rightdata;
    cin >> rightdata;
    root->right = build_tree(root->right, rightdata);
    return root;
}
void print_tree(tree*root){
    if(root == NULL){
        return;
    }
    print_tree(root->left);
    cout<<root->val<<endl;
    print_tree(root->right);
}

int main()
{
    tree *root = NULL;
    int data;
    build_tree(root);
    cout<<root<<endl;
    print_tree(root);

}