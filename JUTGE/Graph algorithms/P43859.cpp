#include <iostream>
#include <vector>
#include <queue>

#define INT_MAX -1

using namespace std;

typedef vector<vector<pair<int,int>>> Graph;

void llegir_graf(Graph& A, int m){
  int src,dest,cost;
  while(m > 0){
    cin >> src >> dest >> cost;
    A[src].push_back(make_pair(dest,cost));
    --m;
  }
}
int distancia_min(int src, const int& dest, const Graph& G){
  vector<int> cost(G.size(),INT_MAX);
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> PQ;
  cost[src] = 0;
  PQ.push(make_pair(cost[src],src));
  while(!PQ.empty()){
    int vertex = PQ.top().second;
    int cost_vertex = PQ.top().first;
    PQ.pop();
    if(vertex == dest) return cost_vertex;
    for(auto v : G[vertex]){
      if(cost[v.first] == -1 or cost[v.first] > cost_vertex + v.second){
        cost[v.first] = cost_vertex + v.second;
        PQ.push(make_pair(cost[v.first],v.first));
      }
    }
  }
  return INT_MAX;
}
int main(){
  int n, m;
  while(cin >> n >> m){
    Graph G (n);
    llegir_graf(G,m);
    int src, dest;
    cin >> src >> dest;
    int dist = distancia_min(src,dest,G);
    if(dist != INT_MAX) cout << dist << endl;
    else cout <<"no path from " << src << " to " << dest << endl;
  }
}

//Àlex Rubio i Quintana
