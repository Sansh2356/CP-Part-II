#include<iostream>
using namespace std;
//Codeforces split it div2 1st//
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s2;
        cin>>s2;
        if(k == 0){
            cout<<"Yes"<<endl;
            continue;
        }
        bool flag = true;
        for(int s=0;s<(n-1)/2;s++){
            if(s2[s] == s2[n-s-1]){
                k--;
            }
            if(s2[s] != s2[n-s-1]){
                break;
            }
        }
        if(k <= 0){
            cout<<"yes"<<endl;
            continue;
        }
        else{
            cout<<"no"<<endl;
        }
    }
}