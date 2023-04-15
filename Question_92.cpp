#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node*next;
    node(int f){
        this->val = f;
        this->next = NULL;
    }
};
node*Insert_at_head(node*head,int value){
    node*newnode = new node(value);
    head->next = newnode;
    newnode->next = NULL;
    return (head);
}
void print(node*head){
    node*temp = head;
    while(temp != NULL){
        cout<<temp->val<<endl;
        temp = temp->next;
    }
}
node*deletion(node*head,int value){
    node*temp = head;
    node*prev = NULL;
    while(temp->val != value && temp != NULL){
        temp = temp->next;
        prev = temp;
    }
    prev->next = temp->next;
    temp->next = NULL;
    delete (temp);
    
}

int main(){
    //Dynamic creation of a node // 
    node*head = new node(1);
    node*tail = head;

}