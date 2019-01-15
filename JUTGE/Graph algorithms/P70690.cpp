#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char>> Graph;

bool es_possible(const Graph& G, int fil, int col, vector<vector<bool>>& V){
  if(fil >= G.size() or col >= G[0].size()) return false;
  if(not V[fil][col]){
    if(G[fil][col] == 't') return true;
    V[fil][col] = true;
    if(G[fil][col] != 'X'){
      if (es_possible(G,fil-1,col,V)) return true;
      if (es_possible(G,fil+1,col,V)) return true;
      if (es_possible(G,fil,col-1,V)) return true;
      if (es_possible(G,fil,col+1,V)) return true;
    }
    else
      return false;
  }
  return false;
}

int main(){
  int n , m;
  char a;
  cin >> n >> m;
  Graph G(n,vector<char>(m));
  for(int i = 0 ; i < n; ++i){
    for(int j = 0 ; j < m ; ++j){
      cin >> a;
      G[i][j] = a;
    }
  } //llegim el graf
  vector<vector<bool>> vis (n,vector<bool>(m,false));
  int f ,c;
  cin >> f >> c;
  if(es_possible(G,f-1,c-1,vis)) cout << "yes" << endl;
  else cout << "no" << endl;
}
