//NO PASSA ELS PRIVATS !

#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;

#define INT_MAX -1

typedef vector<int> VI;
typedef vector<list<pair<int,int>>> trajectes;
typedef priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> PQ;

void llegir_trajectes (trajectes& T, int m){
  while(m > 0){
    --m;
    int c1, c2 , cost;
    cin >> c1 >> c2 >> cost;
    T[c1].push_back(make_pair(c2,cost));
    T[c2].push_back(make_pair(c1,cost));
  }
}

int rutes_barates(const trajectes& T, int src, int dest, const VI& ciutats){
  vector<int> costs (T.size(),INT_MAX);
  costs[src] = 0;
  PQ PRIO;
  PRIO.push(make_pair(0,src));
  while(!PRIO.empty()){
    int vertex = PRIO.top().second;
    int cost = PRIO.top().first;
    PRIO.pop();
    if(vertex == dest) return cost-ciutats[dest];
    for(pair<int,int> p : T[vertex]){
      if(costs[p.first] == INT_MAX or costs[p.first] > cost + p.second + ciutats[p.first]){
        costs[p.first] = cost + p.second + ciutats[p.first];
        PRIO.push(make_pair(costs[p.first],p.first));
      }
    }
  }
  return INT_MAX;
}

int main(){
  int n, m;
  cin >> n >> m;
  VI ciutats(n);
  for(int i = 0; i < n ; ++i){
    int cost;
    cin >> cost;
    ciutats[i] = cost;
  }
  trajectes T (n);
  llegir_trajectes(T,m);
  int origen, desti;
  while(cin >> origen >> desti){
    int res;
    res = rutes_barates(T,origen,desti,ciutats);
    if(res != INT_MAX){
      if(res < 0) res = 0;
      cout << "c(" << origen << "," << desti << ") = " << res << endl;
    }
    else
      cout << "c(" << origen << "," << desti << ") = +oo" << endl;
  }
}
