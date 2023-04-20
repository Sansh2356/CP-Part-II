#include<iostream>
using namespace std;
//Q)
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string empty = "";
        bool flag = true;
        int count = 0;
        if(s.length() == 1 && s[0] == '_'){
            cout<<2<<endl;
            continue;
        }
        if(s.length() == 1 && s[0] == '^'){
            cout<<1<<endl;
            continue;
        }
        for(int m=0;m<(s.length());m++){
            char ch = s[m];
           if(ch == '_' && m == 0){
            count++;
           }
           else if(ch == '_' && m!= 0){
             if(m == (s.length()-1) && s[m-1] == '^'){
                count = count+1;
                }
                if(m == (s.length()-1) && s[m-1] != '^' ){
                    count = count + 2;
                }
                if(s[m-1] != '^' && s[m+1] == '^'){
                    count++;
                }
                if(s[m-1] == '^' && s[m+1] != '^'){
                    continue;
                }
                
                if(s[m-1] == '^' && s[m+1] == '^'){
                    continue;
                }
                if(s[m+1] == '_'){
                    count++;
                }
           }
        }
        cout<<count<<endl;
    }
}