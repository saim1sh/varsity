#include<bits/stdc++.h>

using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

void addEdge(vector<vector<int>> &adj, int u, int v)
{
   adj[u].push_back(v);
   adj[v].push_back(u);
}

void BFS(int start, const vector<vector<int>> &adj, int vertices)
{
   vector<int> color(vertices, WHITE);
   queue<int> q;

   color[start] = GRAY;
   q.push(start);

   while (!q.empty())
   {
      int u = q.front();
      q.pop();
      cout << u << " ";

      for (int v : adj[u])
      {
         if (color[v] == WHITE)
         {
            color[v] = GRAY;
            q.push(v);
         }
      }

      color[u] = BLACK;
   }
   cout << endl;
}

int main()
{
   int vertices, edges, u, v, start;
   cout << "Enter number of vertices: ";
   cin >> vertices;

   cout << "Enter number of edges: ";
   cin >> edges;

   vector<vector<int>> adj(vertices);

   cout << "Enter edges (u v):" << endl;
   for (int i = 0; i < edges; i++)
   {
      cin >> u >> v;
      addEdge(adj, u, v);
   }

   cout << "Enter starting vertex for BFS: ";
   cin >> start;

   cout << "BFS Traversal: ";
   BFS(start, adj, vertices);

   return 0;
}
