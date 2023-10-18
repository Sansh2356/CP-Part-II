#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node*prev;
    Node*next;
    Node(int f){
        this->val = f;
        this->prev = NULL;
        this->next = NULL;
    }
};
void insert(Node*&head,int v){
    if(head == NULL){
        Node*newnode = new Node(v);
       head = newnode;
        return;
    }
    else{
        Node*newnode = new Node(v);
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}
void print(Node*head){
    Node*temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}
int main(){
    Node*head = NULL;
    insert(head,5);
    insert(head,4);
    insert(head,3);
    insert(head,2);
    insert(head,1);
    print(head);


    
}