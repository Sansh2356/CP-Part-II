using namespace std;
#include <list>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <map>
#include <iostream>
// class graph{
//     public:
//     unordered_map<int,list<int>>m;
//     void create(int first,int second,bool flag){
//         m[first].push_back(second);
//         if(flag == false){
//             m[second].push_back(first);
//         }
//     }
//     void print(){
//         for(auto i:m){
//             cout<<"The value of node is ::"<<i.first<<endl;
//             for(auto x:i.second){
//                 cout<<x<<"  ";
//             }
//             cout<<endl<<endl;
//         }
//     }

// };
// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     graph go;
//     vector<int>nodes;
//     for(int x=0;x<m;x++){
//         int a,b;
//         cin>>a>>b;
//         go.create(a,b,false);

//     }
//     go.print();

// }
// //BFS//
// void adj(map<int, list<int>> &m, vector<pair<int, int>> edges)
// {
//     for (int x = 0; x < edges.size(); x++)
//     {
//         int u = edges[x].first;
//         int v = edges[x].second;
//         m[u].push_back(v);
//         m[v].push_back(u);
//     }
// }
// void bfs(map<int, list<int>> m, map<int, bool> visited, int vertex, vector<int> &ans)
// {
//     queue<int> q;
//     q.push(vertex);
//     visited[vertex] = true;
//     while (q.empty() != true)
//     {
//         int frontnode = q.front();
//         q.pop();
//         q.push(frontnode);
//         ans.push_back(frontnode);
//         for (int x = 0; x < m[frontnode].size(); x++)
//         {
//             q.push(m[frontnode].front());
//             visited[m[frontnode].front()] = true;
//         }
//     }
// }
// int main()
// {
//     int n, k;
//     vector<pair<int, int>> edges;
//     map<int, bool> visited;
//     map<int, list<int>> m;
//     vector<int> ans;
//     adj(m, edges);
//     for (int x = 0; x < k; x++)
//     {
//         if (visited[x] != true)
//         {
//             bfs(m, visited, x, ans);
//         }
//     }
// }
// DFS//
// void adj(map<int, list<int>> &m, vector<pair<int, int>> edges)
// {
//     for (int x = 0; x < edges.size(); x++)
//     {
//         int u = edges[x].first;
//         int v = edges[x].second;
//         m[u].push_back(v);
//         m[v].push_back(u);
//     }
// }
// void dfs(map<int, bool> visited, vector<int> ans, map<int, list<int>> adj, int node)
// {
//     ans.push_back(node);
//     visited[node] = true;
//     for (auto i : adj[node])
//     {
//         if (visited[i] != true)
//         {
//             dfs(visited, ans, adj, i);
//         }
//     }
// }
// int main()
// {
//     map<int, list<int>> m;
//     map<int, bool> visited;
//     vector<pair<int, int>> edges;
//     vector<int> ans;
//     adj(m, edges);
//     int node;
//     int k;
//     for (int x = 0; x < k; x++)
//     {
//         if (visited[x] != true)
//         {
//             dfs(visited, ans, m, node);
//         }
//     }
// }
