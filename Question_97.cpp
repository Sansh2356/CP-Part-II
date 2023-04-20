#include<iostream>
#include<algorithm>
#define ll long long
#define nl "\n"
#include<vector>
using namespace std;
//Q)Jojo's incredible adventures//
void solve(int tc){
	string s;
	cin >> s;
	ll cnt = 0, n = s.length(), ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '1')
			cnt++;
		else
		{
			ans = max(ans, ((cnt + 1) / 2) * ((cnt + 2) / 2));
			cnt = 0;
		}
	}
	if (cnt == n)
	{
		cout << n * n << nl;
		return;
	}
	ans = max(ans, ((cnt + 1) / 2) * ((cnt + 2) / 2));
	cnt = 0;
	int idx = n - 1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == '1')
			idx = i;
		else
			break;
	}
	rotate(s.begin(), s.begin() + idx, s.end());
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '1')
			cnt++;
		else
		{
			ans = max(ans, ((cnt + 1) / 2) * ((cnt + 2) / 2));
			cnt = 0;
		}
	}
	ans = max(ans, ((cnt + 1) / 2) * ((cnt + 2) / 2));
	cout << ans << nl;
}


int main(){
    int t;
    cin>>t;
   for(int v=1;v<=t;v++){
	solve(v);
   }
}