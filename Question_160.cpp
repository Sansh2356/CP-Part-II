#include<iostream>
#include<fstream>
#include<vector>
#include<unordered_map>
#define ll long long;
using namespace std;
class Node{
    public:
};
int main(){
    // int t;
    // cin>>t;
    // while(t--){
       

    // }
    class Solution {
public:
    int rec(vector<int>&nums,int x,int l,int r,bool flag){
        if(x < 0){
            return INT_MAX;
        }
        if(x == 0){
            return INT_MAX;
        }
        if(l >= r){
            return INT_MAX;
        }
        int a,b,c,d,e,f;
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        e = 0;
        f = 0;
        if(flag == true){
            a = rec(nums,x,l,r,false);
            if(nums[l] <= x){
                b = 1+rec(nums,x-nums[l],l+1,r,false);
            }
            c = min(a,b);
        }
        else{
            d = rec(nums,x,l,r,true);
            if(nums[r] <= x){
                e = 1+rec(nums,x-nums[r],l,r+1,false);
            }
            f = min(d,e);

        }
        return min(f,c);

    }
    int minOperations(vector<int>& nums, int x) {
        return rec(nums,x,0,0,true);
    }
};
}