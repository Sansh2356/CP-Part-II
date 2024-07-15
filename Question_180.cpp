#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
#include <numeric>

using namespace std;
void make_adj(vector<pair<int, pair<int, int>>> edge, vector<vector<int>> &adj_list)
{

  for (int x = 0; x < edge.size(); x++)
  {
    int u = edge[x].first;
    int v = edge[x].second.first;
    int wt = edge[x].second.second;
    adj_list[u][v] = wt;
  }
}
void dijsktra(int src, vector<vector<int>> &adj_list, int vertices)
{
  vector<int> dist(vertices, INT_MAX);
  dist[src] = 0;

  set<pair<int, int>> s;

  s.insert({0, src});

  // first is distance and second is node//
  while (s.empty() != true)
  {
    auto p = *(s.begin());
    int node = p.second;
    int node_dist = p.first;
    s.erase(s.begin());
    for (int x = 0; x < adj_list[node].size(); x++)
    {
      if ((node_dist + adj_list[node][x]) < dist[x])
      {

        auto it = s.begin();
        while (it != s.end())
        {
          auto p2 = *(it);
          if (p2.second == x)
          {
            s.erase(s.find({dist[x], x}));
          }
          it++;
        }
        dist[x] = (node_dist + adj_list[node][x]);
        s.insert({dist[x], x});
      }
    }
  }
}

void solve()
{
  int vertex, edges;
  cin >> vertex >> edges;
  vector<vector<int>> adj_list(vertex, vector<int>(vertex, 0));
  vector<pair<int, pair<int, int>>> edge;
  for (int x = 0; x < edges; x++)
  {
    int u, v, wt;
    cin >> u >> v >> wt;
    edge.push_back({u, {v, wt}});
  }
  make_adj(edge, adj_list);
  for (int x = 0; x < adj_list.size(); x++)
  {
    for (int f = 0; f < adj_list[x].size(); f++)
    {
      cout << "U is :" << x << " "
           << "V is :"
           << " " << f << " "
           << "Weight between u and v is"
           << " " << adj_list[x][f] << endl;
    }
  }
}

int main()
{
  solve();
}