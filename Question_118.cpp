#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//Q)Div 2 educational round gaming forces//
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int m=0;m<n;m++){
            cin>>v[m];
        }
        sort(v.begin(),v.end());
        int count = 0;
        int count2 = 0;
        for(int s=0;s<v.size();s++){
            int ele = v[s];
            if(ele > 1){
                break;
            }
            else if(ele == 1){
                count++;
            }
        }
        if(count%2 == 0){
            count2+=(count)/2;
        }
        else if(count%2 != 0){
            count2+=(count-1)/2+1;
        }
        count2+=(v.size()-count);
        cout<<count2<<endl;

    }
}