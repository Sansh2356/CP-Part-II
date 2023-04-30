#include<iostream>
#include<numeric>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b,c,d;
        cin>>a>>b>>c>>d;
       if(( long double)a/b == (long double)c/d){
        cout<<0<<endl;
        continue;
       }
       if(a == 0 || c == 0){
        cout<<1<<endl;
        continue;
       }
       long long num1 =a*d;
       long long num2 = b*c;
       if(num1 > num2 && (num1%num2 == 0) || num2 > num1 && num2%num1 == 0){
        cout<<1<<endl;
        continue;
       }
       cout<<2<<endl;
       
      
    }
}