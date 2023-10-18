#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int ans = 0;
        int f = (abs(a^0-(b^0)));
        for(int x=1;x<10e6;x++){
            int c = (abs((a^x)-(b^x)));
            if(c < f){
                f = c;
                ans = x;
            }
        }
        cout<<ans<<endl;
    }
}