#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef  vector<vector<char>> Graph;

int distancia_tresor(int fila, int col, const Graph& G){
  queue<pair<int,int>> Q;
  vector<vector<int>> dis(fila+1, vector<int> (col+1,-1));
  int dist = 0;
  Q.push(make_pair(fila,col));
  while(not Q.empty()){
    pair<int,int> pos = Q.front();
    Q.pop();
    int f,c;
    f = pos.first;
    c = pos.second;
    dist = dis[f][c];
    cerr << "xivato1" << endl;
    if(f < fila and dis[f+1][c] == -1 and G[f+1][c] != 'X'){
      if(G[f+1][c] == 't') return dist;
      Q.push(make_pair(f+1,c));
      dis[f+1][c] = ++dist;
      cerr << "xivato2" << endl;
    }
    else if(f > 0 and dis[f-1][c] == -1 and G[f-1][c] != 'X'){
      if(G[f-1][c] == 't') return dist;
      Q.push(make_pair(f-1,c));
      dis[f-1][c] = ++dist;
      cerr << "xivato3" << endl;
    }
    else if(c > 0 and dis[f][c-1] == -1 and G[f][c-1] != 'X'){
      if(G[f][c-1] == 't') return dist;
      Q.push(make_pair(f,c-1));
      dis[f][c-1] = ++dist;
      cerr << "xivato4" << endl;
    }
    else if(c < col and dis[f][c+1] == -1 and G[f][c+1] != 'X'){
      if(G[f][c+1] == 't') return dist;
      Q.push(make_pair(f,c+1));
      dis[f][c+1] = ++dist;
      cerr << "xivato5" << endl;
    }
    cerr << "xivato6" << endl;
  }
  return -1;
}

int main(){
  int n, m;
  cin >> n >> m;
  char a;
  Graph mapa(n,vector<char>(m));
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m ; ++j){
      cin >> a;
      mapa[i][j] = a;
    }
  }
  int f,c;
  cin >> f >> c;
  cout << distancia_tresor(f-1,c-1,mapa) << endl;
}
