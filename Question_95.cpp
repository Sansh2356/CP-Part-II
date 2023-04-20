#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
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
        vector<int>rand = v;
        int val = (n*(n-1))/2;
        sort(rand.begin(),rand.end());
        for(int x=0;x<n;x++){
            int num = rand[x];
            if()
        }

    }
}