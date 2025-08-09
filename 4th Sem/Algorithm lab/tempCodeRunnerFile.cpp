#include <bits/stdc++.h>

using namespace std;

void bfs(unordered_map<char, vector<char>> &graph, char start)
{
   set<char> visited;
   queue<char> q;

   q.push(start);
   visited.insert(start);
   while (!q.empty())
   {
      char node = q.front();
      q.pop();
      cout << node << " ";

      for (char neighbor : graph[node])
      {
         if (visited.find(neighbor) == visited.end())
         {
            q.push(neighbor);
            visited.insert(neighbor);
         }
      }
   }
}

int main()
{
   unordered_map<char, vector<char>> graph;
   graph['A'] = {'B', 'C'};
   graph['B'] = {'D', 'E'};
   graph['C'] = {'F'};
   graph['D'] = {};
   graph['E'] = {'F'};
   graph['F'] = {};

   cout << "BFS Traversal: ";
   bfs(graph, 'A');

   return 0;
}
