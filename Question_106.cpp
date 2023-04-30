#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    vector<int>num;
    num.push_back(1);
    num.push_back(1);
    num.push_back(3);
    num.push_back(4);
    auto lower = lower_bound(num.begin(),num.end(),2);
    auto upper = upper_bound(num.begin(),num.end(),2);
   cout<<*(lower);
   cout<<*(upper);
}