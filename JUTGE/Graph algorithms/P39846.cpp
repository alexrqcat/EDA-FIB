#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef vector<vector<char>> Graph;

void llegir_graf(Graph& G){
  char c;
  for(int i = 0; i < G.size(); ++i){
    for(int j = 0 ; j < G[0].size(); ++j){
      cin >> c;
      G[i][j] = c;
    }
  }
}

int distancia_max(int fila, int col, const Graph& G){
  queue<pair<int,int>> Q;
  vector<vector<int>> distancies (G.size(),vector<int>(G[0].size(),-1));
  distancies[fila][col] = 0;
  int dist_max = -1;
  Q.push(make_pair(fila,col));
  while(!Q.empty()){
    int f = Q.front().first;
    int c = Q.front().second;
    Q.pop();
    if(f < G.size()-1 and distancies[f+1][c] == -1 and G[f+1][c] != 'X'){
      distancies[f+1][c] = distancies[f][c] + 1;
      if(G[f+1][c] == 't') dist_max = max(dist_max,distancies[f+1][c]);
      Q.push(make_pair(f+1,c));
    }
    if(f > 0 and distancies[f-1][c] == -1 and G[f-1][c] != 'X'){
      distancies[f-1][c] = distancies[f][c] + 1;
      if(G[f-1][c] == 't') dist_max = max(dist_max,distancies[f-1][c]);
      Q.push(make_pair(f-1,c));
    }
    if(c > 0 and distancies[f][c-1] == -1 and G[f][c-1] != 'X'){
      distancies[f][c-1] = distancies[f][c] + 1;
      if(G[f][c-1] == 't') dist_max = max(dist_max,distancies[f][c-1]);
      Q.push(make_pair(f,c-1));
    }
    if(c < G[0].size()-1 and distancies[f][c+1] == -1 and G[f][c+1] != 'X'){
      distancies[f][c+1] = distancies[f][c] + 1;
      if(G[f][c+1] == 't') dist_max = max(dist_max,distancies[f][c+1]);
      Q.push(make_pair(f,c+1));
    }
  }
  return dist_max;
}

int main(){
  int n,m;
  cin >> n >> m;
  Graph mapa(n,vector<char>(m));
  llegir_graf(mapa);
  int f,c;
  cin >> f >> c;
  int dist = distancia_max(f-1,c-1,mapa);
  if(dist != -1) cout <<"distancia maxima: " << dist << endl;
  else
    cout <<"no es pot arribar a cap tresor" << endl;
}
