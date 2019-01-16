#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef  vector<vector<char>> Graph;

void llegir_graf(int files, int cols, Graph& G){
  char a;
  for(int i = 0; i < files; ++i){
    for(int j = 0; j < cols ; ++j){
      cin >> a;
      G[i][j] = a;
    }
  }
}

int distancia_tresor(int fila, int col, const Graph& G){
  queue<pair<int,int>> Q;
  Q.push(make_pair(fila,col));
  vector<vector<int>> distancies (G.size(), vector<int>(G[0].size(),-1));
  distancies[fila][col] = 0;
  while(!Q.empty()){
    int f,c;
    f = Q.front().first;
    c = Q.front().second;
    Q.pop();
    if(f < G.size()-1 and distancies[f+1][c] == -1 and G[f+1][c] != 'X'){
      distancies[f+1][c] = distancies[f][c]+1;
      if(G[f+1][c] == 't') return distancies[f+1][c];
      Q.push(make_pair(f+1,c));
    }
    if(f > 0 and distancies[f-1][c] == -1 and G[f-1][c] != 'X'){
      distancies[f-1][c] = distancies[f][c]+1;
      if(G[f-1][c] == 't') return distancies[f-1][c];
      Q.push(make_pair(f-1,c));
    }
    if(c > 0 and distancies[f][c-1] == -1 and G[f][c-1] != 'X'){
      distancies[f][c-1] = distancies[f][c]+1;
      if(G[f][c-1] == 't') return distancies[f][c-1];
      Q.push(make_pair(f,c-1));
    }
    if(c < G[0].size()-1 and distancies[f][c+1] == -1 and G[f][c+1] != 'X'){
      distancies[f][c+1] = distancies[f][c]+1;
      if(G[f][c+1] == 't') return distancies[f][c+1];
      Q.push(make_pair(f,c+1));
    }
  }
  return -1;
}

int main(){
  int n, m;
  cin >> n >> m;
  Graph mapa(n,vector<char>(m));
  llegir_graf(n,m,mapa);
  int f,c;
  cin >> f >> c;
  int dist = distancia_tresor(f-1,c-1,mapa);
  if (dist != -1) cout <<"distancia minima: " <<  dist << endl;
  else cout << "no es pot arribar a cap tresor" << endl;
}

//Àlex Rubio i Quintana
