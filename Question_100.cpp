#include<iostream> 

#include<algorithm>

#include<unordered_map>

#include<queue>

#include<numeric>

#include<vector>

using namespace std;
bool is_super_permutation(vector<int>b,int n){
    unordered_map<int,int>m;
    for(int s=0;s<b.size();s++){
        if(m.count(b[s]) == true){
            return false;
        }
        else{
            m[b[s]] = 1;
        }
    }
    if(m.size() == n){
        return true;
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       vector<int>per;
       vector<int>b;
       for(int m=1;m<=n;m++){
        per.push_back(m);
       }
      // cout<<endl;
       b.push_back((per[0]%n));
       for(int k=1;k<n;k++){
        b[k] = ((per[k]%n) + (b[k-1]));
        cout<<b[k]<<" ";
       }
      // cout<<b[0];
       //cout<<endl;
       for(int j=0;j<n;j++){
            b[j] = b[j]+1;
           // cout<<b[j];
        }
       bool ans = is_super_permutation(b,n);
       if(ans == true){
        for(int j=0;j<n;j++){
            //cout<<b[j]<<" ";
        }
        //cout<<endl;
       }
       if(ans == false){
        cout<<-1<<endl;
       }
    }
}