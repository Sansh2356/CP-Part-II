#include<iostream>
#include<vector>
using namespace std;
bool is_palindrome(vector<long long>v){
    for(int m=0;m<(v.size()-1)/2;m++){
        if(v[m] != v[v.size()-1-m]){
            return false;
        }
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long>v;
        long long max_val = INT_MIN;
        for(int s=0;s<n;s++){
            long long num;
            cin>>num;
            max_val=max(max_val,num);
            v.push_back(num);
        }
        if(is_palindrome(v) == true){
            cout<<0<<endl;
            continue;
        }
        for(long long x=1;x<=max_val;x++){

        }
    }
}