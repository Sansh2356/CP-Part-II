#include<iostream>
#include<vector>
using namespace std;
int main(){
long long n,m;
vector<long long>v(n);
for(int x=0;x<n;x++){
	cin>>v[x];
}
vector<long long>a(n+1);
vector<long long>b(n+1);
a.push_back(0);
for(int x=1;x<n;x++){
	a[x] = a[x-1] + max((long long)0,abs(v[x]-v[x-1]));
}
b.push_back(0);
for(int j=n-1;j>0;j--){
b[j] = b[j-1]+max((long long)0,abs(v[j]-v[j-1]));
}
while(m--){
	long long s,t;
	cin>>s>>t;
	if(s < t){
		cout<<abs(a[s-1]-a[t-1])<<endl;
	}
	else if(t < s){
		if(t == 1){
			cout<<abs(b[s-1]-b[n-1])<<endl;
		}
		else{
			cout<<abs(b[n-s-1]-b[n-t-1])<<endl;
		}
	}
}
}