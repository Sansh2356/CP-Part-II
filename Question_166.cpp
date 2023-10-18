#include <iostream>
using namespace std;

int main() {
   int t;
   cin>>t;
   int b = 0;
   while(t--){
    long long a,b,c;
    cin>>a>>b>>c;
    if(b < a){
        long long rem1=c%b;
        c-=rem1;
        long long a=c/rem1;
        long long rem2=c%a;
        c-=rem2;
        long long b=c/rem2;
        b++;
        long long bun = 2*(a+b);
        long long cheese = (1*a+2*b);

        cout<<"Case #"<<b<<":"<<" "<<b<<endl;
    }
   }
}
