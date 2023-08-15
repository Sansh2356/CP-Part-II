#include<iostream>
#include<vector>
using namespace std;
int main(){


class Solution {
public:
    int rec(vector<vector<int>>&matrix,int m,int r,int c,vector<vector<int>>&dp){
     if( r == m){
         return 0;
     }
     if(c < 0 ){
         return 10e6;
     }
     if(c > (m-1)){
         return 10e6;
     }
     if(dp[r][c] != -1){
         return dp[r][c];
     }
     int a =  matrix[r][c]+rec(matrix,m,r+1,c-1,dp);
     int b = matrix[r][c]+rec(matrix,m,r+1,c+1,dp);
     int c2 = matrix[r][c]+rec(matrix,m,r+1,c,dp);
     dp[r][c] = min(a,min(b,c2));
     return (dp[r][c]);
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        for(int x=0;x<n;x++){
            vector<vector<int>>dp(matrix.size()+1,vector<int>(matrix.size()+1,-1));
            int a = rec(matrix,n,0,x,dp);
            ans = min(ans,a);
        }
        return ans;
    }
};
}