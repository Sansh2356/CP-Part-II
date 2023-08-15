#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>
#include <chrono>
using namespace std;

#define ll long long;
#define ull unsigned long long;

void solve()
{
  long long n, k;
  chrono::high_resolution_clock();
  cin >> n >> k;

  int cnt = 0;
  for (int x = 1; x <= n; x++)
  {
    int a = x;
    int g = n;
    bool flag = true;
    for (int j = 0; j < (k - 2); j++)
    {
      int l = a;
      a = g - l;
      g = l;
      if (a > g || a < 0)
      {
        flag = false;
        break;
      }
    }
    if (flag == true)
    {
      cnt++;
    }
  }
  cout << cnt << endl;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
}
