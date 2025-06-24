// #include <iostream>
// #include <unordered_set>
// #include <vector>
// #include <queue>
// #include <algorithm>
// #include <regex>
// #include <fcntl.h>
// #include <chrono>
// #include <thread>
// #include <unordered_map>
// using namespace std;

// bool detect(vector<vector<int>> &adj_mat, int nodes)
// {
//   vector<int> parents(nodes, -1);
//   unordered_map<int, bool> visited;
//   queue<int> q;
//   q.push(0);
//   visited[0] = true;
//   parents[0] = 0;
//   while (q.empty() != true)
//   {
//     int frontNode = q.front();
//     q.pop();
//     for (int x = 0; x < adj_mat[frontNode].size(); x++)
//     {
//       if (adj_mat[frontNode][x] != -1 && visited[x] != true)
//       {
//         visited[x] = true;
//         q.push(x);
//         parents[x] = frontNode;
//       }
//       else if (visited[x] == true && parents[frontNode] != x)
//       {
//         return true;
//       }
//     }
//   }
//   return false;
// }
// // auto glambda = [](auto a, auto &&b)
// // {
// //   return a < b;
// // };
// // auto print_name = []()
// // {
// //   cout << "Hello World" << endl;
// // };
// int main()
// {
//   // glambda(1, 2);
//   // int t;
//   // cin >> t;
//   // while (t--)
//   // {
//   //   long long n, num;
//   //   cin >> n >> num;
//   //   vector<long long> a(n);

//   //   for (int x = 0; x < n; x++)
//   //   {
//   //     cin >> a[x];
//   //   }
//   //   sort(a.begin(), a.end());
//   //   int cnt = 0;
//   //   unordered_map<long long, queue<long long>> m;
//   //   unordered_set<long long> st;

//   //   for (int x = 0; x < a.size(); x++)
//   //   {
//   //     m[a[x]].push(x);
//   //   }
//   //   for (int x = 0; x < a.size(); x++)
//   //   {
//   //     long long first = a[x];
//   //     long long second = (a[x] * num);
//   //     if (st.count(x) == true)
//   //       continue;
//   //     else
//   //     {
//   //       // a pair is present assign it to the a[x] value and mark both as visited
//   //       if (m[second].size() != 0)
//   //       {
//   //         long long idx_to_be_assigned = m[second].front();
//   //         m[second].pop();
//   //         st.insert(idx_to_be_assigned);
//   //         st.insert(x);
//   //       }
//   //       // a pair is not present it must be added so cnt must be incremented and after that both must be marked visited
//   //       else if (m[second].size() == 0 || m.count(second) == false)
//   //       {
//   //         st.insert(x);
//   //         cnt++;
//   //       }
//   //     }
//   //   }
//   //   cout << cnt << endl;
//   // }
//   int nodes;
//   cin >> nodes;
//   vector<vector<int>> edges(nodes);
//   for (int x = 0; x < edges.size(); x++)
//   {
//     int num_edges;
//     cin >> num_edges;
//     vector<int> edge(num_edges);
//     for (int y = 0; y < num_edges; y++)
//     {
//       cin >> edge[y];
//     }
//     edges[x] = edge;
//   }
//   vector<vector<int>> adj_mat(nodes, vector<int>(nodes, -1));
//   for (int x = 0; x < nodes; x++)
//   {
//     for (int y = 0; y < edges[x].size(); y++)
//     {
//       int u = edges[x][y];
//       adj_mat[x][u] = 1;
//       adj_mat[u][x] = 1;
//     }
//   }
//   for (int x = 0; x < adj_mat.size(); x++)
//   {
//     for (int y = 0; y < adj_mat[x].size(); y++)
//     {
//       cout << adj_mat[x][y] << " ";
//     }
//     cout << endl;
//   }
//   try
//   {
//     cout << "Entering the try block" << endl;
//     thread *newThread = new thread();
//     unsigned int c = newThread->hardware_concurrency();
//     cout << "Hardware concurrecny for the given hardware is :--" << c << endl;
//     // thread *newThread = new thread(detect, adj_mat, nodes);
//     // newThread->join();
//     // cout << detect(adj_mat, nodes) << endl;
//     // print_name();
//   }
//   catch (const exception &e)
//   {
//     cerr << e.what() << endl;
//   }

//   /*
//     a1^a2^a3 = 20
//     a0^a2^a3 = 11
//     a0^a1^a3 = 9
//     a0^a1^a2 = 24
// 1 2 3 4
// a0 a1 a2 a3
//   */
// 5,6,7,0
// }
#include <vector>
#include <unordered_map>
#include <iostream>
class TrieNode
{
public:
  TrieNode()
  {
  }
};
int main()
{
}