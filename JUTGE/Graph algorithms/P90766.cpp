#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char>> Graph;

int num_tresors(const Graph& G, int fil, int col, vector<vector<bool>>& V, int& res){
  if(fil >= G.size() or col >= G[0].size()) return 0;
  else{
    if(not V[fil][col] and G[fil][col] != 'X'){
      V[fil][col] = true;
      if(G[fil][col] == 't') ++res;
      num_tresors(G,fil-1,col,V,res);
      num_tresors(G,fil+1,col,V,res);
      num_tresors(G,fil,col-1,V,res);
      num_tresors(G,fil,col+1,V,res);
    }
  }
  return 0;
}

int main(){
  int n, m;
  char a;
  cin >> n >> m;
  Graph G(n, vector<char>(m));
  for(int i = 0 ; i < n ; ++i){
    for(int j = 0 ; j < m ; ++j){
      cin >> a;
      G[i][j] = a;
    }
  }
  int f, c;
  cin >> f >> c;
  vector<vector<bool>> vis (n,vector<bool>(m,false));
  int res = 0;
  num_tresors(G,f-1,c-1,vis,res);
  cout << res << endl;
  return res;
}
