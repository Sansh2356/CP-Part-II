#include<iostream>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int count = 0;
        bool flag = true;
        if(s[0] == '?'){
            flag = false;
        }
        for(int m = 0;m<s.length();m++){
            char ch = s[m];
            if(ch == '?'){
                count++;
            }
        }
        if(count == 0){
            if(s[0] == '0'){
                cout<<0<<endl;
                continue;
            }
            else{
                cout<<1<<endl;
                continue;
            }
        }
        else{
            long long ans = 0;
            if(flag != true){
                if(count == 1){
                    cout<<9<<endl;
                    continue;
                }
                ans = 9*(count-1)*10;
            }
            else if(flag == true){
                ans = pow(10,count);
            }
            cout<<ans<<endl;
        }
    }
}