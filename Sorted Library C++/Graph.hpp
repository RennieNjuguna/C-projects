#pragma once
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Graph{

private:

vector <vector <int> > adjacency_list; // mandatory

public:

Graph() {} //default constructor

Graph(int); // one argument constructor
  
void addEdge(int, int);//add a new edge from vertex v1 to v2
//edge also needs to be added from v2 to v1
  
vector<int> BFS(); // Implement Breadth First Search algorithm, using an STL queue
// Using an STL queue is mandatory

vector<int> BFS_Shortest_Distance(int); // Find Shortest Distance from src vertex
// Using an STL queue is mandatory
  
void print_graph(); //optional, for debugging
};

Graph::Graph(int v){

adjacency_list.resize(v);
  
}

void Graph::addEdge(int a, int b){

adjacency_list[a].push_back(b);
adjacency_list[b].push_back(a);
}

vector <int> Graph::BFS(){
   queue<int> q;
   //start from vertex 0
   vector<bool> v(adjacency_list.size(),false);
q.push(0);
v[0] = true;
   vector <int> bfs;
while (!q.empty()) {
  
int f = q.front();
q.pop();
  
       bfs.push_back(f);
  
// Enqueue all adjacent of f and mark them visited
for (int i = 0; i < adjacency_list[f].size(); i++) {
if (!v[adjacency_list[f][i]]) {
q.push(adjacency_list[f][i]);
v[adjacency_list[f][i]] = true;
}
}
}
return bfs;
  
}

vector <int> Graph::BFS_Shortest_Distance(int s) {
   // in a unweighted graph the shortest distance can be found using BFS
   queue <int> queue;
   //number of vertices in graph
   int n = adjacency_list.size();
bool visited[n];
//this vector is used to store the shortest distance of each vertex from s
   vector <int> dist(n);
   //initialization
for (int i = 0; i < n; i++) {
visited[i] = false;
dist[i] = INT_MAX;
}
  
// now s is first to be visited and
// distance from s to itself should be 0
visited[s] = true;
dist[s] = 0;
queue.push(s);
  
// standard BFS algorithm with some changes
while (!queue.empty()) {
int u = queue.front();
queue.pop();
for (int i = 0; i < adjacency_list[u].size(); i++) {
if (visited[adjacency_list[u][i]] == false)
           {
visited[adjacency_list[u][i]] = true;
//update the distance of node
dist[adjacency_list[u][i]] = dist[u] + 1;
queue.push(adjacency_list[u][i]);
}
}
}
return dist;
}

void Graph::print_graph(){

for(int i=0;i<adjacency_list.size();i++)
{
   for(int j=0;j<adjacency_list[i].size();j++)
       cout<<adjacency_list[i][j]<<" ";
   cout<<endl;
}
}