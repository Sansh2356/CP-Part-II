#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
void dfs(int root, vector<vector<int>> &adj_mat, vector<int> &path, unordered_map<int, bool> &visited)
{
  if (visited[root] == true)
    return;
  visited[root] = true;

  for (auto node : path)
  {
    cout << node << " ";
  }
  cout << endl;
  for (int x = 0; x < adj_mat[root].size(); x++)
  {
    if (adj_mat[root][x] != -1 && visited[x] != true)
    {
      path.push_back(x);
      dfs(x, adj_mat, path, visited);
      path.pop_back();
    }
  }
}
vector<long long> White_black_tree(int N, string color, vector<vector<int>> Edges)
{
  vector<vector<int>> adj_mat(N, vector<int>(N, -1));
  vector<long long>ans(N,0);
  for (int x = 0; x < Edges.size(); x++)
  {
    int u = Edges[x][0];
    int v = Edges[x][1];
    adj_mat[u - 1][v - 1] = 0;
    adj_mat[v - 1][u - 1] = 0;
  }

  
 
  return ans;
}
bool check(int row, int col, vector<vector<int>> mine)
{

  if (row < 0 || row >= mine.size() || col < 0 || col >= mine[0].size())
    return false;
  return true;
}
long long rec(int row, int col, vector<vector<int>> &mine, int n, int m, vector<vector<int>> &dp)
{
  // base case //
  // cout<<row<<" "<<col<<endl;
  if (col == mine[0].size() - 1)
  {
    // cout<<"BASE CASE"<<endl;
    return mine[row][col];
  }
  if (dp[row][col] != -1)
    return dp[row][col];
  int a, b, c;
  a = 0;
  b = 0;
  c = 0;
  if (check(row, col + 1, mine) == true)
  {
    a = mine[row][col] + rec(row, col + 1, mine, n, m, dp);
  }
  if (check(row - 1, col + 1, mine) == true)
  {
    b = mine[row][col] + rec(row - 1, col + 1, mine, m, n, dp);
  }
  if (check(row + 1, col + 1, mine) == true)
  {
    c = mine[row][col] + rec(row + 1, col + 1, mine, m, n, dp);
  }
  // cout<<a<<" "<<b<<" "<<c<<endl;
  return dp[row][col] = max(a, max(b, c));
}
long long max_gold(int n, int m, vector<vector<int>> mine)
{
  long long ans = INT_MIN;
  vector<vector<int>> dp(n + 1, vector<int>(m, -1));
  for (int x = 0; x < mine.size(); x++)
  {
    int starting_col = x;
    ans = max(ans, rec(x, 0, mine, mine.size(), mine[0].size(), dp));
    // cout << ans << endl;
  }
  return ans;
}
long long rec2(int idx, vector<int> &weight, vector<int> &happiness, vector<int> &cost, int x, int y, int curr_happiness, int curr_wt)
{
  // base case//
  if (curr_happiness >= x)
  {
    return INT_MAX;
  }

  // take and no take;
  int take = INT_MAX;
  int no_take = INT_MAX;
  no_take = rec2(idx + 1, weight, happiness, cost, x, y, curr_happiness, curr_wt);
  if (curr_wt + weight[idx] <= y)
  {
    take = cost[idx] + rec2(idx, weight, happiness, cost, x, y, curr_happiness + happiness[idx], curr_wt + weight[idx]);
  }
  return min(take, no_take);
}
long long shopping_mall(int n, vector<int> happiness, vector<int> weight, vector<int> cost, int x, int y, vector<int> elements)
{
  return rec2(0, weight, happiness, cost, x, y, 0, 0);
}
int main()
{
  White_black_tree(5, "11110", {{3, 1}, {4, 3}, {5, 3}, {2, 4}});
  // cout << max_gold(4, 4, {{10, 33, 13, 15}, {22, 21, 4, 1} ,{5, 0, 2, 3},{0, 6, 14, 2}}) << endl;
  // cout<<shopping_mall()<<endl;
}