//NO PASSA ELS PRIVATS

#include <iostream>
#include <vector>
#include <list>

using namespace std;

typedef vector<list<int>> Graph;

void llegir_graf(Graph& A){
  int m;
  cin >> m;
  for(int i = 0; i < m; ++i){
    int v1,v2;
    cin >> v1 >> v2;
    A[v1].push_back(v2);
    A[v2].push_back(v1);
  }
}

bool dos_colors(const Graph& G , vector<bool>& V, vector<bool>& vermells,  int vertex, bool es_vermell){
  if(not V[vertex]){
    V[vertex] = true;
    vermells[vertex] = es_vermell;
    for(int v : G[vertex]){
      if(not V[v]) dos_colors(G,V,vermells,v,!es_vermell);
      else
        if(es_vermell == vermells[v]) return false;
    }
  }
  return true;
}

int main(){
  int n;
  while(cin >> n){
    Graph G (n);
    llegir_graf(G);
    vector<bool> vis(n,false);
    vector<bool> vermells(n);
    bool stop = false;
    for(int i = 0; i < n and not stop ; ++i){
      if(not vis[i]) {
        if (not dos_colors(G,vis,vermells,i,true)) stop = true;
      }
    }
    if(not stop) cout <<"yes"<< endl;
    else cout << "no" << endl;
  }
}
