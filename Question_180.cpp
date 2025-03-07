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
// int rec(vector<vector<int>> &books, int shelfWidth, int idx, int widthLeft, int maxi)
// {
//   // Making partitions at different indexes such that each partition represents the
//   // number of shelf along with the books present on those shelf
//   if (idx >= books.size())
//   {
//     return 0;
//   }
//   // take and not-take the book//
//   int not_taken = 0;
//   int taken =  rec(books, shelfWidth, idx + 1, widthLeft, max(maxi, books[idx][1]));
//   // if taking the book only when //
//   if (widthLeft - books[idx][0] >= 0)
//   {
//     int not_taken = maxi+rec(books, shelfWidth, idx + 1, widthLeft - books[idx][0], -1);
//   }

//   return min(taken, not_taken);
// }
// class name
// {
// public:
//   name()
//   {
//     cout << "samnjsajoifs" << endl;
//   }
//   int get_name()
//   {
//     cout << "jkasdkasjnd" << endl;
//   }
// };
// class T : public name
// {
// public:
//   static int x;
//   int *ptr;
//   int y;
//   int get_name()
//   {
//     cout << "sadjaskndnkasd" << endl;
//   }
// };
int main()
{
}
