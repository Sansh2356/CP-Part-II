#include <iostream>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include<thread>
#include<chrono>
#include<ctime>
#include<mutex>
using namespace std;

void create_graph(vector<vector<int>> edges, vector<vector<int>> &adj_mat, int n)
{
  for (int x = 0; x < n; x++)
  {
    adj_mat[edges[x][0]][edges[x][1]] = edges[x][2];
  }
}
void kruskal(vector<vector<int>> &adj_mat, int n)
{
  // sorting by weight //
  set<pair<int, pair<int, int>>> s;
  vector<int> parent(n);
  vector<int> rank(n);
  for (int x = 0; x < n; x++)
  {
    parent[x] = x;
    rank[x] = 0;
  }
  for (int x = 0; x < s.size(); x++)
  {
    auto p = *(s.begin());
    int u = p.second.first;
    int v = p.second.second;
    if (u != v)
    {
      uni(u, v, rank, parent);
    }
  }
}
int find_parent(int node, vector<int> parent)
{
  if (parent[node - 1] == node)
  {
    return node;
  }
  return find_parent(parent[node - 1], parent);
}
void uni(int u, int v, vector<int> &rank, vector<int> &parent)
{
  int parent1 = find_parent(u, parent);
  int parent2 = find_parent(v, parent);

  if (parent1 == parent2)
  {
    return;
  }
  else if (parent1 != parent2)
  {
    if (rank[u] > rank[v])
    {
      parent[v] = u;
    }
    else if (rank[u] < rank[v])
    {
      parent[u] = v;
    }
    else
    {
      parent[u] = v;
      rank[u]++;
    }
  }
}
void disjoint_set_union(vector<vector<int>> &adj_mat, int n)
{
  vector<int> parent(n);
  vector<int> rank(n);
  for (int x = 0; x < n; x++)
  {
    parent[x] = x;
    rank[x] = 0;
  }
  return;
}

int main()
{
  vector<vector<int>> edges;
  int n = 5;
  vector<vector<int>> adj_mat(5, vector<int>(5, 0));
  create_graph(edges, adj_mat, n);
  disjoint_set_union(adj_mat, n);
  kruskal(adj_mat, n);
  thread
}