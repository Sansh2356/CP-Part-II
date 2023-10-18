#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
bool check(int mid,int h,vector<int>v){
    for(int x=0;x<v.size();x++){
        int a = v[x];
        if(mid >= a)continue;
        else if(mid < a){
            if(h <= a){
                return false;
            }
            else if(h > a){
                h = h-a;
                if(h < 0){
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	 int n,h;
     cin>>n>>h;
     vector<int>v(n);
     for(int x=0;x<n;x++){
        cin>>v[x];
     }
     sort(v.begin(),v.end());
     int e = v[v.size()-1];
     int s = 0;
     int ans = INT_MAX;
     while(s <= e){
        int mid = (s+e)/2;
        if(check(mid,h,v) == true){
            ans = min(ans,mid);
            e = mid-1;
        }
        else{
            s = mid+1;
        }
     }
     cout<<ans<<endl;
	}
	return 0;
}
