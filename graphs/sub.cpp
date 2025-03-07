#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
void rec(vector<vector<int>> &sub, vector<int> &path, unordered_map<int, pair<vector<int>, int>> &m, int n)
{
  if (path.size() == (2 * n - 1))
  {
    sub.push_back(path);
    return;
  }

  for (int x = 1; x <= n; x++)
  {
    if (x == 1 && m[1].second < 1)
    {
      m[1].first.push_back(path.size());
      m[1].second += 1;
      path.push_back(1);
      rec(sub, path, m, n);
      m[1].first.pop_back();
      m[1].second -= 1;
      path.pop_back();
    }
    else if (x != 1)
    {
      if (m[x].second == 0)
      {
        m[x].first.push_back(path.size());
        m[x].second += 1;
        path.push_back(x);
        rec(sub, path, m, n);
        path.pop_back();
        m[x].first.pop_back();
        m[x].second -= 1;
      }
      else if (m[x].second >= 1 && abs(m[x].first[0] - int(path.size())) == x && m[x].second < 2)
      {
        m[x].second += 1;
        m[x].first.push_back(path.size());
        path.push_back(x);
        rec(sub, path, m, n);
        path.pop_back();
        m[x].first.pop_back();
        m[x].second -= 1;
      }
    }
  }
  return;
}
vector<int> constructDistancedSequence(int n)
{
  vector<vector<int>> sub;
  vector<int> path = {};
  unordered_map<int, pair<vector<int>, int>> m;
  rec(sub, path, m, n);
  sort(sub.begin(), sub.end());

  return sub[sub.size() - 1];
}
int countArrays(vector<int> &original, vector<vector<int>> &bounds)
{
}
void solve()
{
  // vector<int>v = constructDistancedSequence(8);
}
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
}