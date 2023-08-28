#include<queue>
#include<iostream>
#include<algorithm>
#include<stack>
#include<deque>
using namespace std;
int main(){
    priority_queue<pair<int,int>>pq;
    pq.push({1,2});
    pq.push({2,3});
    pq.push({67,1});
    //cout<<pq.top().first<<endl;
    deque<int>dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(-1);
    sort(dq.begin(),dq.end());
    for(auto i:dq){
        cout<<i<<endl;
    }
    deque<int>dq2;

    dq2 = dq;
     for(auto i:dq2){
        cout<<i<<endl;
    }
    
    
}