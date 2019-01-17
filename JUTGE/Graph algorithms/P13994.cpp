#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

#define INT_MAX -1

typedef vector<vector<pair<int,int>>> Graph;

void llegir_graf(Graph& A){
  int m;
  cin >> m;
  int src,dest,cost;
  while(m > 0){
    cin >> src >> dest >> cost;
    A[src].push_back(make_pair(dest,cost));
    --m;
  }
}
void escriure_llista(list<int>& L){
  while(!L.empty()){
    if(L.front() == L.back()) cout << L.front();
    else
      cout << L.front() <<" ";
    L.pop_front();
  }
}

list<int> cami_mes_curt(const Graph& G, int src, int dest){
  vector<int> cost(G.size(),INT_MAX);
  list<int> L;
  bool cami_trobat = false;
  priority_queue< pair<pair<int,int>,list<int>>, vector<pair<pair<int,int>,list<int>>>, greater<pair<pair<int,int>,list<int>>>>  PQ; //primer component cost, segon component vertex;
  cost[src] = 0;
  PQ.push(make_pair(make_pair(cost[src],src),L));
  while(!PQ.empty()){
    int vertex = PQ.top().first.second;
    int c = PQ.top().first.first;
    L = PQ.top().second;
    //cout << "Estic al vertex " << vertex <<" amb cost " << c << endl;
    PQ.pop();
    L.push_back(vertex);
    if(vertex == dest) {
      cami_trobat = true;
      return L;
    }
    for(auto v : G[vertex]){
      if(cost[v.first] == -1 or cost[v.first] > c + v.second){
        cost[v.first] =  c + v.second;
        PQ.push(make_pair(make_pair(cost[v.first],v.first),L));
      }
    }
  }
  if(! cami_trobat)
    while(! L.empty()) L.pop_front();
  return L;
}
int main(){
  int n;
  while(cin >> n){
    Graph G(n);
    llegir_graf(G);
    int origen, desti;
    cin >> origen >> desti;
    list<int> L = cami_mes_curt(G,origen,desti);
    if(L.empty()) cout << "no path from " << origen <<" to " << desti;
    else
      escriure_llista(L);
    cout << endl;
    }
}
