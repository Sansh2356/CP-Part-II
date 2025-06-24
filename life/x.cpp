#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        for(int x=0;x<arr.size();x++){
            cin>>arr[x];
        }
        sort(arr.begin(),arr.end());
        int ans =0;
        k++;
        while(k--){
            ans+=arr[arr.size()-1];
            arr.pop_back();
        }
        cout<<ans<<endl;
        
    }
}