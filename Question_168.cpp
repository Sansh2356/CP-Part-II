#include<iostream>
#include<vector>
using namespace std;
int main(){
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<int>sf(nums.size(),0);
        vector<int>pf(nums.size(),0);
        int a = nums[0];
        for(int x=0;x<nums.size();x++){
            pf[x]=a;
            a=max(nums[x],a);
        }
        int b = nums[nums.size()-1];
        for(int x=nums.size()-2;x>=0;x--){
            sf[x]=b;
            b=max(b,nums[x]);
        }
        long long ans = 0;
        for(int x=0;x<nums.size();x++){
            long long s = (long long)(pf[x]-nums[x])*(sf[x]);
            if(ans<s)ans=s;
        }
        return ans;
    }
};
}