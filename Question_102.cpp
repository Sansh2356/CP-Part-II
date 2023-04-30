//Brute force approach for longest possible palindromic substring iterative solution of time complexity O(N^3) and space complexity of O(N)//
using namespace std;
#include<vector>
#include<string>
int main(){
    class Solution {
public:
bool is_palindrome(string s){
    for(int x=0;x<(s.length())/2;x++){
        if(s[x] != s[s.length()-x-1]){
            return false;
        }
    }
    return true;
}
void solve(string str,vector<string>&pal){
    for (int i = 0; i < str.length(); i++) {
        string subStr;
        for (int j = i; j < str.length(); j++) {
            subStr += str[j];
            if(is_palindrome(subStr) == true){
                pal.push_back(subStr);
            }
        }
    }
}
    string longestPalindrome(string s) {
        vector<string>pal;
        solve(s,pal);
        int maxi =INT_MIN;
        int index2 = 0;
        for(int m=0;m<pal.size();m++){
            if((int)pal[m].length() > maxi){
                maxi = pal[m].length(); 
                index2 = m;
            }
        }
        return (pal[index2]);
    }
};
//2nd possible solution using the idea of lcs recursively we are able to use the idea of lcs here because of the 
//reason that it is satisfying the matching algorithm and for the 2nd string which is required in lcs we will use the reverse
//of the given string as the palindromic subsequence will be in both the string and the reverse of it  and will get automatically checked we wont have to
//additionally define the function for checking whether the genrated subsequence is palindrome or not.
class Solution {
public:
int solve(string text1,string text2,int m,int n){
    if(m == 0 || n == 0){
        return 0;
    }
    if(text1[m-1] == text2[n-1]){
        return(1+solve(text1,text2,m-1,n-1));
    }
    return(max(solve(text1,text2,m-1,n),solve(text1,text2,m,n-1)));
}
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(),rev.end());
        int m = rev.length();
        int n = s.length();
        return solve(s,rev,m,n);
    }
};
//3rd possible solution will be the optimization of the first one that is memoization(top-down approach) or tabulation(bottom-up approach)//
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }

                else if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }

                else{dp[i][j]=max(dp[i-1][j],dp[i][j-1]);}
            }
        }
        return dp[n][m];


    }
};

}