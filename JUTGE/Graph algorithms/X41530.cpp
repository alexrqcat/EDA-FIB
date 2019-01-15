#include <iostream>
#include <vector>
#include <list>

using namespace std;

typedef vector<list<int>> Graph;

void llegir_graf (int n_arestes, Graph& G){
  int v1,v2;
  for(int j = 0 ; j < n_arestes ; ++j){
    cin >> v1 >> v2;
    G[v1].push_back(v2);
    G[v2].push_back(v1);
    }
  }

bool es_bosc(const Graph& G, int vertex, int old_v, vector<bool>& V){
  if(not V[vertex]){
    V[vertex] = true;
    for(int v : G[vertex]){
      if(v != old_v){
        if(V[v]) return false;
        if(not es_bosc(G,v,vertex,V)) return false;
      }
    }
  }
    return true;
}

int main(){
  int v,a;
  while(cin >> v >> a){
    Graph G(v);
    llegir_graf(a,G);
    int res= 0;
    bool aux = true;
    vector<bool> vis (G.size(),false);
    if(a == 0) cout << v << endl;
    else{
      for(int i = 0 ; i < v; ++i){
        if(not vis[i]){
          ++res;
          if(not es_bosc(G,i,i, vis)) aux = false;
        }
      }
    }
    if(not aux) cout << "no" << endl;
    else if (a != 0) cout << res << endl;
  }
}
