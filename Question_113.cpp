#include<iostream>
#include<unordered_map>
#include<vector>
#include<set>
using namespace std;
//Codeforces div 2 problem Trus nodbody//
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long>v;
        for(int x=0;x<n;x++){
            long long num;
            cin>>num;
            v.push_back(num);
        
             }
             bool flag = true;
             for(int x=0;x<=n;x++){
                //if liars are greater than actual liars then that person is lying//
                long long act_liars = 0;
                long long possible_liars = x;
                    for(int s=0;s<n;s++){
                        int num = v[s];
                        if(num > x){
                            act_liars++;
                        }
                    }
                    if(act_liars == possible_liars){
                        flag =false;
                        cout<<possible_liars<<endl;
                        break;
                    }
             }
             if(flag == false){
                continue;
             }
             else{
                cout<<-1<<endl;
             }


    }
}