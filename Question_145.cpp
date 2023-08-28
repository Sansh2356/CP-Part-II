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
/*
class Solution {
private:
// Tabulation(Accepted)
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        int mani=INT_MAX;
        vector<vector<int>>dp(r,vector<int>(c,0));
            //initialisation
        for(int i=0;i<c;i++){
           dp[0][i] = matrix[0][i];
        }
        //dp code
        for(int row=1;row<r;row++){
            for(int col=0;col<c;col++){
               
                int up=matrix[row][col]+dp[row-1][col];

                int leftD=matrix[row][col];
                if(col-1>=0) leftD+=dp[row-1][col-1];
                else leftD+=1e8;

                int rightD=matrix[row][col];
                if(col+1<c) rightD+=dp[row-1][col+1];
                else rightD+=1e8;
    
                dp[row][col] = min(up,min(leftD,rightD));
            }
        }


        for(int i=0;i<c;i++){
            mani=min(mani,dp[r-1][i]);
        }
        return mani;
    }
};


*/