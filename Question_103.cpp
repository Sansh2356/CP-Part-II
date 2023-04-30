#include<iostream>
using namespace std;
#include<vector>
//Solution of Largest common subsequenece(can be discontinuos in nature) by recursive methods hence time complexity is O(2^n) and space is O(n) memory used for maintaing the memeory stack//
int main(){
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
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        return solve(text1,text2,m,n);
    }
};
string s;
}
