#include <iostream>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <map>
#include <math.h>
#include <thread>
#include <stack>
#include <chrono>
#include <bitset>
#include <queue>
#include <string>
#include <unordered_map>
#include <ctime>
#include <mutex>
#include <cmath>
using namespace std;
#define ll long long
#define MOD 1000000007
// Implementation of sieve of erastothenes for finding prime numbers upto
// nth number range in O(log(log(N))) time complexity
void seive_of_erasthothenes()
{
  int n;
  // Initialization of seieve for keeping track of prime
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++)
  {
    if (is_prime[i] && (long long)i * i <= n)
    {
      for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;
    }
  }
}
int tree[100];
// Segment Tree implementation //
// dividing the complete query range in the form power of 2^1 hence making the complete binary tree //
// if the length is not a power of 2 we will add padding to make it a neareast power of 2//
// Since the length of segment tree is 2*n-1 where n is the number of array elements and hence the building
// time for segment tree comes out to be O(n)
int seg(int node, int query_left, int query_right, int node_low, int node_high)
{
  // check whether the current node interval lies completely within the query interval //
  if (query_left <= node_low && query_right >= node_high)
  {
    return node;
  }
  // check whether the current node interval lies completely outside the query interval //
  if (query_right < node_low || query_left > node_high)
  {
    return 0;
  }
  // check whether the current node interval lies partially within the query interval //
  // dividing each of the nodes and alloting them theri seperate intervals//
  int node_last_val = (node_high + node_low) / 2;
  return seg(2 * node, query_left, query_right, node_low, node_last_val) + seg(2 * node + 1, query_left, query_right, node_last_val + 1, node_high);
}
// Iterative updation in segment tree//
void update(int val, int n, int i)
{
  tree[n + i] = val;
  for (int x = (n + i) / 2; x >= 1; x /= 2)
  {
    tree[x / 2] = tree[2 * x] + tree[2 * x + 1];
  }
}
// Recursive updation in segment tree//
void change(int node, int node_high, int node_low, int v, int query_high, int query_low)
{
  if (query_low >= node_low && query_high <= node_high)
  {
    // It will happen only in the case of leaf node only hence set the leaf to updated value//
    tree[node] = v;
    return;
  }
  if (query_high < node_low || query_low > node_high)
  {
    return;
  }
  int node_last_val = (node_high + node_low) / 2;
  // move left child //
  change(2 * node, node_low, node_last_val, v, query_high, query_low);
  // move right child//
  change(2 * node + 1, node_last_val + 1, node_high, v, query_high, query_low);
  // update the nodes values along the ancestors path until root//
  tree[node] = tree[2 * node] + tree[2 * node + 1];
  return;
}
class TreeNode
{
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val)
  {
    this->val = val;
    this->left = nullptr;
    this->right = nullptr;
  }
};
class Solution
{
public:
  // bool check(int row, int col, int rowsize, int colsize)
  // {
  //   if (row >= rowsize || col >= colsize || row < 0 || col < 0)
  //   {
  //     return false;
  //   }
  //   return true;
  // }
  void bfs(int row, int col, set<pair<int, int>> &visited,
           vector<vector<char>> &grid)
  {
    queue<pair<int, int>> q;
    q.push({row, col});
    visited.insert({row, col});
    while (q.empty() != true)
    {
      pair<int, int> p = q.front();
      q.pop();
      pair<int, int> v1, v2, v3, v4;
      v1 = {p.first + 1, p.second};
      v2 = {p.first - 1, p.second};
      v3 = {p.first, p.second + 1};
      v4 = {p.first, p.second - 1};
      if (check(v1.first, v1.second, grid.size(), grid[0].size()) ==
              true &&
          grid[v1.first][v1.second] == '1' &&
          visited.find({v1.first, v1.second}) == visited.end())
      {
        q.push({v1.first, v1.second});
        visited.insert({v1.first, v1.second});
      }
      if (check(v2.first, v2.second, grid.size(), grid[0].size()) ==
              true &&
          grid[v2.first][v2.second] == '1' &&
          visited.find({v2.first, v2.second}) == visited.end())
      {
        q.push({v2.first, v2.second});
        visited.insert({v2.first, v2.second});
      }
      if (check(v3.first, v3.second, grid.size(), grid[0].size()) ==
              true &&
          grid[v3.first][v3.second] == '1' &&
          visited.find({v3.first, v3.second}) == visited.end())
      {
        q.push({v3.first, v3.second});
        visited.insert({v3.first, v3.second});
      }
      if (check(v4.first, v4.second, grid.size(), grid[0].size()) ==
              true &&
          grid[v4.first][v4.second] == '1' &&
          visited.find({v4.first, v4.second}) == visited.end())
      {
        q.push({v4.first, v4.second});
        visited.insert({v4.first, v4.second});
      }
    }
  }
  int numIslands(vector<vector<char>> &grid)
  {
    set<pair<int, int>> visited;
    int cnt = 0;
    for (int x = 0; x < grid.size(); x++)
    {
      for (int y = 0; y < grid[0].size(); y++)
      {
        if ((visited.find({x, y}) != visited.end() &&
             grid[x][y] == '1') ||
            (grid[x][y] == '0'))
        {
          continue;
        }
        else
        {
          bfs(x, y, visited, grid);
          cnt += 1;
        }
      }
    }
    return cnt;
  }
  int minimumOperations(TreeNode *root)
  {
    return 1;
  }
  vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
  {
    sort(items.begin(), items.end());
    vector<int> pf_max(items.size(), 0);
    vector<int> ans;
    pf_max[0] = items[0][1];
    for (int x = 1; x < items.size(); x++)
    {
      int beauty = items[x][1];
      pf_max[x] = max(pf_max[x - 1], beauty);
    }

    for (auto query : queries)
    {
      long long s = 0;
      long long e = items.size();
      long long mid = -1;
      int idx = -1;
      while (s <= e)
      {
        mid = (s + e) / 2;
        if (items[mid][0] <= query)
        {
          idx = mid;
          s = mid + 1;
        }
        else
        {
          e = mid - 1;
        }
      }
      int mid_idx = idx;
      int maxm_beauty = pf_max[mid_idx];
      ans.push_back(maxm_beauty);
    }
    return ans;
  }
  int largestCombination(vector<int> &candidates)
  {
    priority_queue<int> pq;
    for (int x = 1; x <= 32; x++)
    {
      int cnt = 0;
      for (auto candidate : candidates)
      {
        if ((candidate & (1 << x)) == 1)
        {
          cnt += 1;
        }
      }
      pq.push(cnt);
    }
    return pq.top();
  }
  vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
  {
    vector<int> ans;
    vector<int> pf(nums.size(), 0);
    pf[0] = nums[0];
    for (int x = 1; x < nums.size(); x++)
    {
      pf[x] = pf[x - 1] ^ nums[x];
    }
    for (int x = 0; x < nums.size(); x++)
    {
      int prefix_xor = pf[nums.size() - 1 - x];
      ans.push_back((prefix_xor ^ ((1 << maximumBit) - 1)));
    }
    return ans;
  }
  bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
  {
    unordered_map<int, vector<int>> adj_list;
    for (int x = 0; x <= n; x++)
    {
      adj_list[x] = {};
    }
    for (int x = 0; x < edges.size(); x++)
    {
      adj_list[edges[x][0]].push_back(edges[x][1]);
      adj_list[edges[x][1]].push_back(edges[x][0]);
    }
    queue<int> q;
    q.push(source);
    unordered_map<int, bool> visited;
    visited[source] = true;
    while (q.empty() != true)
    {
      int frontNode = q.front();
      if (frontNode == destination)
      {
        return true;
      }
      q.pop();
      for (auto neighbours : adj_list[frontNode])
      {
        if (visited[neighbours] != true)
        {
          visited[neighbours] = true;
          q.push(neighbours);
        }
      }
    }
    return false;
  }
  long long minEnd(int n, int x)
  {
    return 10e7;
  }
  int minimumSize(vector<int> &nums, int maxOperations)
  {
    return -1;
  }
  string repeatLimitedString(string s, int repeatLimit)
  {

    unordered_map<char, int> m;
    for (int x = 0; x < s.length(); x++)
    {
      m[s[x]] += 1;
    }
    vector<char> chars;
    for (auto it : m)
    {
      chars.push_back(it.first);
    }
    sort(chars.begin(), chars.end());
    reverse(chars.begin(), chars.end());
    string ans = "";
    for (int x = 0; x < chars.size(); x++)
    {
      int freq = m[chars[x]];
      if (freq <= repeatLimit)
      {
        for (int z = 0; z < freq; z++)
        {
          ans.push_back(chars[x]);
        }
      }
      else if (freq > repeatLimit)
      {
        int cnt = 0;
        while (cnt < repeatLimit)
        {
          cnt += 1;
          ans.push_back(chars[x]);
          m[chars[x]] -= 1;
        }
        bool flag = true;
        int idx = -1;
        for (int y = x + 1; y < chars.size(); y++)
        {
          if (m[chars[y]] > 0)
          {
            flag = false;
            idx = y;
            break;
          }
        }
        if (flag == true)
        {
          break;
        }
        else if (flag == false)
        {
          ans.push_back(chars[idx]);
          m[chars[idx]] -= 1;
          x -= 1;
        }
      }
    }
    return ans;
  }
  vector<int> finalPrices(vector<int> &prices)
  {
    vector<int> ans;
    for (int x = 0; x < prices.size(); x++)
    {
      int idx = x;
      for (int y = (x + 1); y < prices.size(); y++)
      {
        if (prices[y] <= prices[x])
        {
          idx = y;
          break;
        }
      }
      ans.push_back(prices[x] - prices[idx]);
    }
    return ans;
  }
  int buttonWithLongestTime(vector<vector<int>> &events)
  {
    pair<int, int> p = {events[0][0], events[0][1]};
    int curr = 0;
    int prev = 0;
    for (int x = 1; x < events.size(); x++)
    {
      curr = x;
      int dist = abs(events[prev][1] - events[curr][1]);
      prev = curr;
      if (p.second < dist)
      {
        p.first = events[curr][0];
        p.second = dist;
      }
      else if (p.second == dist)
      {
        p.first = min(p.first, events[curr][0]);
      }
    }
    return p.first;
  }
  unordered_map<double, pair<double, double>> construct_adj_list(vector<vector<double>> &edges)
  {
    unordered_map<double, pair<double, double>> adj_list;
    for (int x = 0; x < edges.size(); x++)
    {
      adj_list[edges[x][0]] = {edges[x][1], edges[x][2]};
    }
    return adj_list;
  }
  double solve_max_amount(unordered_map<double, pair<double, double>> &adj_list)
  {
    return 0.0;
  }
  double maxAmount(string initialCurrency, vector<vector<string>> &pairs1, vector<double> &rates1, vector<vector<string>> &pairs2, vector<double> &rates2)
  {
    unordered_map<string, double> m;
    double node_val = 0;
    m[initialCurrency] = node_val;
    node_val += 1;
    for (int x = 0; x < pairs1.size(); x++)
    {
      string parent_node = pairs1[x][0];
      string child_node = pairs1[x][1];
      if (m.count(parent_node) != true)
      {
        m[parent_node] = node_val;
        node_val += 1.0;
      }
      if (m.count(parent_node) != true)
      {
        m[child_node] = node_val;
        node_val += 1.0;
      }
    }
    vector<vector<double>> edges;
    for (int x = 0; x < pairs1.size(); x++)
    {
      vector<double> edge;
      vector<double> edge2;
      edge.push_back(m[pairs1[x][0]]);
      edge.push_back(m[pairs1[x][1]]);
      edge.push_back(rates1[x]);
      edge2.push_back(m[pairs1[x][1]]);
      edge2.push_back(m[pairs1[x][0]]);
      edge2.push_back(1 / rates1[x]);
      edges.push_back(edge);
      edges.push_back(edge2);
    }
    for (int x = 0; x < pairs2.size(); x++)
    {
      vector<double> edge;
      vector<double> edge2;

      edge.push_back(m[pairs2[x][0]]);
      edge.push_back(m[pairs2[x][1]]);
      edge.push_back(rates2[x]);
      edge2.push_back(m[pairs2[x][2]]);
      edge2.push_back(m[pairs2[x][0]]);
      edge2.push_back(1 / rates2[x]);
      edges.push_back(edge);
      edges.push_back(edge2);
    }
    unordered_map<double, pair<double, double>> adj_list = construct_adj_list(edges);
    return solve_max_amount(adj_list);
  }
  int maxChunksToSorted(vector<int> &arr)
  {
    int ans = 0;
    int prefix_sum = 0;
    int sum_of_natural = 0;

    for (int x = 0; x < arr.size(); x++)
    {
      sum_of_natural += x;
      prefix_sum += arr[x];
      if (sum_of_natural == prefix_sum)
        ans++;
    }
    return ans;
  }
  void level_order(TreeNode *&root)
  {
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    stack<int> st;
    int level = 0;
    while (!q.empty())
    {
      TreeNode *temp = q.front();
      q.pop();
      if (temp == NULL)
      {
        level++;
        if (!q.empty())
        {
          q.push(NULL);
        }
      }
      else
      {
        if (temp->left && level % 2 == 0)
        {
          q.push(temp->left);
          st.push(temp->left->val);
        }
        if (temp->right && level % 2 == 0)
        {
          q.push(temp->right);
          st.push(temp->right->val);
        }
        if (temp->left && level % 2 != 0)
        {
          q.push(temp->left);
        }
        if (temp->right && level % 2 != 0)
        {
          q.push(temp->right);
        }
        if (level % 2 != 0)
        {
          temp->val = st.top();
          st.pop();
        }
      }
    }
  }
  TreeNode *reverseOddLevels(TreeNode *root)
  {
    level_order(root);
    return root;
  }
  int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                              vector<int> &values, int k)
  {
    int components = 0;
    if (n <= 1)
      return 1;
    queue<int> q;
    vector<long long> val;
    for (auto i : values)
    {
      val.push_back(i);
    }

    unordered_map<int, set<int>> adj_list;
    for (int x = 0; x < edges.size(); x++)
    {
      int vertex_1 = edges[x][0];
      int vertex_2 = edges[x][1];
      adj_list[vertex_1].insert(vertex_2);
      adj_list[vertex_2].insert(vertex_1);
    }
    for (auto i : adj_list)
    {
      if (i.second.size() == 1)
        q.push(i.first);
    }
    while (q.empty() != true)
    {
      int frontNode = q.front();
      q.pop();
      int neighborNode = -1;
      if (!adj_list[frontNode].empty())
      {
        neighborNode = *adj_list[frontNode].begin();
      }
      if (neighborNode >= 0)
      {
        adj_list[neighborNode].erase(frontNode);
        adj_list[frontNode].erase(neighborNode);
      }
      if (val[frontNode] % k == 0)
      {
        components++;
      }
      else
      {
        val[neighborNode] += val[frontNode];
      }
      if (adj_list[neighborNode].size() == 1)
      {
        q.push(neighborNode);
      }
    }
    return components;
  }
  int barclays_2()
  {
    vector<int> idEList;
    vector<int> effList;
    vector<vector<int>> empQuit;
    vector<int> answer;
    // Write your code here
    // numdays and nume s
    unordered_map<int, int> m;
    vector<pair<int, int>> v;
    long long total_eff = 0;
    for (int x = 0; x < effList.size(); x++)
    {
      int eff = effList[x];
      int id = idEList[x];
      m[id] = eff;
      pair<int, int> p = {eff, id};
      v.push_back(p);
      total_eff += eff;
    }
    sort(v.begin(), v.end());
    long long sub = 0;
    int st = 0;
    for (int x = 0; x < empQuit.size(); x++)
    {
      int emp_id = empQuit[x][0];
      int k_emp = empQuit[1][1];
      total_eff -= m[emp_id];
      for (int y = st; y < k_emp; y++)
      {
        if (v[y].second == emp_id)
          continue;
        else
        {
          sub += v[y].first;
        }
      }
      st += k_emp;
      total_eff -= sub;
      answer.push_back(total_eff);
    }
    return answer[1];
  }
  bool check(int m, int n, int row, int col)
  {
    if (row < m && col < n)
    {
      return true;
    }
    return false;
  }
  int rec(int row, int col, vector<vector<int>> &grid, int k, int xor_val,
          int m, int n, vector<vector<vector<int>>> &dp)
  {
    // base case//
    if (row == (m - 1) && col == (n - 1))
    {
      return xor_val == k ? 1 : 0;
    }
    if (dp[row][col][xor_val] != -1)
    {
      return dp[row][col][xor_val];
    }
    int a = 0;
    int b = 0;

    if (check(m, n, row, col + 1) == true)
    {

      a = rec(row, col + 1, grid, k, (xor_val ^ grid[row][col + 1]), m, n,
              dp) %
          MOD;
    }

    if (check(m, n, row + 1, col) == true)
    {
      b = rec(row + 1, col, grid, k, (xor_val ^ grid[row + 1][col]), m, n,
              dp) %
          MOD;
    }
    dp[row][col][xor_val] = (a + b) % MOD;
    return dp[row][col][xor_val];
  }
  int countPathsWithXorValue(vector<vector<int>> &grid, int k)
  {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<int>>> dp(
        m, vector<vector<int>>(n, vector<int>(20, -1)));
    return rec(0, 0, grid, k, grid[0][0], m, n, dp);
  }
  int subarraySum(vector<int> &nums, int k)
  {
    ///-------------------------O(N^2)--------------------//
    // vector<int> prefix(nums.size(), 0);
    // prefix[0] = nums[0];
    // for (int x = 1; x < nums.size(); x++)
    // {
    //   prefix[x] = prefix[x - 1] + nums[x];
    // }
    // int cnt = 0;
    // for (int x = 0; x < prefix.size(); x++)
    // {
    //   for (int y = x + 1; y < prefix.size(); y++)
    //   {
    //     int sub_array_sum = prefix[y] - prefix[x];
    //     if (sub_array_sum == k)
    //       cnt++;
    //   }
    // }
    // for (auto i : prefix)
    // {
    //   if (i == k)
    //     cnt++;
    // }
    //----------------------------O(N)---------------------------//
    int cnt = 0;
    unordered_map<int, int> m;
    int cum_sum = 0;
    m[cum_sum] = 1;
    for (int x = 0; x < nums.size(); x++)
    {
      cum_sum += nums[x];
      if (m.count((cum_sum - k)) == true)
        cnt += m[(cum_sum - k)];
      m[cum_sum] += 1;
    }
    return cnt;
  }
  int subarraysDivByK(vector<int> &nums, int k)
  {
    int n = nums.size();
    int prefixMod = 0, result = 0;

    // There are k mod groups 0...k-1.
    vector<int> modGroups(k);
    modGroups[0] = 1;

    for (int num : nums)
    {
      // Take modulo twice to avoid negative remainders.
      prefixMod = (prefixMod + num % k + k) % k;
      // Add the count of subarrays that have the same remainder as the current
      // one to cancel out the remainders.
      result += modGroups[prefixMod];
      modGroups[prefixMod]++;
    }

    return result;
  }
  int numSubarrayProductLessThanK(vector<int> &nums, int k)
  {
    int s = 0;
    int e = 0;
    int cnt = 0;
    int prod = 1;
    while (s <= e && e < nums.size())
    {
      if (nums[e] * prod < k)
      {
        cnt++;
        prod *= nums[e];
        e++;
        if (e >= nums.size())
        {
          s++;
          e = s;
          prod = 1;
        }
      }
      else if (nums[e] * prod >= k)
      {
        prod = 1;
        s++;
        e = s;
      }
    }
    return cnt;
  }
  int lengthOfLongestSubstring(string s)
  {
    int start = 0;
    int end = 0;
    string sub = "";
    int cnt = 0;
    unordered_map<char, int> m;
    while (start <= end && end < s.length())
    {
      m[s[end]] += 1;
      sub.push_back(s[end]);
      if (m[s[end]] > 1)
      {
        cnt = max(cnt, (end - start));
        unordered_map<char, int> m2;
        m = m2;
        sub = "";
        start++;
        end = start;
      }
      else if (m[s[end]] <= 1)
      {
        end++;
        if (end >= s.length())
        {
          cnt = max(cnt, (end - start));
          unordered_map<char, int> m2;
          m = m2;
          sub = "";
          start++;
          end = start;
        }
      }
    }
    return cnt;
  }
  vector<string> findRepeatedDnaSequences(string s)
  {
    return {};
  }
  int characterReplacement(string s, int k)
  {
    int ans = 0;
    int start = 0;
    int end = 0;
    int max_freq = 0;
    unordered_map<char, int> m;
    while (start <= end && end < s.length())
    {
      m[s[end]]++;
      max_freq = max(max_freq, m[s[end]]);
      if (((end - start + 1) - max_freq) > k)
      {
        // false condition//
        while (((end - start + 1) - max_freq) > k)
        {
          m[s[start]] -= 1;
          start++;
        }
      }
      ans = max(ans, (end - start));
      end++;
    }
    return ans + 1;
  }
  vector<int> findAnagrams(string s, string p)
  {
    vector<int> freq_p(26), freq_s(26);
    for (auto it : p)
      freq_p[it - 'a']++;

    int low = 0;
    vector<int> res;
    for (int high = 0; high < s.size(); high++)
    {
      freq_s[s[high] - 'a']++;
      if ((high - low + 1 == p.size()) && (freq_p == freq_s))
        res.push_back(low);

      if (high - low + 1 >= p.size())
      {
        freq_s[s[low] - 'a']--;
        low++;
      }
    }
    return res;
  }
  bool checkInclusion(string s1, string s2)
  {
    vector<int> freq_p(26), freq_s(26);
    for (auto it : s1)
      freq_p[it - 'a']++;

    int low = 0;
    vector<int> res;
    for (int high = 0; high < s2.size(); high++)
    {
      freq_s[s2[high] - 'a']++;
      if ((high - low + 1 == s1.size()) && (freq_p == freq_s))
        res.push_back(low);

      if (high - low + 1 >= s1.size())
      {
        freq_s[s2[low] - 'a']--;
        low++;
      }
    }
    return res.size() >= 1 ? true : false;
  }
  vector<int> findClosestElements(vector<int> &arr, int k, int x)
  {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    vector<int> ans;
    for (int f = 0; f < arr.size(); f++)
    {
      pq.push({abs(arr[f] - x), f});
    }
    while (pq.empty() != true && k > 0)
    {
      ans.push_back(arr[pq.top().second]);
      pq.pop();
      k--;
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
  int findLength(vector<int> &nums1, vector<int> &nums2)
  {
    int ans = 0;
    vector<vector<int>> dp(nums1.size() + 1,
                           vector<int>(nums2.size() + 1, 0));

    for (int x = nums1.size() - 1; x >= 0; x--)
    {
      for (int y = nums2.size() - 1; y >= 0; y--)
      {
        if (nums1[x] == nums2[y])
        {
          dp[x][y] = dp[x + 1][y + 1] + 1;
          ans = max(ans, dp[x][y]);
        }
      }
    }
    // for(auto i:dp){
    //     for(auto f : i){
    //         cout<<f<<" ";
    //     }
    //     cout<<endl;
    // }
    return ans;
  }
  // int rec(vector<int> &nums, int target, int index, int curr_val)
  // {
  //   // Base Case//
  //   if (index >= nums.size())
  //   {
  //     if (curr_val == target)
  //       return 1;
  //     return 0;
  //   }
  //   // Choose either of + or - //
  //   int a, b;
  //   a = 0;
  //   b = 0;
  //   a = rec(nums, target, index + 1, curr_val + nums[index]);
  //   b = rec(nums, target, index + 1, curr_val - nums[index]);
  //   return a + b;
  // }
  // int findTargetSumWays(vector<int> &nums, int target)
  // {
  //   return rec(nums, target, 0, 0);
  // }
  // double rec(int n, int k, vector<int> maxPts, int idx, double prob, int curr_val)
  // {
  //   if (idx >= maxPts.size())
  //   {
  //     if (curr_val >= n)
  //     {
  //       return 0.0;
  //     }
  //     if (curr_val >= k)
  //     {
  //       return 1.0;
  //     }
  //   }
  //   // according to TPT total probability theorem all the probabilities have to be summed up for all
  //   // possible cases//
  //   double sum = 0.0;
  //   sum += (prob * (rec(n, k, maxPts, idx + 1, prob, curr_val + maxPts[idx])));
  //   return sum;
  // }
  // double new21Game(int n, int k, int maxPts)
  // {
  //   vector<int> mx_pts;
  //   for (int x = 1; x <= maxPts; x++)
  //   {
  //     mx_pts.push_back(x);
  //   }
  //   // probability of drawing out any number from
  //   // the available interval
  //   double prob = (double)1 / (double)maxPts;
  //   cout << prob << endl;
  //   return rec(n, k, mx_pts, 0, prob, 0);
  // }
  int longestOnes(vector<int> &nums, int k)
  {
    int s = 0;
    int e = 0;
    int count = 0;
    int ans = 0;
    while (e < nums.size())
    {
      if (nums[e] == 1)
      {
        e++;
        count++;
      }
      else if (k > 0)
      {
        k--;
        e++;
        count++;
      }
      else
      {
        if (nums[s] == 0)
        {
          k++;
        }
        count--;
        s++;
      }
      ans = max(ans, count);
    }
    return ans;
  }
  int numberOfSubarrays(vector<int> &nums, int k)
  {
    int cnt = 0;
    unordered_map<int, int> m;
    int curr_sum = 0;
    m[curr_sum] = 1;
    for (int x = 0; x < nums.size(); x++)
    {
      curr_sum += nums[x] % 2;
      if (m.find(curr_sum - k) != m.end())
      {
        cnt += m[curr_sum - k];
      }
      m[curr_sum] += 1;
    }
    return cnt;
  }
  string answerString(string word, int numFriends)
  {
    vector<int> v;
    unordered_set<char> st;
    if (numFriends == 1)
      return word;
    for (auto i : word)
      st.insert(i);
    auto it = st.begin();
    while (it != st.end())
    {
      v.push_back(*(it));
      it++;
    }
    sort(v.begin(), v.end());
    char largest = v[v.size() - 1];
    string ans = "";
    vector<string> v2;
    for (int x = 0; x < word.size(); x++)
    {
      ans = "";
      if (word[x] == largest)
      {
        ans.push_back(word[x]);
        for (int y = x + 1; y < word.size(); y++)
        {
          if (word.size() - ans.size() - 1 >= numFriends - 1)
          {
            ans.push_back(word[y]);
          }
        }
        v2.push_back(ans);
      }
    }
    sort(v2.begin(), v2.end());
    return v2[v2.size() - 1];
  }
  long long numberOfSubsequences(vector<int> &nums)
  {
    return 1;
  }
  int maxScoreSightseeingPair(vector<int> &values)
  {
    int ans = INT_MIN;
    vector<int> prefix_max(values.size(), 0);
    vector<int> temp;
    for (int x = values.size() - 1; x >= 0; x--)
    {
      temp.push_back(values[x]);
    }
    prefix_max[0] = temp[0] - (values.size() - 1);
    for (int x = 1; x < temp.size(); x++)
    {
      prefix_max[x] = max(prefix_max[x - 1], int(temp[x] - (values.size() - x - 1)));
    }
    reverse(prefix_max.begin(), prefix_max.end());
    for (int x = 0; x < values.size() && x + 1 < values.size(); x++)
    {
      int maxi = prefix_max[x + 1];
      ans = max(ans, ((values[x] + x) + maxi));
    }
    return ans;
  }
  int rec(vector<int> &days, vector<int> &costs, int i, unordered_set<int> &visited, vector<int> &dp)
  {
    // base case //
    if (i > days[days.size() - 1])
    {
      return 0;
    }
    if (visited.find(i) == visited.end())
    {
      return rec(days, costs, i + 1, visited, dp);
    }
    if (dp[i] != -1)
    {
      return dp[i];
    }
    int a = costs[0] + rec(days, costs, i + 1, visited, dp);
    int b = costs[1] + rec(days, costs, i + 7, visited, dp);
    int c = costs[2] + rec(days, costs, i + 30, visited, dp);
    return dp[i] = min(a, min(b, c));
  }
  int mincostTickets(vector<int> &days, vector<int> &costs)
  {
    unordered_set<int> visited;
    vector<int> dp(1000, -1);
    for (auto it : days)
    {
      visited.insert(it);
    }
    return rec(days, costs, 1, visited, dp);
  }
  int rec(int len, int zero, int one, int curr_len, vector<int> &dp)
  {
    if (curr_len > len)
    {
      return 0;
    }
    if (curr_len == len)
    {
      return 1;
    }
    if (dp[curr_len] != -1)
    {
      return dp[curr_len];
    }
    int a = rec(len, zero, one, curr_len + zero, dp);
    int b = rec(len, zero, one, curr_len + one, dp);
    return dp[curr_len] = a + b;
  }
  int countGoodStrings(int low, int high, int zero, int one)
  {
    int ans = 0;

    for (int x = low; x <= high; x++)
    {
      vector<int> dp(high + 1, -1);
      ans += rec(x, zero, one, 0, dp);
    }
    return ans;
  }
  // Revise new type //
  double new21Game(int n, int k, int maxPts)
  {
    if (k == 0)
      return 1;

    vector<double> dp(k);

    n = min(n, k + maxPts - 1);

    double sum = n - k + 1;
    dp[k - 1] = sum / maxPts;

    for (int step = k - 2; step >= 0; step--)
    {
      sum += dp[step + 1];

      if (step + maxPts + 1 > n)
        ;
      else if (step + maxPts + 1 >= k)
        sum -= 1;
      else
        sum -= dp[step + maxPts + 1];

      dp[step] = sum / maxPts;
    }

    return dp[0];
  }
  int minimumSumSubarray(vector<int> &nums, int l, int r)
  {
    int ans = INT_MAX;
    for (int x = 0; x < nums.size(); x++)
    {
      vector<int> v;
      v.push_back(nums[x]);
      if (1 >= l && 1 <= r)
      {
        if (v[0] > 0)
          ans = min(ans, v[0]);
      }
      for (int y = x + 1; y < nums.size(); y++)
      {
        v.push_back(nums[y]);
        if (v.size() >= l && v.size() <= r)
        {
          int sum = 0;
          for (auto it : v)
          {
            sum += it;
          }
          if (sum > 0)
            ans = min(ans, sum);
        }
      }
    }

    return ans == INT_MAX ? -1 : ans;
  }
  int minSubArrayLen(int target, vector<int> &nums)
  {
    int ans = INT_MAX;
    int s = 0;
    int window_sum = 0;
    for (int e = 0; e < nums.size(); e++)
    {
      window_sum += nums[e];

      while (window_sum >= target)
      {
        ans = min(ans, (e - s));
        window_sum -= nums[s];
        s++;
      }
    }
    return ans == INT_MAX ? 0 : ans + 1;
  }
  int maxSubarrayLength(vector<int> &nums, int k)
  {
    unordered_map<int, int> m;
    int s = -1;
    int ans = 0;
    for (int e = 0; e < nums.size(); e++)
    {
      m[nums[e]] += 1;
      while (m[nums[e]] > k)
      {
        s++;
        m[nums[s]] -= 1;
      }
      ans = max(ans, (e - s));
    }
    return ans;
  }
  // pattern for different condition checking in sliding window //
  long long countSubarrays(vector<int> &nums, int k)
  {
    unordered_map<long long, long long> m;
    long long ans = 0;
    for (auto i : nums)
    {
      m[i] += 1;
    }
    long long maxi_ele = INT_MIN;
    for (auto it : m)
    {
      maxi_ele = max(maxi_ele, it.first);
    }
    int s = 0;
    int cnt = 0;
    for (int e = 0; e < nums.size(); e++)
    {
      if (nums[e] == maxi_ele)
        cnt++;
      while (cnt == k)
      {
        if (nums[s] == maxi_ele)
          cnt--;
        s++;
      }
      ans += s;
    }

    return ans;
  }
  vector<int> vowelStrings(vector<string> &words,
                           vector<vector<int>> &queries)
  {
    vector<int> ans;
    vector<int> indices;
    set<char> st;
    st.insert('a');
    st.insert('e');
    st.insert('i');
    st.insert('o');
    st.insert('u');

    for (int x = 0; x < words.size(); x++)
    {
      if (st.count(words[x][0]) == true &&
          st.count(words[x][words[x].size() - 1]) == true)
      {
        indices.push_back(x);
      }
    }
    for (int x = 0; x < queries.size(); x++)
    {
      int l = queries[x][0];
      int r = queries[x][1];
      int mini_idx = -1;
      int maxi_idx = -1;

      int s = 0;
      int e = indices.size() - 1;
      while (s <= e)
      {
        int mid = s + (e - s) / 2;
        if (indices[mid] <= r)
        {
          maxi_idx = mid;
          s = mid + 1;
        }
        else
        {
          e = mid - 1;
        }
      }

      s = 0;
      e = indices.size() - 1;
      while (s <= e)
      {
        int mid = s + (e - s) / 2;
        if (indices[mid] >= l)
        {
          mini_idx = mid;
          e = mid - 1;
        }
        else
        {
          s = mid + 1;
        }
      }

      if (mini_idx != -1 && maxi_idx != -1 && mini_idx <= maxi_idx)
      {
        ans.push_back((maxi_idx - mini_idx) + 1);
      }
      else
      {
        ans.push_back(0);
      }
    }
    return ans;
  }
  // Nice question involving bit manipulation and sliding window //
  //  Revise again //
  int minimumSubarrayLength(vector<int> &nums, int target)
  {
    long Or = 0;
    vector<int> bits(32);
    int ans = INT_MAX, left = 0, right = 0, n = nums.size();
    while (right < n)
    {
      Or |= nums[right];
      bitset<32> Bit(nums[right++]);
      for (int i = 0; i < 32; i++)
        bits[i] += Bit[i];

      while (left < right && Or >= target)
      {
        ans = min(ans, right - left);

        string num;
        bitset<32> Bit(nums[left++]);
        for (int i = 31; i >= 0; i--)
        {
          bits[i] -= Bit[i];
          num += bits[i] ? '1' : '0';
        }
        Or = stoi(num, NULL, 2);
      }
    }
    return ans == INT_MAX ? -1 : ans;
  }
  int waysToSplitArray(vector<int> &nums)
  {
    if (nums.size() <= 1)
      return 0;
    vector<long long> prefix_sum(nums.size(), 0);
    prefix_sum[0] = nums[0];
    for (int x = 1; x < nums.size(); x++)
    {
      prefix_sum[x] = prefix_sum[x - 1] + nums[x];
    }
    long long cnt = 0;
    for (int x = 0; x < nums.size() && (x + 1) < nums.size(); x++)
    {
      long long rem_sum = prefix_sum[x];
      long long total_sum = (prefix_sum[prefix_sum.size() - 1] - rem_sum);
      if (rem_sum >= total_sum)
        cnt++;
    }
    return cnt;
  }
  void transpose(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
  void rotate(vector<vector<int>> &matrix)
  {
    transpose(matrix);
    for (int x = 0; x < matrix.size(); x++)
    {
      reverse(matrix[x].begin(), matrix[x].end());
    }
  }
  bool rec(TreeNode *root, int targetSum, int curr)
  {
    if (root == NULL)
    {
      return false;
    }
    if (root->left == NULL && root->right == NULL)
    {
      if ((curr + root->val) == targetSum)
        return true;
      return false;
    }
    bool a = rec(root->left, targetSum, curr + root->val);
    bool b = rec(root->right, targetSum, curr + root->val);
    return a | b;
  }
  bool hasPathSum(TreeNode *root, int targetSum)
  {
    return rec(root, targetSum, 0);
  }
  TreeNode *inorder(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &m)
  {
    if (root == NULL)
    {
      return NULL;
    }
    TreeNode *left_child = inorder(root->left, m);
    TreeNode *right_child = inorder(root->right, m);
    m[left_child] = root;
    m[right_child] = root;

    return root;
  }
  void path_retrace(unordered_map<TreeNode *, TreeNode *> &m, TreeNode *node,
                    vector<int> &curr_arr)
  {
    // Base case after reaching the root node //
    if (m.count(node) == false && node != NULL)
    {
      curr_arr.push_back(node->val);
      return;
    }
    curr_arr.push_back(node->val);
    path_retrace(m, m[node], curr_arr);
  }
  bool rec(TreeNode *root, int targetSum, int curr,
           unordered_map<TreeNode *, TreeNode *> &m, vector<vector<int>> &ans)
  {
    if (root == NULL)
    {
      return false;
    }
    if (root->left == NULL && root->right == NULL)
    {
      if ((curr + root->val) == targetSum)
      {
        vector<int> curr_arr;
        path_retrace(m, root, curr_arr);
        reverse(curr_arr.begin(), curr_arr.end());
        ans.push_back(curr_arr);
        return true;
      }

      return false;
    }
    bool a = rec(root->left, targetSum, curr + root->val, m, ans);
    bool b = rec(root->right, targetSum, curr + root->val, m, ans);
    return a | b;
  }
  vector<vector<int>> pathSum(TreeNode *root, int targetSum)
  {
    vector<vector<int>> ans;
    unordered_map<TreeNode *, TreeNode *> m;
    inorder(root, m);
    if (rec(root, targetSum, 0, m, ans))
    {
      return ans;
    }
    return {};
  }
  int cnt = 0;
  void rec(TreeNode *root, vector<TreeNode *> &v, int targetSum, long long s)
  {
    if (root == NULL)
    {
      return;
    }
    s += root->val;
    if (s == targetSum)
      cnt++;
    rec(root->left, v, targetSum, s);
    rec(root->right, v, targetSum, s);
    s -= root->val;
  }
  void in(TreeNode *root, int targetSum)
  {
    if (root == NULL)
      return;
    vector<TreeNode *> v;
    rec(root, v, targetSum, 0);
    in(root->left, targetSum);
    in(root->right, targetSum);
  }
  int pathSum3(TreeNode *root, int targetSum)
  {
    in(root, targetSum);
    return cnt;
  }
  int minOperations(vector<int> &nums)
  {
    int ans = 0;
    for (int x = 0; x < nums.size(); x++)
    {
      if (nums[x] == 1)
        continue;
      else if (nums[x] == 0)
      {
        if ((x + 2) < nums.size())
        {
          nums[x] = 1;
          for (int k = 1; (k + x) < nums.size() && k <= 2; k++)
          {
            if (nums[k + x] == 0)
              nums[k + x] = 1;
            else if (nums[k + x] == 1)
              nums[k + x] = 0;
          }
          ans++;
        }
        else
        {
          return -1;
        }
      }
    }
    return ans;
  }
  // Important use of updation for both side path //
  int ans = 0;
  int rec(TreeNode *root, int parent)
  {
    if (root == NULL)
    {
      return 0;
    }
    int a = rec(root->left, root->val);
    int b = rec(root->right, root->val);
    ans = max(ans, (a + b));
    return root->val == parent ? 1 + max(a, b) : 0;
  }
  int longestUnivaluePath(TreeNode *root)
  {
    rec(root, -1);
    return ans;
  }
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    // Base case//
    if (root == NULL)
    {
      return NULL;
    }
    if (root == p || root == q)
    {
      return root;
    }
    TreeNode *leftans = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightans = lowestCommonAncestor(root->right, p, q);
    if (rightans == NULL && leftans != NULL)
    {
      return leftans;
    }
    if (rightans != NULL && leftans == NULL)
    {
      return rightans;
    }
    if (rightans == NULL && leftans == NULL)
    {
      return NULL;
    }
    return root;
  }
  vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
  {
    vector<string> ans;
    string res = "";
    string com = "";
    for (int x = 0; x < words2.size(); x++)
    {
      res += words2[x];
    }
    unordered_map<char, int> m;
    for (const auto &word : words2)
    {
      map<char, int> tempCharFreq;

      for (char ch : word)
      {
        tempCharFreq[ch]++;
      }

      for (const auto &[ch, freq] : tempCharFreq)
      {
        m[ch] = std::max(m[ch], freq);
      }
    }

    for (int x = 0; x < words1.size(); x++)
    {
      com += words1[x];
      com.push_back(' ');
    }

    unordered_map<char, int> mp;
    int idx = 0;
    int cnt = 0;
    for (int x = 0; x < com.size(); x++)
    {
      if (com[x] == ' ')
      {
        bool flag = true;
        cnt = 0;
        for (auto it : mp)
        {
          char ch = it.first;
          if (m.count(ch) == true && m[ch] <= it.second)
          {
            cnt++;
          }
        }
        if (cnt == m.size())
          ans.push_back(words1[idx]);
        mp.clear();
        idx++;
      }
      else
      {
        if (com[x] != ' ')
          mp[com[x]]++;
      }
    }
    return ans;
  }
  bool canConstruct(string s, int k)
  {
    unordered_map<char, int> m;
    if (s.length() < k)
      return false;
    for (int x = 0; x < s.length(); x++)
    {
      m[s[x]]++;
    }
    int extra_ones = 0;
    for (auto it : m)
    {
      if (it.second % 2 != 0)
        extra_ones++;
    }
    if (extra_ones > k)
      return false;
    return true;
  }
  // bool check(int row, int col, int c, int r)
  // {
  //   if (row >= r || col >= c)
  //     return false;
  //   return true;
  // }
  int rec(int row, int col, int r, int c, vector<vector<int>> &dp)
  {
    if (row == r - 1 && col == c - 1)
    {
      return 1;
    }
    if (dp[row][col] != -1)
    {
      return dp[row][col];
    }
    int a, b;
    a = 0;
    b = 0;
    if (check(row + 1, col, c, r) == true)
    {
      a = rec(row + 1, col, r, c, dp);
    }
    if (check(row, col + 1, c, r) == true)
    {
      b = rec(row, col + 1, r, c, dp);
    }
    return dp[row][col] = a + b;
  }
  int uniquePaths(int m, int n)
  {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return rec(0, 0, m, n, dp);
  }
  bool check(int row, int col, vector<vector<int>> &coins)
  {
    if (row >= coins.size() || col >= coins[0].size())
    {
      return false;
    }
    return true;
  }
  int rec(vector<vector<int>> &coins, int row, int col, int cnt,
          vector<vector<vector<int>>> &dp)
  {
    // base case //
    if (row == coins.size() - 1 && col == coins[0].size() - 1)
    {
      if (coins[row][col] < 0 && cnt < 2)
      {
        return 0;
      }
      return coins[row][col];
    }
    if (dp[row][col][cnt] != -1)
    {
      return dp[row][col][cnt];
    }

    // take and no take //
    int no_take = INT_MIN;
    int take = INT_MIN;
    if (check(row, col, coins) == true && coins[row][col] >= 0)
    {
      take = coins[row][col] + max(rec(coins, row + 1, col, cnt, dp),
                                   rec(coins, row, col + 1, cnt, dp));
    }
    else if (check(row, col, coins) == true && coins[row][col] < 0)
    {
      int a = INT_MIN;
      int b = INT_MIN;
      if (cnt < 2)
      {
        // avoid that negitive value if skip count not 2//
        a = max(rec(coins, row + 1, col, cnt + 1, dp),
                rec(coins, row, col + 1, cnt + 1, dp));
        ;
      }
      // we cannot avoid hence take it no other option//
      b = coins[row][col] + max(rec(coins, row + 1, col, cnt, dp),
                                rec(coins, row, col + 1, cnt, dp));
      no_take = max(a, b);
    }
    return dp[row][col][cnt] = max(take, no_take);
  }
  int maximumAmount(vector<vector<int>> &coins)
  {
    vector<vector<vector<int>>> dp(
        coins.size() + 1,
        vector<vector<int>>(coins[0].size() + 1, vector<int>(3, -1)));
    return rec(coins, 0, 0, 0, dp);
  }
  bool check(int row, int col, vector<vector<int>> &visited, vector<vector<int>> &obstacleGrid)
  {
    if (row < obstacleGrid.size() && col < obstacleGrid[0].size() && obstacleGrid[row][col] == 0)
    {
      return true;
    }
    return false;
  }
  int rec(vector<vector<int>> &obstacleGrid, int row, int col, vector<vector<int>> &visited)
  {
    // Base case if the row exceeds the range or the column//
    // if the destination is reached//
    if (row == obstacleGrid.size() - 1 && col == obstacleGrid[0].size() - 1)
    {
      return 1;
    }
    if (visited[row][col] != -1)
    {
      return visited[row][col];
    }
    // allowed movement for right and down movements only//
    // checking if the move is valid or not and also if it is not visited earlier//
    int a = 0;
    int b = 0;
    if (check(row, col + 1, visited, obstacleGrid) == true)
    {

      a = rec(obstacleGrid, row, col + 1, visited);
    }

    if (check(row + 1, col, visited, obstacleGrid) == true)
    {

      b = rec(obstacleGrid, row + 1, col, visited);
    }
    visited[row][col] = a + b;
    return visited[row][col];
  }
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
  {
    vector<vector<int>> visited(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
    if (obstacleGrid[0][0] == 1)
    {
      return 0;
    }
    return rec(obstacleGrid, 0, 0, visited);
  }
  // int ans = 0;
  int empty_box = 1;
  void rec(int row, int col, vector<vector<int>> &grid, int empty_box)
  {
    cout << empty_box << endl;
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() ||
        grid[row][col] < 0)
      return;
    if (grid[row][col] == 2)
    {
      if (empty_box == 0)
      {
        ans++;
      }
      return;
    }
    grid[row][col] = -2;
    empty_box -= 1;
    rec(row + 1, col, grid, empty_box);
    rec(row - 1, col, grid, empty_box);
    rec(row, col + 1, grid, empty_box);
    rec(row, col - 1, grid, empty_box);
    grid[row][col] = 0;
    empty_box += 1;
  }
  int uniquePathsIII(vector<vector<int>> &grid)
  {
    int dest_index_row, dest_index_col, start_index_row, start_index_col;
    for (int x = 0; x < grid.size(); x++)
    {
      for (int y = 0; y < grid[0].size(); y++)
      {
        if (grid[x][y] == 1)
        {
          start_index_row = x;
          start_index_col = y;
        }
        if (grid[x][y] == 2)
        {
          dest_index_row = x;
          dest_index_col = y;
        }
        if (grid[x][y] == 0)
          empty_box++;
      }
    }
    rec(start_index_row, start_index_col, grid, empty_box);
    return ans;
  }
  bool isValid(string s)
  {
    stack<int> st;
    for (int x = 0; x < s.length(); x++)
    {
      char ch = s[x];
      if (st.empty() == true)
      {
        st.push(ch);
      }
      else
      {
        if (st.top() == '(' && ch == ')' ||
            st.top() == '[' && ch == ']' ||
            st.top() == '{' && ch == '}')
        {
          st.pop();
        }
        else
        {
          st.push(ch);
        }
      }
    }
    if (st.empty() == true)
    {
      return true;
    }
    return false;
  }
  void rec(int n, unordered_map<char, int> &m, string &path,
           vector<string> &ans)
  {
    if (path.size() == 2 * n)
    {
      ans.push_back(path);
      return;
    }
    for (auto &it : m)
    {
      if (it.second <= 0)
        continue;
      else
      {
        m[it.first]--;
        path.push_back(it.first);
        rec(n, m, path, ans);
        m[it.first]++;
        path.pop_back();
      }
    }
  }
  vector<string> generateParenthesis(int n)
  {
    vector<string> ans;
    unordered_map<char, int> m;
    for (int x = 0; x < n; x++)
    {
      m['('] += 1;
      m[')'] += 1;
    }
    string path = "";
    rec(n, m, path, ans);
    vector<string> ans_str;
    for (auto it : ans)
    {
      if (isValid(it))
        ans_str.push_back(it);
    }
    return ans_str;
  }
  // Good parenthese having DUAL STACK approach also //
  bool rec(int count, int idx, string s, vector<vector<int>> &dp)
  {
    // base case//
    if (idx >= s.length())
    {
      // if brackets are balanced i.e.
      // number of opened brackets is equal to closed brackets
      if (count == 0)
        return true;
      return false;
    }
    if (dp[idx][count] != -1)
      return dp[idx][count];
    bool a = false;
    bool b = false;
    if (s[idx] == '*')
    {
      // Choice for substituting as open bracket
      a |= rec(count + 1, idx + 1, s, dp);
      // Count for open bracket to be
      // incremented only when there are some open brackets present
      // otherwise no point of iterating and adding the count
      // as we will have to substitute in 2d dp also and hence negitive
      // value wont be indexed
      if (count > 0)
      {
        a |= rec(count - 1, idx + 1, s, dp);
      }
      // substituing nothing hence no take and move on
      a |= rec(count, idx + 1, s, dp);
      if (a == true)
        return true;
    }
    else
    {
      if (s[idx] == '(')
      {
        b = rec(count + 1, idx + 1, s, dp);
      }
      else if (s[idx] == ')' && count > 0)
      {
        b = rec(count - 1, idx + 1, s, dp);
      }
    }
    return dp[idx][count] = a | b;
  }
  bool checkValidString(string s)
  {
    vector<vector<int>> dp(s.size() + 1, vector<int>(10e3, -1));
    return rec(0, 0, s, dp);
  }
  // finding whether a given node is reachable from other nodes or not//
  bool bfs(vector<vector<int>> &adj_mat, int root, int dest)
  {
    queue<int> q;
    q.push(root);
    unordered_map<int, bool> m;
    while (q.empty() != true)
    {
      int frontNode = q.front();
      q.pop();
      m[frontNode] = true;
      for (int x = 0; x < adj_mat[frontNode].size(); x++)
      {
        int neighbour_node = adj_mat[frontNode][x];
        if (neighbour_node != -1 && m.count(x) == false)
        {
          if (x == dest)
            return true;
          else
          {
            q.push(x);
          }
        }
      }
    }
    return false;
  }
  vector<int> findReachable(int target_node, vector<vector<int>> &edges, int n)
  {
    vector<vector<int>> adj_mat(n, vector<int>(n, -1));
    for (int x = 0; x < edges.size(); x++)
    {
      int u = edges[x][0];
      int v = edges[x][1];
      int weight = edges[x][2];
      adj_mat[u][v] = weight;
    }
    vector<int> ans;
    for (int x = 0; x < n; x++)
    {
      if (target_node == x)
        continue;
      else
      {
        if (bfs(adj_mat, x, target_node) == true)
        {
          ans.push_back(x);
        }
      }
    }
    return ans;
  }
  // REVISE AGAIN MUSTTT DO
  int minMaxWeight(int n, vector<vector<int>> &edges, int threshold)
  {
    /*
    The conditions to satisfy -:

    Node 0 must be reachable from all other nodes.
    The maximum edge weight in the resulting graph is minimized.
    Each node has at most threshold outgoing edges.

    Observations-:

    If 0 cannot be reached from any of the exisiting nodes then automatically false
    since we cannot add any edge.

    Calculate the outdegree for each node and check whether that degree is lesser than threshold if not then we will approach in a greedy manner i.e. deleting those edges
    having highest to lowest cost but keeping sure that deleting any of those edges dont
    mess up reaching the 0th node.
    VVIMP ---- reversing the entire graph will take out the threshold variable from the game

    */
    // Initially checking if there is any node which does not have a dedicated path towards 0th node then no possible answer could exist hence return -1
    vector<vector<int>> adj_mat(n, vector<int>(n, -1));
    // reversing the graph edges
    for (int x = 0; x < edges.size(); x++)
    {
      int u = edges[x][0];
      int v = edges[x][1];
      int wt = edges[x][2];
      adj_mat[v][u] = wt;
    }
    // start from the 0th node and travese using dijkstra
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    unordered_map<int, bool> visited;
    int ans = INT_MIN;
    while (pq.empty() != true)
    {
      int node = pq.top().second;
      int wt = pq.top().first;
      pq.pop();
      visited[node] = true;
      ans = max(ans, wt);
      for (int x = 0; x < adj_mat[node].size(); x++)
      {
        int wt = adj_mat[node][x];
        if (wt != -1 && visited[x] != true)
        {
          pq.push({wt, x});
        }
      }
    }
    for (auto it : visited)
    {
      if (it.second == false)
        return -1;
    }
    return ans;
  }
  int minimumLength(string s)
  {
    unordered_map<char, int> m1, m2;
    int cnt = 0;
    for (int x = 0; x < s.length(); x++)
    {
      m1[s[x]] += 1;
    }
    for (int x = 0; x < s.length(); x++)
    {
      m1[s[x]] -= 1;
      if (m1[s[x]] > 0 && m2[s[x]] > 0)
      {
        cnt++;
        m1[s[x]] -= 1;
        m2[s[x]] -= 1;
      }

      m2[s[x]] += 1;
    }
    return (s.size() - (2 * cnt));
  }
  int rec(vector<vector<int>> &moveTime)
  {
    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>
        pq;
    vector<vector<int>> dist(moveTime.size(),
                             vector<int>(moveTime[0].size(), INT_MAX));
    dist[0][0] = moveTime[0][0];
    pq.push({0, {0, 0}});
    while (pq.empty() != true)
    {
      auto node = pq.top();
      pq.pop();
      int row = node.second.first;
      int col = node.second.second;
      int cost = node.first;
      if ((row + 1) < moveTime.size())
      {
        int c = max(cost, moveTime[row + 1][col]) + 1;
        if (c < dist[row + 1][col])
        {
          dist[row + 1][col] = c;
          pq.push({c, {row + 1, col}});
        }
      }
      if ((row - 1) >= 0)
      {
        int c = max(cost, moveTime[row - 1][col]) + 1;
        if (c < dist[row - 1][col])
        {
          dist[row - 1][col] = c;
          pq.push({c, {row - 1, col}});
        }
      }
      if ((col + 1) < moveTime[0].size())
      {
        int c = max(cost, moveTime[row][col + 1]) + 1;
        if (c < dist[row][col + 1])
        {
          dist[row][col + 1] = c;
          pq.push({c, {row, col + 1}});
        }
      }
      if ((col - 1) >= 0)
      {
        int c = max(cost, moveTime[row][col - 1]) + 1;
        if (c < dist[row][col - 1])
        {
          dist[row][col - 1] = c;
          pq.push({c, {row, col - 1}});
        }
      }
    }
    return dist[dist.size() - 1][dist[0].size() - 1];
  }
  int minTimeToReach(vector<vector<int>> &moveTime) { return rec(moveTime); }
  int minimizeXor(int num1, int num2)
  {
  }
};

class test : public Solution
{
public:
  long long rec(long long n)
  {
    if (n <= 3)
    {
      return 1;
    }
    return (rec(n / 4) * 2);
  }
  long long rec(long long right, long long left, long long range, vector<vector<long long>> &dp)
  {
    // base case//
    if (right - left + 1 < range)
    {
      return 0;
    }
    if (dp[right][left] != -1)
    {
      return dp[right][left];
    }
    long long mid = left + (right - left) / 2;
    if ((right - left + 1) % 2 == 0)
    {
      long long left_partition_value = rec(mid, left, range, dp);
      long long right_partition_value = rec(right, (mid + 1), range, dp);

      return dp[right][left] = left_partition_value + right_partition_value;
    }
    else
    {
      long long l = rec(mid - 1, left, range, dp);
      long long r = rec(right, (mid + 1), range, dp);
      return dp[right][left] = (l + r + mid);
    }
  }
  void solve()
  {
    /*
      string s with digits from [0-9]
      pick any digit except zero or leftmost digit
      and decrease it by 1 swap it with the digit at immediate left with the one which you have picked
      find lexicographically maximum string possible
    */
    // string s;
    // cin >> s;
    // string ans = "";
    // for (int x = 0; x < s.length(); x++)
    // {
    //   string a = "";
    //   a.push_back(s[x]);
    //   int curr_num = stoi(a);
    //   int idx = x;
    //   for (int y = x + 1; y < ((x + 10) > s.length() ? s.length() : (x + 10)); y++)
    //   {
    //     if (s[y] == '0')
    //       continue;
    //     a.pop_back();
    //     a.push_back(s[y]);
    //     int num = stoi(a);
    //     if ((num - (y - x)) > curr_num)
    //     {
    //       idx = y;
    //       curr_num = (num - (y - x));
    //     }
    //   }
    //   while (idx > x)
    //   {
    //     swap(s[idx], s[idx - 1]);
    //     idx--;
    //   }
    //   s[x] = to_string(curr_num)[0];
    // }
    // cout << s << endl;
    // int number;
    // cin >> number;
    // int num_2 = 0;
    // int num_3 = 0;
    // int sum = 0;
    // string num = to_string(number);
    // for (int x = 0; x < num.length(); x++)
    // {
    //   if (num[x] == '3')
    //     num_3 += 1;
    //   if (num[x] == '2')
    //     num_2 += 1;
    //   string digit = "";
    //   digit.push_back(num[x]);
    //   sum += stoi(digit);
    // }
    // if (sum % 9 == 0)
    // {
    //   cout << "YES" << endl;
    //   return;
    // }
    // else if (sum % 9 != 0)
    // {
    //   if (num == "2")
    //   {
    //     cout << "NO\n";
    //     return;
    //   }
    //   int res = 9 - (sum % 9);
    //   bool flag = 0;
    //   int x = num_2, y = num_3;

    //   // (6y + 2x) % 9 == res
    //   for (int i = 0; i <= x; i++)
    //   {
    //     for (int j = 0; j <= y; j++)
    //     {
    //       if ((i * 2 + j * 6) % 9 == res)
    //       {
    //         flag = 1;
    //         break;
    //       }
    //       if (flag)
    //         break;
    //     }
    //   }
    //   if (flag)
    //     cout << "YES\n";
    //   else
    //     cout << "NO\n";
    // }

    // ll k, l1, r1, l2, r2;
    // cin >> k >> l1 >> r1 >> l2 >> r2;
    // ll maxi, mini;
    // ll temp_l1, temp_r1, temp_l2, temp_r2;
    // ll ans = 0;
    // for (int x = 0; x <= 32; x++)
    // {
    //   ll power = pow(k, x);
    //  if(power > 10e9)break;
    //   temp_l1 = l1;
    //   temp_r1 = r1;
    //   temp_l2 = l2;
    //   temp_r2 = r2;
    //   maxi = -1;
    //   mini = -1;
    //   // cout << "POWER" << " " << power << endl;
    //   while (temp_l1 <= temp_r1)
    //   {
    //     ll mid = (temp_l1 + temp_r1) / 2;
    //     // cout << (power * mid) << endl;
    //     if ((power * mid) >= l2 && (power * mid) <= r2)
    //     {
    //       maxi = mid;
    //       temp_l1 = mid + 1;
    //     }
    //     if ((power * mid) < l2)
    //     {
    //       temp_l1 = mid + 1;
    //     }
    //     else if ((power * mid) > r2)
    //     {
    //       temp_r1 = mid - 1;
    //     }
    //   }
    //   temp_l1 = l1;
    //   temp_r1 = r1;
    //   while (temp_l1 <= temp_r1)
    //   {
    //     ll mid = (temp_l1 + temp_r1) / 2;
    //     if ((power * mid) >= l2 && (power * mid) <= r2)
    //     {
    //       mini = mid;
    //       temp_r1 = mid - 1;
    //     }
    //     if ((power * mid) < l2)
    //     {
    //       temp_l1 = mid + 1;
    //     }
    //     else if ((power * mid) > r2)
    //     {
    //       temp_r1 = mid - 1;
    //     }
    //   }
    //   if (mini != -1 && maxi != -1)
    //   {
    //     cout << maxi << " " << "Maximum Value for the n equal to" << " " << x << endl;
    //     cout << mini << " " << "Minimum Value for the n equal to" << " " << x << endl;
    //     ans += (maxi - mini + 1);
    //   }
    //   // ans += (maxi - mini + 1);
    // }
    // cout << ans << endl;
    // string s;
    // cin >> s;
    // string rev = s;
    // reverse(rev.begin(), rev.end());
    // string ans = "";
    // for (int x = 0; x < rev.size(); x++)
    // {
    //   char ch = rev[x];
    //   if (ch == 'w')
    //     ans.push_back('w');
    //   else if (ch == 'p')
    //   {
    //     ans.push_back('q');
    //   }
    //   else if (ch == 'q')
    //   {
    //     ans.push_back('p');
    //   }
    // }
    // cout << ans << endl;
    // int n;
    // cin >> n;
    // vector<int> v(n);
    // for (int x = 0; x < n; x++)
    // {
    //   cin >> v[x];
    // }
    // vector<int> ans;
    // vector<int> random_numbers;
    // unordered_set<int> s;
    // vector<int> visited(n, 0);
    // for (auto x : v)
    // {
    //   s.insert(x);
    // }
    // for (int x = 1; x <= n; x++)
    // {
    //   if (s.find(x) == s.end())
    //   {
    //     random_numbers.push_back(x);
    //   }
    // }
    // int cnt = 0;
    // for (int x = 0; x < n; x++)
    // {
    //   if (visited[v[x] - 1] == 0)
    //   {
    //     ans.push_back(v[x]);
    //     visited[v[x] - 1] = 1;
    //   }
    //   else
    //   {
    //     ans.push_back(random_numbers[cnt]);
    //     cnt++;
    //   }
    // }
    // for (int x = 0; x < ans.size(); x++)
    // {
    //   cout << ans[x] << " ";
    // }
    // cout << endl;
    // string s;
    // cin >> s;
    // int cnt_ones = 0;
    // int cnt_zeros = 0;
    // int i, j, k, l;
    // unordered_map<string, pair<int, int>> m;
    // for (int x = 0; x < s.size(); x++)
    // {
    //   string sub = "";
    //   sub.push_back(s[x]);
    //   m[sub] = {x, x};
    //   for (int y = (x + 1); y < s.size(); y++)
    //   {
    //     sub.push_back(s[y]);
    //     m[sub] = {x, y};
    //   }
    // }
    // for (int x = 0; x < s.length(); x++)
    // {
    //   if (s[x] == '1')
    //   {
    //     cnt_ones++;
    //   }
    //   else
    //   {
    //     cnt_zeros++;
    //   }
    // }
    // if (cnt_ones == 0 || cnt_zeros == 0)
    // {
    //   i = 1;
    //   j = s.length();
    //   k = 1;
    //   l = 1;
    //   cout << i << " " << j << " " << k << " " << l << endl;
    //   return;
    // }
    // else if (cnt_zeros != 0 && cnt_ones != 0)
    // {
    //   i = 1;
    //   j = s.length();
    //   k = -1;
    //   l = -1;
    //   bool flag = true;
    //   string def = "";
    //   for (int x = 0; x < s.length(); x++)
    //   {
    //     if (s[x] == '1')
    //     {
    //       continue;
    //     }
    //     else if (s[x] == '0')
    //     {
    //       def = "";
    //       for (int y = (x ); y < s.length(); y++)
    //       {
    //         // cout<<def<<" sadafsafasfa"<<endl;
    //         if (s[y] == '1')
    //         {
    //           def.push_back('0');
    //           if (m.count(def) == true)
    //           {
    //             k = m[def].first + 1;
    //             l = m[def].second + 1;
    //             // cout << i << " " << j << " " << k << " " << l << endl;
    //             // return;
    //           }
    //           else
    //           {
    //             def.pop_back();
    //             def.push_back('1');
    //           }
    //         }
    //         else if (s[y] == '0')
    //         {
    //           def.push_back('1');
    //           if (m.count(def) == true)
    //           {
    //             k = m[def].first + 1;
    //             l = m[def].second + 1;
    //             // cout << i << " " << j << " " << k << " " << l << endl;
    //             // return;
    //           }
    //           else
    //           {
    //             def.pop_back();
    //             def.push_back('0');
    //           }
    //         }
    //       }
    //         if (m.count(def) == true)
    //         {
    //           k = m[def].first + 1;
    //           l = m[def].second + 1;
    //           cout << i << " " << j << " " << k << " " << l << endl;
    //           return;
    //         }
    //     }
    //   }
    // }

    // i = 1;
    // j = s.length();
    // k = -1;
    // unordered_map<string, pair<int,int>> m;
    // for (int x = 0; x < s.size(); x++)
    // {
    //   string sub = "";
    //   sub.push_back(s[x]);
    //   m[sub] = {x,x};
    //   for (int y = (x + 1); y < s.size(); y++)
    //   {
    //     sub.push_back(s[y]);
    //     m[sub] = {x,y};
    //   }
    // }
    // string def = "";
    // bool flag = true;
    // for (int x = 0; x < s.length(); x++)
    // {
    //   if (s[x] == '1' && flag == true)
    //     continue;
    //   if (s[x] == '0' && flag == true)
    //   {
    //     if (k == -1)
    //     {
    //       k = x;
    //       l = x;
    //       flag = false;
    //       def.push_back('1');
    //     }
    //   }
    //   if (flag == false)
    //   {
    //     if (s[x] == '1')
    //     {
    //       def.push_back('0');
    //     }
    //     else if (s[x] == '0')
    //     {
    //       def.push_back('1');
    //     }
    //     if(m.count(def) == true){
    //       l = x;
    //     }
    //   }
    // }
    // int n;
    // cin >> n;
    // vector<int> v(n);
    // for (int i = 0; i < n; i++)
    // {
    //   cin >> v[i];
    // }
    // int cnt = 0;
    // bool flag = true;
    // int cnt2 = 0;
    // for (int x = 0; x < n; x++)
    // {
    //   if (v[x] == 0)
    //   {
    //     cnt2++;
    //   }
    // }
    // if (cnt2 == n)
    // {
    //   cout << 0 << endl;
    //   return;
    // }
    // for (int x = 0; x < n; x++)
    // {
    //   if (v[x] == 0 && flag == true)
    //     continue;
    //   else if (v[x] != 0 && flag == true)
    //   {
    //     flag = false;
    //     cnt++;
    //   }
    //   if (v[x] == 0 && flag == false)
    //   {
    //     flag = true;
    //   }
    // }
    // if (cnt <= 1)
    // {
    //   cout << 1 << endl;
    //   return;
    // }
    // cout << 2 << endl;
    // int n, l, m;
    // cin >> n >> m >> l;
    // vector<vector<int>> hurdles;
    // vector<vector<int>> power_ups;
    // for (int x = 0; x < n; x++)
    // {
    //   vector<int> temp(2);
    //   cin >> temp[0] >> temp[1];
    //   hurdles.push_back(temp);
    // }
    // for (int x = 0; x < m; x++)
    // {
    //   vector<int> temp(2);
    //   cin >> temp[0] >> temp[1];
    //   power_ups.push_back(temp);
    // }
    // int ans = 0;
    // map<int, priority_queue<int>> mapping;
    // int cnt = 0;
    // for (int x = 0; x < power_ups.size(); x++)
    // {
    //   if (power_ups[x][0] < hurdles[cnt][0])
    //   {
    //     mapping[hurdles[cnt][0]].push(power_ups[x][1]);
    //   }
    //   else if (power_ups[x][0] >= hurdles[cnt][0])
    //   {
    //     cnt++;
    //     if (cnt >= hurdles.size())
    //     {
    //       break;
    //     }
    //     else
    //     {
    //       mapping[hurdles[cnt][0]].push(power_ups[x][1]);
    //     }
    //   }
    // }
    // cnt = 0;
    // int diff;
    // int total_power = 1;
    // for (auto it : mapping)
    // {
    //   diff = hurdles[cnt][1] - hurdles[cnt][0];
    //   priority_queue<int> pq = it.second;
    //   bool flag = true;
    //   if (total_power >= (diff+2))
    //   {
    //     continue;
    //   }
    //   while (pq.empty() != true)
    //   {
    //     total_power += pq.top();
    //     ans++;
    //     if (total_power >= (diff+2))
    //     {
    //       cnt++;
    //       flag = false;
    //       break;
    //     }
    //     pq.pop();
    //   }
    //   if (flag == true)
    //   {
    //     cout << -1 << endl;
    //     return;
    //   }
    // }
    // cout << ans <<endl;
    // int n;
    // cin >> n;
    // vector<int> a(n);
    // vector<int> b(n);
    // for (int x = 0; x < n; x++)
    // {
    //   cin >> a[x];
    // }
    // for (int x = 0; x < n; x++)
    // {
    //   cin >> b[x];
    // }
    // int ans = 0;
    // int c = 0;
    // for (int x = 0; x < (n - 1); x++)
    // {
    //   int next = b[x + 1];
    //   if (a[x] > next)
    //   {
    //     ans += a[x];
    //     c += next;
    //   }
    // }
    // ans += a[a.size() - 1];
    // cout << (ans - c) << endl;

    // long long n, a, b, c;
    // cin >> n >> a >> b >> c;

    // int sum = (a + b + c);
    // int rem = n % sum;
    // {
    //   int temp = n;
    //   temp -= rem;
    //   int ans = 0;
    //   ans = temp / sum;
    //   sum *= ans;
    //   ans *= 3;
    //   if (sum >= n)
    //   {
    //     cout << ans << endl;
    //     return;
    //   }
    //   sum += a;
    //   if (sum >= n)
    //   {
    //     ans++;
    //     cout << ans << endl;
    //     return;
    //   }
    //   sum += b;
    //   if (sum >= n)
    //   {
    //     ans += 2;
    //     cout << ans << endl;
    //     return;
    //   }
    //   sum += c;
    //   if (sum >= n)
    //   {
    //     ans += 3;
    //     cout << ans << endl;
    //     return;
    //   }
    // }

    // int n, m, k;
    // cin >> n >> m >> k;
    // vector<int> a(m);
    // vector<int> q(k);
    // set<int> st;
    // for (int x = 0; x < m; x++)
    // {
    //   cin >> a[x];
    // }
    // for (int x = 0; x < k; x++)
    // {
    //   cin >> q[x];
    //   st.insert(q[x]);
    // }
    // string ans = "";
    // set<int> unknown;
    // for (int x = 1; x <= n; x++)
    // {
    //   if (st.count(x) != true)
    //   {
    //     unknown.insert(x);
    //   }
    // }
    // for (int x = 0; x < m; x++)
    // {
    //   int question = a[x];
    //   if (unknown.count(question) == true && unknown.size() <= 1 || unknown.size() == 0)
    //   {
    //     ans.push_back('1');
    //   }
    //   else
    //   {
    //     ans.push_back('0');
    //   }
    // }
    // cout << ans << endl;

    // long long n, x, y;
    // cin >> n >> x >> y;
    // vector<long long> v(n);
    // long long total_sum = 0;
    // for (int f = 0; f < v.size(); f++)
    // {
    //   cin >> v[f];
    //   total_sum += v[f];
    // }
    // long long s = 0;
    // long long e = n;
    // sort(v.begin(), v.end());
    // int mini = -1;
    // int maxi = (n + 1);
    // int ans = 0;
    // set<pair<int, int>> st;
    // for (int f = 0; f < n; f++)
    // {
    //   int num = v[f];
    //   int s = 0, e = n - 1;
    //   int mini = -1, maxi = -1;

    //   while (s <= e)
    //   {
    //     int mid = s + (e - s) / 2;
    //     if (x <= (total_sum - num - v[mid]) && (total_sum - num - v[mid]) <= y)
    //     {
    //       mini = mid;
    //       e = mid - 1;
    //     }
    //     else
    //     {
    //       s = mid + 1;
    //     }
    //   }

    //   s = 0, e = n - 1;

    //   while (s <= e)
    //   {
    //     int mid = s + (e - s) / 2;
    //     if (x <= (total_sum - num - v[mid]) && (total_sum - num - v[mid]) <= y)
    //     {
    //       maxi = mid;
    //       s = mid + 1;
    //     }
    //     else
    //     {
    //       e = mid - 1;
    //     }
    //   }
    //   // cout << "MINI" << " " << mini << " " << "MAXI" << " " << maxi << endl;
    //   if (mini != -1 && maxi != -1 && mini <= maxi)
    //   {
    //     for (int z = mini; z <= maxi; z++)
    //     {
    //       if (z == f || st.find({f, z}) != st.end() || st.find({z, f}) != st.end())
    //         continue;
    //       else
    //       {
    //         // cout << "VALID PAIR" << " " << v[f] << " " << v[z] << endl;
    //         ans++;
    //         st.insert({f, z});
    //       }
    //     }
    //   }
    //   // cout << "--------END---------------" << endl;
    // }
    // cout << ans<< endl;
    // long long n;
    // cin >> n;
    // long long ans = rec(n);
    // cout<<ans<<endl;
    // int n, d;
    // cin >> n >> d;
    // vector<int> ans;
    // ans.push_back(1);
    // if (n >= 3 || d % 3 == 0)
    //   ans.push_back(3);
    // if (d % 5 == 0)
    //   ans.push_back(5);
    // if (d % 7 == 0 || n >= 7)
    // {
    //   ans.push_back(7);
    // }
    // if (n < 7 && d % 7 != 0)
    // {
    //   int fact = 1;
    //   for (int x = 2; x <= n; x++)
    //   {
    //     fact *= x;
    //   }
    //   if (fact % 7 == 0)
    //     ans.push_back(7);
    // }
    // if (d % 9 == 0 || n >= 6 || (d % 3 == 0 && n >= 3))
    // {
    //   ans.push_back(9);
    // }
    // for (auto it : ans)
    // {
    //   cout << it << " ";
    // }
    // cout << endl;
    // ll k, l1, r1, l2, r2;
    // cin >> k >> l1 >> r1 >> l2 >> r2;
    // ll maxi, mini;
    // ll temp_l1, temp_r1, temp_l2, temp_r2;
    // ll ans = 0;
    // for (int x = 0; x <= 40; x++)
    // {
    //   ll power = pow(k, x);
    //   temp_l1 = l1;
    //   temp_r1 = r1;
    //   temp_l2 = l2;
    //   temp_r2 = r2;
    //   maxi = -1;
    //   mini = -1;
    //   // cout << "POWER" << " " << power << endl;
    //   while (temp_l1 <= temp_r1)
    //   {
    //     ll mid = (temp_l1 + temp_r1) / 2;
    //     // cout << (power * mid) << endl;
    //     if ((power * mid) >= l2 && (power * mid) <= r2)
    //     {
    //       maxi = mid;
    //       temp_l1 = mid + 1;
    //     }
    //     if ((power * mid) < l2)
    //     {
    //       temp_l1 = mid + 1;
    //     }
    //     else if ((power * mid) > r2)
    //     {
    //       temp_r1 = mid - 1;
    //     }
    //   }
    //   temp_l1 = l1;
    //   temp_r1 = r1;
    //   while (temp_l1 <= temp_r1)
    //   {
    //     ll mid = (temp_l1 + temp_r1) / 2;
    //     if ((power * mid) >= l2 && (power * mid) <= r2)
    //     {
    //       mini = mid;
    //       temp_r1 = mid - 1;
    //     }
    //     if ((power * mid) < l2)
    //     {
    //       temp_l1 = mid + 1;
    //     }
    //     else if ((power * mid) > r2)
    //     {
    //       temp_r1 = mid - 1;
    //     }
    //   }
    //   if (mini != -1 && maxi != -1)
    //     cout << maxi << " " << "Maximum Value for the n equal to" << " " << x << endl;
    //   cout << mini << " " << "Minimum Value for the n equal to" << " " << x << endl;
    //   {
    //     ans += (maxi - mini + 1);
    //   }
    //   // ans+=(maxi-mini+1);
    // }
    // cout << ans << endl;
    // int n;
    // cin >> n;
    // vector<int> v(n);
    // for (int x = 0; x < n; x++)
    // {
    //   cin >> v[x];
    // }
    // for (int x = 0; x < v.size() && (x + 1) < v.size(); x++)
    // {
    //   if (v[x] * 2 > v[x + 1] && v[x + 1] * 2 > v[x])
    //   {
    //     cout << "YES" << endl;
    //     return;
    //   }
    // }
    // cout<<"NO"<<endl;
    // long long n, k;
    // cin >> n >> k;
    // vector<vector<long long>> dp(1000, vector<long long>(1000, -1));
    // cout << rec(n, 1, k, dp) << endl;
    // int n;
    // cin >> n;
    // vector<vector<int>> v(n, vector<int>(2, 0));
    // set<int> st;
    // unordered_map<int, int> m;
    // for (int x = 0; x < n; x++)
    // {
    //   cin >> v[x][0] >> v[x][1];
    // }
    // for (int x = 0; x < v.size(); x++)
    // {
    //   int l = v[x][0];
    //   int r = v[x][1];
    //   if (l == r)
    //   {
    //     st.insert(l);
    //     m[l] += 1;
    //   }
    // }
    // string ans = "";
    // for (int x = 0; x < v.size(); x++)
    // {
    //   bool flag = true;
    //   if (v[x][0] == v[x][1] && m[v[x][0]] == 1)
    //   {
    //     ans.push_back('1');
    //     continue;
    //   }
    //   else if (v[x][0] == v[x][1] && m[v[x][0]] > 1)
    //   {
    //     ans.push_back('0');
    //     continue;
    //   }
    //   int l = v[x][0];
    //   int r = v[x][1];
    //   int lower_bnd = *st.lower_bound(l);
    //   int upper_bnd = *st.upper_bound(r);
    //   if (upper_bnd - lower_bnd < (r - l + 1))
    //   {
    //     ans.push_back('1');
    //   }
    //   else
    //   {
    //     ans.push_back('0');
    //   }
    // }
    // cout << ans << endl;
    // int n;
    // cin >> n;
    // string s;
    // cin >> s;
    // int num_s = 0;
    // int num_p = 0;
    // int num_dot = 0;
    // int last_p = 0;
    // int last_s = 0;
    // for (int x = 0; x < s.length(); x++)
    // {
    //   if (s[x] == '.')
    //     num_dot += 1;
    //   else if (s[x] == 'p')
    //   {
    //     num_p += 1;
    //     last_p = x;
    //   }
    //   else
    //   {
    //     num_s += 1;
    //     last_s = x;
    //   }
    // }
    // if (num_p == n || num_s == n || num_dot == n || (num_s == 0 && num_p != 0) || (num_p == 0 && num_s != 0))
    // {
    //   cout << "YES" << endl;
    //   return;
    // }
    // else
    // {
    //   if (num_p > 1 && num_s > 1)
    //   {
    //     cout << "NO" << endl;
    //     return;
    //   }
    //   else if (num_s > 1 && num_p > 1)
    //   {
    //     cout << "NO" << endl;
    //     return;
    //   }
    //   else if (num_s == 1 && num_p >= 1)
    //   {
    //     if (last_s == (0))
    //     {
    //       cout << "YES" << endl;
    //       return;
    //     }
    //     else
    //     {
    //       cout << "NO" << endl;
    //       return;
    //     }
    //   }
    //   else if (num_p == 1 && num_s >= 1 && last_p == (n - 1))
    //   {
    //     if (last_p == (n - 1))
    //     {
    //       cout << "YES" << endl;
    //       return;
    //     }
    //     else
    //     {
    //       cout << "NO" << endl;
    //       return;
    //     }
    //   }
    //   else
    //   {
    //     cout << "NO" << endl;
    //     return;
    //   }
    // }
    // int n;
    // cin >> n;
    // vector<vector<int>> v(2, vector<int>(n, 0));
    // for (int x = 0; x < n; x++)
    // {
    //   cin >> v[0][x];
    // }
    // for (int x = 0; x < n; x++)
    // {
    //   cin >> v[1][x];
    // }
    // int ans = 0;
    // int maxi = 0;
    // int maxi_idx = 0;
    // for (int x = 0; x < n; x++)
    // {
    //   int a = v[0][x];
    //   int b = v[1][x];
    //   if (a > b)
    //   {
    //     ans += a;
    //   }
    //   else if (a <= b)
    //   {
    //     if (a + b > maxi)
    //     {
    //       maxi_idx = x;
    //       maxi = a + b;
    //     }
    //   }
    // }
    // bool flag = true;
    // for (int x = 0; x < n; x++)
    // {
    //   int a = v[0][x];
    //   int b = v[1][x];
    //   if (a < b && x == maxi_idx && flag == true)
    //   {
    //     ans += (a + b);
    //     flag = false;
    //   }
    //   else if (a < b && flag == false)
    //   {
    //     ans += b;
    //   }
    // }
    // cout << ans << endl;
    // long long n, k;
    // cin >> n >> k;
    // vector<long long> v(n, 0);
    // for (int x = 0; x < n; x++)
    // {
    //   cin >> v[x];
    // }
    // long long ans = 0;
    // sort(v.begin(), v.end());
    // long long total_len = n;
    // long long idx = 0;
    // long long prev = 0;
    // long long val = 0;
    // for (int x = 0; x < n; x++)
    // {
    //   long long curr = v[x];
    //   long long diff = (curr - prev);
    //   prev = curr;
    //   if (((ans + (diff * total_len))) >= k)
    //   {
    //     idx = x;
    //     val = diff;
    //     break;
    //   }
    //   else
    //   {
    //     ans += (diff * total_len);
    //     total_len--;
    //   }
    // }
    // cout << k + idx  << endl;
    // int n, k;
    // cin >> n >> k;
    // vector<long long> v(n, 0);
    // unordered_map<int, int> m;
    // for (int x = 0; x < v.size(); x++)
    // {
    //   cin >> v[x];
    //   m[v[x]] += 1;
    // }
    // vector<int> freq_cnt;
    // if (k == n)
    // {
    //   cout << 1 << endl;
    //   return;
    // }
    // for (auto i : m)
    // {
    //   freq_cnt.push_back(i.second);
    // }
    // sort(freq_cnt.begin(), freq_cnt.end());
    // int ans = 0;
    // int cnt = 0;
    // int idx = 0;
    // for (int x = 0; x < freq_cnt.size()-1; x++)
    // {
    //   if (freq_cnt[x] > k)
    //   {
    //     idx = x;
    //     break;
    //   }
    //   else if (freq_cnt[x] <= k)
    //   {
    //     k -= freq_cnt[x];
    //     cnt++;
    //   }
    // }

    // cout << freq_cnt.size() - idx << endl;
    // long long n, x, y;
    // cin >> n >> x >> y;
    // vector<long long> v(n, 0);
    // long long sum = 0;
    // for (int x = 0; x < n; x++)
    // {
    //   cin >> v[x];
    //   sum += v[x];
    // }
    // sort(v.begin(), v.end());
    // long long l = sum - y;
    // long long r = sum - x;
    // long long extra_cnt = 0;
    // long long cnt = 0;
    // int s = 0;
    // int e = n - 1;
    // while (s <= e)
    // {
    //   long long pair_sum = v[s] + v[e];
    //   if (pair_sum > r)
    //   {
    //     e--;
    //   }
    //   else if (pair_sum <= r)
    //   {
    //     extra_cnt += (e - s);
    //     s++;
    //   }
    // }
    // s = 0;
    // e = n - 1;
    // while (s <= e)
    // {
    //   long long pair_sum = v[s] + v[e];
    //   if (pair_sum > l - 1)
    //   {
    //     e--;
    //   }
    //   else
    //   {
    //     cnt += (e - s);
    //     s++;
    //   }
    // }
    // cout << extra_cnt - cnt << endl;
    // int n;
    // cin >> n;
    // vector<int> v(n);
    // double curr_avg = 0;
    // for (int x = 0; x < n; x++)
    // {
    //   cin >> v[x];
    //   curr_avg += double(v[x]);
    // }
    // curr_avg = double(curr_avg / double(2 * n));
    // sort(v.begin(), v.end());
    // if (n < 3)
    //   cout << -1 << endl;
    // else
    // {
    //   cout << max(0, v[n / 2] * 2 * n - curr_avg - 1) << endl;
    // }
  }
  void cf_questions()
  {
    int t;
    cin >> t;
    while (t--)
    {
      solve();
    }
  }
};

TreeNode *construct_tree(TreeNode *&root, int data)
{
  if (data == -1)
  {
    return NULL;
  }
  // constructing new node//
  root = new TreeNode(data);
  int leftval, rightval;
  cout << "Enter the value to be inserted in left of" << " " << root->val << endl;
  cin >> leftval;
  root->left = construct_tree(root->left, leftval);
  cout << "Enter the value to be inserted in right of" << " " << root->val << endl;
  cin >> rightval;
  root->right = construct_tree(root->right, rightval);
  return root;
}
void po(TreeNode *&root)
{
  if (root == NULL)
  {
    return;
  }
  po(root->left);
  po(root->right);
  cout << root->val << " ";
}
void preo(TreeNode *&root)
{
  if (root == NULL)
  {
    return;
  }
  cout << root->val << " ";
  preo(root->left);
  preo(root->right);
}
void io(TreeNode *&root)
{
  if (root == NULL)
  {
    return;
  }
  io(root->left);
  cout << root->val << " ";
  io(root->right);
}
void level_order(TreeNode *&root)
{
  queue<TreeNode *> q;
  q.push(root);
  q.push(NULL);
  while (!q.empty())
  {
    TreeNode *temp = q.front();
    q.pop();
    if (temp == NULL)
    {
      cout << endl;
      if (!q.empty())
      {
        q.push(NULL);
      }
    }
    else
    {
      cout << temp->val << " ";
      if (temp->left)
      {
        q.push(temp->left);
      }
      if (temp->right)
      {
        q.push(temp->right);
      }
    }
  }
}
class Node
{
public:
  Node *arr[26];
  bool flag;
  Node()
  {
    this->flag = false;
    for (int x = 0; x < 26; x++)
    {
      arr[x] = NULL;
    }
  }
};
class Trie
{
public:
  Node *root;
  Trie() { root = new Node(); }
  void insert(string target)
  {
    Node *temp = root;
    int idx = 0;
    while (idx < target.size())
    {
      // cout<<"INSERTING FOR"<<target<<" "<<endl;
      char ch = target[idx];
      // if character exists//
      if (temp->arr[ch - 'a'] != NULL)
      {
        temp = temp->arr[ch - 'a'];
      }
      // if character does not exists//
      else
      {
        Node *newNode = new Node();
        temp->arr[ch - 'a'] = newNode;
        temp = temp->arr[ch - 'a'];
      }
      // if the word is fully traversed then mark the flag true//
      if (idx == target.size() - 1)
      {
        temp->flag = true;
      }
      idx++;
    }
  }
  bool search(string target)
  {
    Node *temp = root;
    int idx = 0;
    while (idx < target.size())
    {
      char ch = target[idx];
      if (temp->arr[ch - 'a'] == NULL)
      {
        return false;
      }
      else
      {
        temp = temp->arr[ch - 'a'];
      }
      idx++;
    }
    return temp->flag;
  }
  bool startsWith(string prefix)
  {
    Node *temp = root;
    int idx = 0;
    while (idx < prefix.size())
    {
      char ch = prefix[idx];
      if (temp->arr[ch - 'a'] == NULL)
      {
        return false;
      }
      else
      {
        temp = temp->arr[ch - 'a'];
      }
      idx++;
    }
    return true;
  }
};
class LineSweep
{
public:
  // Difference of array approach//
  // Whenever the operation is to be performed according to a received query//
  // instead of performing that operation at each index we can perform it
  // only on the ranges points i.e. at arr[l] and arr[r+1] and adding complement of the result
  // of operation performed thus it will reduce the overall complexity from O(q*N) to O(1) and after
  // calculating the difference array apply a prefix array operation in O(N) time that will ultimately give you the same
  // result as the above O(Q*N) type  remember it using the gun analogy as well//
  string shiftingLetters(string s, vector<vector<int>> &shifts)
  {
    vector<int> diff_arr(s.length(), 0);
    for (int x = 0; x < shifts.size(); x++)
    {
      int l = shifts[x][0];
      int r = shifts[x][1];
      int direction = shifts[x][2];
      if (direction == 0)
      {
        diff_arr[l] -= 1;
        if (r + 1 < s.size())
          diff_arr[r + 1] += 1;
      }
      else if (direction == 1)
      {
        diff_arr[l] += 1;
        if (r + 1 < s.size())
          diff_arr[r + 1] -= 1;
      }
    }
    vector<int> pf(diff_arr.size(), 0);
    pf[0] = diff_arr[0];
    for (int x = 1; x < diff_arr.size(); x++)
    {
      pf[x] = pf[x - 1] + diff_arr[x];
    }
    for (int x = 0; x < s.length(); x++)
    {
      int shif = pf[x];
      if (shif < 0)
        shif += 26;

      s[x] = 'a' + (s[x] - 'a' + shif) % 26;
      ;
    }
    return s;
  }
  // Longest proper prefix that is also a suffix//
  // KMP algorithm //
  // Very important longest proper prefix that is also a suffix
  void kmp_implementation(string target, string actual)
  {
    // longest proper prefix which is also a suffix //
    vector<int> lps(target.size(), 0);
    int prevLPS = 0;
    int i = 1;
    while (i < target.size())
    {
      if (target[i] == target[prevLPS])
      {
        lps[i] = prevLPS + 1;
        prevLPS += 1;
        i += 1;
      }
      else if (prevLPS == 0)
      {
        lps[i] = 0;
        i += 1;
      }
      else
      {
        prevLPS = lps[prevLPS - 1];
      }
    }
    i = 0;
    int e = 0;
    int start_idx = -1;
    while (e < target.length())
    {
      if (target[e] == actual[i])
      {
        i++;
        e++;
      }
      else
      {
        if (e == 0)
        {
          i += 1;
        }
        else
        {
          e = lps[e - 1];
        }
      }
      if (e >= target.length())
      {
        start_idx = i - target.size();
        break;
      }
    }

    for (auto i : lps)
    {
      cout << i << " ";
    }
    cout << endl;
    cout << "INDEX ACCORDING TO KMP IS : " << start_idx << " " << endl;
  }
};
class Graph
{
public:
  // this will contain information about each edge and its cost/weight
  vector<vector<int>> adj_mat;
  // rank vector will store the cost that will be the basis of joining two distinct components
  vector<int> rank;
  // this will be the parent array storing each node's parent used before union of two nodes
  vector<int> parent;
  // Constructor for constructing graph
  int n;
  Graph(vector<vector<int>> edges, int nodes)
  {
    this->n = nodes;
    cout << n << endl;
    adj_mat.resize(n, vector<int>(n, -1));

    // constructing a weighted and directed graph
    for (int x = 0; x < edges.size(); x++)
    {
      int u = edges[x][0];
      int v = edges[x][1];
      int weight = edges[x][2];
      // cout<<u<<" "<<v<<endl;
      if (adj_mat[u - 1][v - 1] != -1)
      {

        adj_mat[u - 1][v - 1] = min(adj_mat[u - 1][v - 1], weight);
      }
      else if (adj_mat[u - 1][v - 1] == -1)
      {
        adj_mat[u - 1][v - 1] = weight;
      }
    }
  }
  // this is the implementation for finding the parent of a given node using the parent
  // array
  int find_parent(int node)
  {
    // base case if we encounter the component's root node
    // then surely the parent's array indexed value will be equal to the node itself
    if (parent[node] == node)
    {
      return node;
    }
    find_parent(parent[node]);
  }
  // Implementing the inialization of the given dsu
  void initalization_dsu()
  {
    // graph size i.e. the number of nodes in a graph
    int graph_size = this->n;
    // the rank array will be intialized with zeros
    // the parent array will be initalized with the same parent as the given node
    for (int x = 0; x < graph_size; x++)
    {
      rank.push_back(0);
      parent.push_back(x);
    }
  }
  // this will contain the implementation for union of 2 nodes into a single connected component
  void union_set(int u, int v)
  {
    int parent_u = find_parent(u);
    int parent_v = find_parent(v);
    // firstly if both the parents are same it means that they belong to same component
    // hence no joining is required otherwise according to rank nodes are joined and their respective parents are updated
    if (parent_u == parent_v)
    {
      return;
    }
    else
    {
      // we will join according to the rank//
      int rank_parent_u = rank[parent_u];
      int rank_parent_v = rank[parent_v];
      if (rank_parent_u > rank_parent_v)
      {
        parent[parent_v] = parent_u;
      }
      else if (rank_parent_u < rank_parent_v)
      {
        parent[parent_u] = parent_v;
      }
      else if (rank_parent_u == rank_parent_v)
      {
        rank[parent_u]++;
        parent[parent_v] = parent_u;
      }
    }
  }
  // Implementation of kruskal algorithm for finding MST(Minimum spanning tree)
  void kruskal()
  {
    // sorting all the vertices of a graph ascendingly by weight
    set<pair<int, pair<int, int>>> st;
    for (int x = 0; x < adj_mat.size(); x++)
    {
      int u = x;
      int v = adj_mat[x][0];
      int weight = adj_mat[x][1];
      st.insert({weight, {u, v}});
    }
    // while the set is not empty pick the node of smallest possible weight and insert it into
    // the connected component as root and then move forward
    initalization_dsu();
    while (st.empty() != true)
    {
      auto it = *(st.begin());
      int weight = it.first;
      int u = it.second.first;
      int v = it.second.second;
      // join edge between u and v on the basis of dsu union set
      union_set(u, v);
      st.erase(st.begin());
    }
  }
  // Topological sort for ordering the vertices according to
  // a prescribed order can be understood with example of i.e. making of cake etc.
  void topological_sort()
  {
    // firstly calculating the indegrees for all the vertices and
    // to start with the vertice having indegree of 0 and further reducing the correspoing indegree count each node
    vector<int> indegee(this->n, 0);
    for (int x = 0; x < adj_mat.size(); x++)
    {
      int parent_node = x;
      for (int y = 0; y < adj_mat[x].size(); y++)
      {
        indegee[y]++;
      }
    }
    // Initialzing a queue and moving in a FIFO manner
    queue<int> q;
    for (int x = 0; x < indegee.size(); x++)
    {
      if (indegee[x] == 0)
        q.push(x);
    }
    vector<int> topological_order;
    while (q.empty() != true)
    {
      int frontNode = q.front();
      q.pop();
      topological_order.push_back(frontNode);
      for (int x = 0; x < adj_mat[frontNode].size(); x++)
      {
        indegee[x] -= 1;
        if (indegee[x] == 0)
          q.push(x);
      }
    }
  }
  // traversing the depth-first and breadth-first search thorughout the graph
  void bfs(int root_node)
  {
    unordered_map<int, bool> visited;
    queue<int> q;
    q.push(root_node);
    while (q.empty())
    {
      int frontNode = q.front();
      cout << frontNode << " ";
      visited[frontNode] = true;
      for (int x = 0; x < adj_mat[frontNode].size(); x++)
      {
        int neighbour = adj_mat[frontNode][x];
        if (visited[neighbour] == false)
        {
          q.push(neighbour);
        }
      }
    }
    cout << "\n";
  }
  void dfs(int root, unordered_map<int, bool> &visited)
  {
    if (visited[root] == true)
    {
      return;
    }
    visited[root] = true;
    cout << root << " ";
    for (int x = 0; x < adj_mat[root].size(); x++)
    {
      int neighbour = adj_mat[root][x];
      dfs(root, visited);
    }
  }
  // dijsktra for finding out the single source shortest path
  void dijsktra(int src)
  {
    // Initalizing the distance array for keeping the track of overall path from source to all other nodes
    vector<int> dist(this->n, INT_MAX);
    // Visited for keeping track of all the nodes which are visited and not to get stuck in infinite loop
    vector<int> visited(this->n, 0);
    // Min-heap for keeping track of minimum possible weight reachable from the current node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    while (pq.empty() != true)
    {
      // cout<<pq.size()<<endl;
      // current parent node
      int node = pq.top().second;
      // current node's weight
      int wt = pq.top().first;
      pq.pop();
      if (visited[node])
        continue;
      visited[node] = true;
      for (int x = 0; x < adj_mat[node].size(); x++)
      {
        // if the current node + existing distance is lesser then it is
        // optimized than before path hence add that particular node to the queue and change the
        // corresponding sum
        if (adj_mat[node][x] != -1 && visited[x] != true && (wt + adj_mat[node][x]) < dist[x])
        {
          dist[x] = wt + adj_mat[node][x];
          pq.push({dist[x], x});
        }
      }
    }
    for (int x = 0; x < dist.size(); x++)
    {
      // cout << "THE SHORTEST COST TO TRAVEL FROM" << " " << src << " " << "TO " << x << " IS " << dist[x] << endl;
      cout << (dist[x] == INT_MAX ? 0 : dist[x]) << " ";
    }
  }
  void print_adj()
  {
    for (int x = 0; x < adj_mat.size(); x++)
    {
      for (int y = 0; y < adj_mat[x].size(); y++)
      {
        cout << adj_mat[x][y] << " ";
      }
      cout << endl;
    }
  }
  // prims algorithm for generating MST can be used for sparse graphs unlike kruskal
  void prims(int src)
  {
    vector<bool> visited(this->n, false);
    vector<int> parent(this->n, -1);
    vector<int> cost(this->n, INT_MAX);
    visited[src] = true;
    cost[src] = 0;
    for (int x = 0; x < n; x++)
    {
      int min_node_val = INT_MAX;
      int min_node = -1;
      for (int x = 0; x < cost.size(); x++)
      {
        if (cost[x] < min_node)
        {
          min_node = cost[x];
          min_node = x;
        }
      }
      visited[min_node] = true;
      for (int x = 0; x < adj_mat[min_node].size(); x++)
      {
        parent[x] = min_node;
        if (visited[x] != true && cost[x] > adj_mat[min_node][x])
        {
          cost[x] = adj_mat[min_node][x];
        }
      }
    }
  }
  // detecting cycles in a directed graph using the idea of Topological sort
  bool KahnCycleDetection()
  {
    vector<int> topo_order;
    vector<int> indegree(this->n, 0);
    for (int x = 0; x < adj_mat.size(); x++)
    {
      for (int y = 0; y < adj_mat[x].size(); y++)
      {
        if (adj_mat[x][y] != -1)
          indegree[y]++;
      }
    }
    queue<int> q;
    for (int x = 0; x < indegree.size(); x++)
    {
      if (indegree[x] == 0)
        q.push(x);
    }
    while (q.empty() != true)
    {
      int node = q.front();
      q.pop();
      topo_order.push_back(node);
      for (int x = 0; x < adj_mat[node].size(); x++)
      {
        if (adj_mat[node][x] != -1)
        {
          indegree[x]--;
          if (indegree[x] == 0)
            q.push(x);
        }
      }
    }
    for (auto order : topo_order)
    {
      cout << order << " ";
    }
    cout << endl;
    if (topo_order.size() != n)
    {
      return true;
    }
    return false;
  }
  // detection of cycle in an undirected graph using bfs
  bool detect(int node, unordered_map<int, bool> &visited)
  {
    vector<int> parent(this->n, -1);
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (q.empty() != true)
    {
      int root = q.front();
      for (int x = 0; x < adj_mat[root].size(); x++)
      {
        if (adj_mat[root][x] != -1 && visited[x] != true)
        {
          visited[x] = true;
          q.push(x);
          parent[x] = root;
        }
        else if (parent[root] != x)
        {
          return true;
        }
      }
    }
    return false;
  }
  bool cycleDetection()
  {
    unordered_map<int, bool> visited;
    for (int x = 0; x < this->n; x++)
    {
      if (visited[x] != true && detect(x, visited) == true)
      {
        return true;
      }
      else
      {
        continue;
      }
    }
    return false;
  }
  void bellman(unordered_map<string, double> &best, vector<vector<string>> &pairs, vector<double> &rates)
  {
    for (int relax_iteration = 0; relax_iteration < pairs.size(); ++relax_iteration)
    {
      for (int i = 0; i < pairs.size(); ++i)
      {
        best[pairs[i][1]] = max(best[pairs[i][1]], best[pairs[i][0]] * rates[i]);
        best[pairs[i][0]] = max(best[pairs[i][0]], best[pairs[i][1]] / rates[i]);
      }
    }
  }
  void countChars(string &str, int l, int r, int &countA, int &countB)
  {
    countA = 0, countB = 0;
    for (int i = l; i <= r; i++)
    {
      if (str[i] == 'A')
        countA++;
      else
        countB++;
    }
  }

  bool canTransform(int A1, int B1, int A2, int B2)
  {
    int total1_A = A1 + 2 * B1;
    int total2_A = A2 + 2 * B2;

    int total1_B = 2 * A1 + B1;
    int total2_B = 2 * A2 + B2;

    return ((total1_A - total2_A) % 3 == 0) || ((total1_B - total2_B) % 3 == 0);
  }
  void solve()
  {
    string S, T;
    int Q;
    cin >> S >> T >> Q;

    while (Q--)
    {
      int a, b, c, d;
      cin >> a >> b >> c >> d;

      int A1, B1, A2, B2;
      countChars(S, a - 1, b - 1, A1, B1);
      countChars(T, c - 1, d - 1, A2, B2);

      cout << (canTransform(A1, B1, A2, B2) ? "YES" : "NO") << endl;
    }
  }
};
class Spreadsheet
{
public:
  vector<vector<int>> spread_sheet;
  Spreadsheet(int rows)
  {
    this->spread_sheet.resize(rows, vector<int>(26, 0));
  }
  void setCell(string cell, int value)
  {
    string row_str = "";
    for (int x = 1; x < cell.size(); x++)
      row_str.push_back(cell[x]);
    int row = stoi(row_str);
    this->spread_sheet[row - 1][cell[0] - 'A'] = value;
  }
  void resetCell(string cell) { setCell(cell, 0); }

  int getValue(string formula)
  {
    string left = "";
    string right = "";
    bool flag = true;
    for (int x = 1; x < formula.size(); x++)
    {
      if (formula[x] == '+')
      {
        flag = false;
        continue;
      }
      if (flag == false)
      {
        right.push_back(formula[x]);
      }
      else if (flag == true)
      {
        left.push_back(formula[x]);
      }
    }
    int left_val = 0;
    int right_val = 0;
    if (left[0] >= 'A' && left[0] <= 'Z')
    {
      string temp = "";
      for (int x = 1; x < left.size(); x++)
      {
        temp.push_back(left[x]);
      }
      left_val = this->spread_sheet[stoi(temp) - 1][left[0] - 'A'];
    }
    else
    {
      left_val = stoi(left);
    }
    if (right[0] >= 'A' && right[0] <= 'Z')
    {
      string temp = "";
      for (int x = 1; x < right.size(); x++)
      {
        temp.push_back(right[x]);
      }
      right_val = this->spread_sheet[stoi(temp) - 1][right[0] - 'A'];
    }
    else
    {
      right_val = stoi(right);
    }
    return left_val + right_val;
  }
};
void solve()
{
}
int main()
{

  // Spreadsheet s(3);
  // cout << "Error" << endl;
  // s.getValue("=5+7");
  // cout << "Error" << endl;

  // s.setCell("A1", 10);
  // cout << "Error" << endl;

  // s.getValue("=A1+6");
  // cout << "Error" << endl;

  // s.setCell("B2", 15);
  // cout << "Error" << endl;

  // s.getValue("=A1+B2");
  // cout << "Error" << endl;

  // s.resetCell("A1");
  // cout << "Error" << endl;

  // s.getValue("=A1+B2");
  // test to;
  // vector<int> v = {1, 2, 3, 4, 5, 6};
  // to.finalPrices(v);
  // to.cf_questions();
  // LineSweep lo;
  // lo.kmp_implementation("AAAA", "AAAXAAAA");
  // TreeNode *root = NULL;
  // construct_tree(root, 1);
  // po(root);
  // Graph g({{0, 1, 4},
  //          {0, 7, 8},
  //          {1, 2, 8},
  //          {1, 7, 11},
  //          {2, 3, 7},
  //          {2, 8, 2},
  //          {2, 5, 4},
  //          {3, 4, 9},
  //          {3, 5, 14},
  //          {4, 5, 10},
  //          {5, 6, 2},
  //          {6, 7, 1},
  //          {6, 8, 6},
  //          {7, 8, 7}},
  //         9);
  // g.dijsktra(0);
  // g.print_adj();
  // int n, m;
  // cin >> n >> m;
  // vector<vector<int>> edges;
  // for (int x = 0; x < m; x++)
  // {
  //   vector<int> v(3, 0);
  //   for (int y = 0; y < 3; y++)
  //   {
  //     cin >> v[y];
  //   }
  //   edges.push_back(v);
  // }
  // Graph g(edges, n);
  // g.dijsktra(0);
  // g.print_adj();
  // int t;
  // cin >> t;
  // while (t--)
  // {
  //   solve();
  // }
}
