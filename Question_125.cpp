//Longest possible arithmetic subsequence recursive approach//
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int rec(int index,int diff,vector<int>nums){
        if(index < 0){
            return 0;
        }
       int ans = 0;
       for(int x=index-1;x>=0;x--){
           if(nums[index]-nums[x] == diff){
               ans = max(ans,1+rec(x,diff,nums));
           }
       }
       return ans;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int index ;
        int ans = 0;
        for(int x=0;x<nums.size();x++){
            index = x;
                for(int k=x+1;k<nums.size();k++){
                    ans = max(ans,2+rec(x,nums[k]-nums[x],nums));
                }
        }  
        return ans; 
    }   
};
////Longest possible arithmetic subsequence memoized approach//
class Solution {
public:
    int rec(int index,int diff,vector<int>nums,vector<unordered_map<int,int>>dp){
        if(index < 0){
            return 0;
        }
        if(dp[index].count(diff) == true){
            return dp[index][diff];
        }
       int ans = 0;
       for(int x=index-1;x>=0;x--){
           if(nums[index]-nums[x] == diff){
               ans = max(ans,1+rec(x,diff,nums,dp));
           }
       }
       //Storing before returning//
       dp[index][diff] = ans;
       return ans;
    }
    int longestArithSeqLength(vector<int>& nums) {
        int index ;
        int ans = 0;
        //Map is used to store the various lengths corresponding to different differences//
        vector<unordered_map<int,int>>dp(nums.size()-1);
        for(int x=0;x<nums.size();x++){
                for(int k=x+1;k<nums.size();k++){
                    ans = max(ans,2+rec(x,nums[k]-nums[x],nums,dp));
                }
        }  
        return ans; 
    }   
};
////Longest possible arithmetic subsequence tabulation approach//
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<unordered_map<int,int>>dp(nums.size()+1);
        if(nums.size() <=2 ){
            return nums.size();
        }
        int ans = 0;
        for(int x=1;x<nums.size();x++){
            //In bottom up approach we will change the approach in reverse order//
            for(int y=0;y<x;y++){
                int diff = nums[x]-nums[y];
                int cnt = 1;
                if(dp[y].count(diff) == true){
                    cnt = dp[y][diff];
                }
                dp[x][diff]=cnt+1;
                ans = max(ans,dp[x][diff]);

            }
        }
        return ans;
    }
};