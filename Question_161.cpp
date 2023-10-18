#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Node{
    public:
    int val;
    Node*next;
    Node*prev;
    Node(int f){
        this->val = f;
        this->prev = NULL;
        this->next = NULL;
    }
};
void insert_at_head(Node*&head,int v,Node*&tail){
    if(head == NULL){
        Node*newnode = new Node(v);
        head = newnode;
        tail = head;
        return;
    }
    else{
        Node*newnode = new Node(v);
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
        return;
    }
}
void print_next(Node*head){
    Node*temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void print_prev(Node*head){
    Node*temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->prev;
    }
    cout<<endl;
}
void insert_at_tail(Node*&tail,int v){
    if(tail == NULL){
        Node*newnode = new Node(v);
        newnode = tail;
        return;
    }
    else{
        Node*newnode = new Node(v);
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
        return;
        
    }
}
void freq1(Node*head){
    unordered_map<int,int>m;
    Node*temp = head;
    while(temp != NULL){
        if(m.count(temp->val) == true){
            m[temp->val]++;
        }
        else{
            m[temp->val]=1;
        }
        temp = temp->next;
        
    }
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
}
int freq2(Node*head){
    Node*temp = head;
    int a = 0;
    while(temp != NULL){
        a++;
        temp = temp->next;
    }
    //cout<<"Length is :-"<<" "<<a<<endl;
    return a;
}
void insert_at_pos(Node*head,int pos,int v){
    Node*newnode = new Node(v);
    Node*temp = head;
    pos = pos-1;
    while(pos > 0){
        temp = temp->next;
        pos--;
    }
    temp = temp->prev;
    temp->next->prev = newnode;
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    
    return;
}
void delete_head(Node*&head){
    head = head->next;
    head->prev = NULL;
}
void delete_tail(Node*&tail){
   tail = tail->prev;
   tail->next = NULL;
}
void delete_pos(Node*head,int pos){
    Node*temp = head;
    while(pos--){
        temp = temp->next;
    }
    temp = temp->prev;
    temp->prev->next = temp->next;
    temp->prev = NULL;
    temp->next = NULL;
}
void rev(Node*head,Node*tail){
    int l = freq2(head);
    l/=2;
    Node*temp1=head;
    Node*temp2=tail;
    while(l--){
        int a = temp1->val;
        temp1->val = temp2->val;
        temp2->val = a;
        temp1 =temp1->next;
        temp2 = temp2->prev;
    }
}
int main(){
    Node*head = NULL;
    Node*tail = NULL;
    insert_at_head(head,1,tail);
    insert_at_head(head,2,tail);
    insert_at_head(head,5,tail);
     //print_next(head);
    insert_at_head(head,3,tail);
     //print_next(head);
    // print_prev(head);
     insert_at_tail(tail,4);
    //  print_next(head);
    //  print_prev(head);
    //freq1(head);
    rev(head,tail);
    print_next(head);
    //cout<<"Total nodes:-"<<freq2(head)<<endl;
     //print_next(head);
    // insert_at_tail(tail,5);
    // print_next(head);
    // print_prev(head);
     //insert_at_pos(head,3,55);
     //print_next(head);
    // print_prev(head);
     //delete_head(head);
     // print_next(head);
    //  delete_tail(tail);
    //  print_next(head);
    // print_next(head);
    // delete_pos(head,3);
    // print_next(head);
    // print_next(head);
    // rev(head,tail);
    // print_next(head);
   
    //print_next(head);
}