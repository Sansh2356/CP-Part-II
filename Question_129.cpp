#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long xa,ya;
        cin>>xa>>ya;
        long long xb,yb,xc,yc;
        cin>>xb>>yb>>xc>>yc;
        int count = 1;
        if(ya == yb && ya == yc){
            if(xa > xb && xa > xc || xa < xb && xa <xc){
                cout<<abs(xa-min(xb,xc))<<endl;
                continue; 
            }
            else if(xa > xb && xa < xc || xa >xc && xa < xb){
                cout<<1<<endl;
                continue;
            }
        }
        if(xa == xb && xa == xc){
            if(ya > yb && ya > yc || ya < yb && ya < yc){
                cout<<abs(ya-min(yb,yc))<<endl;
                continue; 
            }
            else if(ya > yb && ya < yc || ya >yc && ya < yb){
                cout<<1<<endl;
                continue;
            }
        }
        

    }
}