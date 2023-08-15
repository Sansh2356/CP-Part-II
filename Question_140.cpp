#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define ll "long long int";
#define nl "/n";
#include <algorithm>
//All possible combinations using backtracking//

void rec(vector<vector<int>> &ans, int n, int k, vector<int> ele, int index)
{
	if (ele.size() == k)
	{
		ans.push_back(ele);
	}
	for (int x = index; x <= n; x++)
	{
		ele.push_back(x + 1);
		rec(ans, n, k, ele, index + 1);
		ele.pop_back();
	}
}
void solve()
{
	int n, k;
	cin >> n >> k;
	int *arr = new int(n);
	vector<vector<int>> ans;
	vector<int> ele;
	rec(ans, n, k, ele, 1);
}

int main()
{
	ios::sync_with_stdio(true);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}