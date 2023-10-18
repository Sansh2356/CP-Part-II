#include<iostream>
#include<vector>
#include<algorithm>
int main(){
    class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = INT_MAX;
        if(nums.size()==1)return 0;
        int p = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dub;
        for(int x=0;x<nums.size()-1;x++){
            if(nums[x+1]==nums[x])continue;
            else{dub.push_back(nums[x]);}    
        }
        dub.push_back(nums[nums.size()-1]);
        nums=dub;
        int uni=p-dub.size();
        for(int x=0;x<nums.size();x++){
            int l=nums[x];
            int r = (p-1+l);
            int cnt = 0;
            //range will be from l to r both included//
            //we will check for all those values which do not lie in this range
            //the non lying values must be changed//
            
            ans=min(ans,cnt+uni);
        }
        return ans;
    }
};
}