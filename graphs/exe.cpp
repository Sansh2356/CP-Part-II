// #include <iostream>
// #include <stack>
// #include <set>
// #include <algorithm>
// #include <unordered_set>
// #include <string>
// #include <vector>
// #include <queue>
// #include <unordered_map>
// using namespace std;

// void adj_mat(int u, int v, vector<pair<int, int>> edges, vector<vector<int>> &adj)
// {
//   for (int x = 0; x < edges.size(); x++)
//   {
//     pair<int, int> p = edges[x];
//     int w1;
//     cout << "Enter weight between" << p.first << " " << p.second << endl;
//     cin >> w1;
//     adj[p.first][p.second] = 1;
    
//     adj[p.second][p.first] = 1;
//   }
// }

// void adj_mat(vector<vector<int>>edges){

// }

// // void bfs(vector<vector<int>> &adj, int vertices, unordered_map<int, bool> &m)
// // {
// //   queue<int> q;
// //   q.push(0);
// //   m[q.front()] = true;
// //   while (q.empty() != true)
// //   {
// //     int k = q.front();
// //     cout << k << " ";
// //     q.pop();
// //     for (int x = 0; x < adj[k].size(); x++)
// //     {
// //       if (adj[k][x] == 1 && m[x] != true)
// //       {
// //         q.push(x);
// //         m[x] = true;
// //       }
// //     }
// //   }
// //   cout << endl;
// // }
// // void dfs(vector<vector<int>> &adj, int u, unordered_map<int, bool> &m, int edge)
// // {
// //   if (m[edge] == true)
// //     return;
// //   m[edge] = true;
// //   for (auto i : adj[edge])
// //   {
// //     if (m[i] != true)
// //     {
// //       dfs(adj, u, m, i);
// //     }
// //   }
// // }
// // bool is_cycle(vector<vector<int>> &adj, int u, unordered_map<int, bool> &visited)
// // {
// //   queue<int> q1;
// //   queue<int> parent;
// //   q1.push(0);
// //   visited[0] = true;
// //   while (!q1.empty())
// //   {
// //     int k = q1.front();
// //     q1.pop();
// //     for (auto i : adj[k])
// //     {
// //       if (visited[i] != true && parent.back() != k)
// //       {
// //         return true;
// //       }
// //       if (visited[i] != true)
// //       {
// //         q1.push(k);
// //         visited[i] = true;
// //         parent.push(k);
// //       }
// //     }
// //   }
// //   return false;
// // }
// // /*
// // #include<unordered_map>
// // #include <queue>
// // string bfs(unordered_map<int,vector<int>>&adj,unordered_map<int,bool>&visited){
// //     int cnt = 0;
// //     queue<int>q;
// //     q.push(1);
// //     visited[1]=true;
// //     while(q.empty() != true){
// //         int k=q.front();
// //         q.pop();
// //         for(auto i:adj[k]){
// //             if(visited[i] != true){
// //                 q.push(i);
// //                 visited[i]=true;
// //             }
// //             else{cnt++;}
// //         }
// //          if(cnt>=2)return "Yes";
// //     }

// //     return "No";
// // }
// // string cycleDetection (vector<vector<int>>& edges, int n, int m)
// // {
// //     unordered_map<int,vector<int>>adj;
// //     unordered_map<int,bool>visited;
// //     for(int x=0;x<edges.size();x++){
// //         pair<int,int>p={edges[x][0],edges[x][1]};
// //         adj[p.first].push_back(p.second);
// //         adj[p.second].push_back(p.first);
// //     }
// //     for(auto i:adj){
// //         cout<<i.first<<" --- ";
// //         for(auto j:i.second){
// //             cout<<j<<" ";
// //         }
// //         cout<<endl;
// //     }
// //     for(int x=0;x<n;x++){
// //         visited[x+1]=false;
// //     }
// //     return bfs(adj,visited);
// // }

// // */
// // void topological_sort(vector<vector<int>> &adj, int u, unordered_map<int, bool> &visited, int node, stack<int> &st)
// // {
// //   if (visited[node] == true)
// //     return;
// //   visited[node] = true;
// //   for (auto i : adj[node])
// //   {
// //     if (visited[node] != true)
// //     {
// //       topological_sort(adj, u, visited, i, st);
// //     }
// //   }
// //   st.push(node);
// // }
// // void shortest_path(vector<vector<int>> &adj, unordered_map<int, bool> &visited, int src, int dest)
// // {
// //   unordered_map<int, int> parent;
// //   queue<int> q;
// //   q.push(src);
// //   visited[src] = true;
// //   while (!q.empty() && q.front() != dest)
// //   {
// //     int k = q.front();
// //     q.pop();
// //     for (auto i : adj[k])
// //     {
// //       if (visited[i] != true)
// //       {
// //         q.push(i);
// //         visited[i] = true;
// //         parent[i] = k;
// //       }
// //     }
// //   }
// // }
// // bool cmp(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2)
// // {
// //   return p1.first < p2.first;
// // }
// // // Finding the parent of the nodes to be union recursively
// // // if two nodes belong to same componenet then both will have same parent
// // int find_parent(int node, vector<int> &parent)
// // {
// //   if (parent[node] == node)
// //     return node;
// //   return parent[node] = find_parent(parent[node], parent);
// // }
// // // To perform union between 2 nodes and merging them
// // void union_parent(int u, int v, vector<int> &rank, vector<int> &parent)
// // {
// //   int par1 = find_parent(u, parent);
// //   int par2 = find_parent(v, parent);
// //   if (rank[par1] < rank[par2])
// //   {
// //     parent[par1] = par2;
// //     rank[par2] += 1;
// //   }
// //   else if (rank[par1] > rank[par2])
// //   {
// //     parent[par2] = par1;
// //     rank[par1] += 1;
// //   }
// //   else
// //   {
// //     parent[par1] = par2;
// //     rank[par1]++;
// //   }
// //   return;
// // }
// // // To build MST using Kruskal algorithm//
// // // Requiring the adjacent list to be sorted in the ascending order of their
// // // weights
// // int kruskal(vector<vector<pair<int, pair<int, int>>>> adj, int u, int v)
// // {
// //   sort(adj.begin(), adj.end(), cmp);
// //   int wt = 0;
// //   vector<int> parent(u);
// //   vector<int> rank(u, 0);
// //   for (int x = 0; x < u; x++)
// //   {
// //     parent[x] = x;
// //   }
// //   for (int x = 0; x < adj.size(); x++)
// //   {
// //     int node1 = adj[x][0].second.second;
// //     int node2 = adj[x][0].second.first;
// //     int weight = adj[x][0].first;
// //     int par1 = find_parent(node1, parent);
// //     int par2 = find_parent(node2, parent);
// //     if (par1 != par2)
// //     {
// //       union_parent(u, v, rank, parent);
// //     }
// //   }
// //   return wt;
// // }
// // void prims_algo(vector<vector<int>> &adj, int v)
// // {
// //   vector<int> parent(v + 1, -1);
// //   vector<int> key(v + 1, INT_MAX);
// //   vector<int> mst(v + 1, false);
// //   key[0] = 0;
// //   int mini = INT_MAX;
// //   int node = -1;
// //   // finding the minimum which is not already present in the mst
// //   for (int x = 0; x < key.size(); x = +1)
// //   {
// //     if (key[x] < mini && mst[x] != true)
// //     {
// //       mini = key[x];
// //       node = x;
// //     }
// //   }
// //   // checking all the adjacent nodes and updating if their already existing weights is less than
// //   // minima and then also update the parent of that nodes
// //   mst[node] = true;
// //   for (auto i : adj[node])
// //   {
// //     if (mst[i] != true && key[i] < 1)
// //     {
// //       key[i] = weight;
// //       parent[i] = node;
// //     }
// //   }
// // }

// void dijkstra(vector<vector<int>> &adj, unordered_map<int, bool> &visited, int v, int src)
// {
//   vector<int> dist(v, INT_MAX);
//   dist[src] = 0;
//   set<pair<int, int>> st;
//   st.insert({0, src});
//   while (st.empty() != true)
//   {
//     pair<int, int> p = *st.begin();
//     int k = p.second;
//     st.erase(st.begin());
//     for (auto i : adj[k])
//     {
//       if (p.second + p.first< dist[i])
//       {
//         dist[i] = p.second + p.first ;
//         st.insert({i, dist[i]});
//       }
//     }
//   }
// }

// int main()
// {

//   int u, v;
//   cin >> u >> v;

//   vector<vector<int>> adj(u, vector<int>(u, 0));

//   // edges = {(0,1),(0,4),(4,1),(4,3),(1,3),(1,2),(3,2)}
//   vector<vector<int>> edges = {{0, 1}, {0, 4}, {4, 1}, {4, 3}, {1, 3}, {1, 2}, {3, 2}};


// }

#include <iostream>
using namespace std;
#include <limits.h>

#define V 9

int minDistance(int dist[], bool sptSet[])
{


	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}


void printSolution(int dist[])
{
	cout << "Vertex \t Distance from Source" << endl;
	for (int i = 0; i < V; i++)
		cout << i <<" "<< dist[i] << endl;
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V]; 
	

	bool sptSet[V]; 

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	dist[src] = 0;

	
	for (int count = 0; count < V - 1; count++) {

		int u = minDistance(dist, sptSet);


		sptSet[u] = true;


		for (int v = 0; v < V; v++)

			if (!sptSet[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	printSolution(dist);
}
int main()
{

	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	dijkstra(graph, 0);

	return 0;
}


