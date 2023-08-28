#include <iostream>
#include <vector>
using namespace std;
// Jump game variation 2 minimum possible length of sequnece of jumps//
int main()
{
    class Solution
    {
    public:
        int rec(vector<int> &nums, int index, vector<int> &dp)
        {
            if (index >= nums.size())
            {
                return 10000;
            }
            if (index == nums.size() - 1)
            {
                return 1;
            }
            if (nums[index] == 0)
            {
                return 10000;
            }
            if (dp[index] != -1)
            {
                return dp[index];
            }
            int ans = INT_MAX;
            for (int x = 1; x <= nums[index]; x++)
            {
                ans = min(ans, 1 + rec(nums, index + x, dp));
            }
            dp[index] = ans;
            return dp[index];
        }
        int jump(vector<int> &nums)
        {
            vector<int> dp(nums.size() + 1, -1);
            return rec(nums, 0, dp) - 1;
        }
    };
}

/*
class Solution {
public:
    int rec(vector<int>&nums,int target,int index,vector<int>&dp){
        if(index >= nums.size()){
            return 0;
        }
        if(index == nums.size()-1){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int ans = INT_MIN;
        for(int x=1;x<nums.size();x++){
            if(index+x < nums.size() && abs(nums[index]-nums[index+x])<= target){
                ans = max(ans,1+rec(nums,target,index+x,dp));
            }
        }
        return dp[index] = ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int>dp(nums.size()+1,-1);
        int a = rec(nums,target,0,dp);
        if(a < 0){
            return -1;
        }
        return a;
    }
};

*/