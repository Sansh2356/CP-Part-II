#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Odd-even linked list//
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
int main(){
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL){return NULL;}
        ListNode*fwd;
        ListNode*fwd2;
        if(head->next != NULL){fwd = head->next;}
        //Storage is always required to join the connections hence it will be required//
        fwd2 = fwd;
        ListNode*temp = head;
        while(temp->next != NULL && fwd->next != NULL){
            temp->next = fwd->next;
            temp = fwd->next;
            fwd->next = temp->next;
            fwd = temp->next;
        }
        temp->next = fwd2;
        return head;
    }
};
}