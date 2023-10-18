#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,x;
        cin>>n>>k>>x;
         if(k > n || (k-1) > x)cout<<-1<<endl;
         else{
             int ans = 0;
             ans+=(k*(k+1))/2;
             n-=k;
             ans+=(n*x);
             cout<<ans<<endl;
             continue;
         }
         
    }
}