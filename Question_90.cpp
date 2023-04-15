#include <iostream>
#include<numeric>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       int a, b;
        cin >> a >> b;
        if(a == b && a != 1){
            cout<<2<<endl;
            cout<<3<<" "<<4<<endl;
            cout<<a<<" "<<b<<endl;
            continue;
        }
        else if(a == 1 && b == 1 ){
            cout<<1<<endl;
            cout<<1<<" "<<1<<endl;
            continue;
        }
        bool flag = false;
        if(gcd(a,b) != 1);{
            flag = true;
        }
        
       
        if(flag == false){
            //There will always exist only one point//
            cout<<1<<endl;
            cout<<a<<" "<<b<<endl;
            continue;
        }
        else if(flag == true){
            //There will always exist two points//
            cout<<2<<endl;
            //x = 0//
            cout<<(a-1)<<" "<<1<<endl;
            cout<<a<<" "<<b<<endl;
        }
       
    }
}