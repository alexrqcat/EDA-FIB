#include <iostream>
#include <vector>
#include <set>
#include <list>

using namespace std;

typedef vector<list<int>> Graph;

void llegir_graf(Graph& G, int n_tasques){
  while(n_tasques > 0){
    int v1,v2;
    cin >> v1 >> v2;
    G[v1].push_back(v2);
    --n_tasques;
  }
}
void escriure_llista(list<int>& L){
  while(not L.empty()){
    cout << L.front();
    L.pop_front();
    if(not L.empty()) cout << " ";
  }
}

list<int> ordenacio_topologica_tasques(const Graph& G){
  int n = G.size();
  vector<int> graus(n,0);
  for(int i = 0; i < n; ++i){
    for(int v : G[i]){
      ++graus[v];
    }
  }
  set<int> S;
  for(int i = 0; i < n; ++i){
    if(graus[i] == 0) S.insert(i);
  }
  list<int> res;
  while(not S.empty()){
    set<int>:: iterator it = S.begin();
    int aux = *it;
    S.erase(aux);
    res.push_back(aux);
    for(int v : G[aux])
      if(--graus[v] == 0) S.insert(v);
  }
  return res;
}
int main(){
  int n, m;
  while(cin >> n >> m){
    Graph G(n);
    llegir_graf(G,m);
    list<int> resultat = ordenacio_topologica_tasques(G);
    escriure_llista(resultat);
    cout << endl;
  }
}

//Àlex Rubio i Quintana
