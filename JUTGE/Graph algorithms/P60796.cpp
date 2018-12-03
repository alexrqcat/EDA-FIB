#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<char> Fila;
typedef vector<Fila> Graph;
typedef vector<bool> Fila_vis;
typedef vector <Fila_vis> Mat_vis;

int bfs_dist(const Graph& G, const int f, const int c){
  Mat_vis vis (G.size(),Fila_vis(G[0].size(),false));
  queue <pair <int,int> > Q;
  queue<int> distQ;
  Q.push(make_pair(f,c));
  distQ.push(0); //distancia inicial
  vis[f][c] = true;
  while(!Q.empty()){
    pair<int,int> act = Q.front();
    int x = act.first;
    int y = act.second;
    int dist = distQ.front()+1; //la nova distancia minima
    //Casella superior
    if(y > 0 and not vis[x][y-1]  and G[x][y-1] != 'X'){
      if(G[x][y-1] == 't') return dist;
      Q.push(make_pair(x,y-1));
      distQ.push(dist);
      vis[x][y-1] = true;
    }
    //Casella inferior
    if(y < G[0].size()-1 and not vis[x][y+1] and G[x][y+1] != 'X'){
      if(G[x][y+1] == 't') return dist;
      Q.push(make_pair(x,y+1));
      distQ.push(dist);
      vis[x][y+1] = true;
    }
    //Casella esquerra
    if(x > 0 and not vis[x-1][y] and G[x-1][y] != 'X'){
      if(G[x-1][y] == 't') return dist;
      Q.push(make_pair(x-1,y));
      distQ.push(dist);
      vis[x-1][y] = true;
    }
    //Casella dreta
    if(x < G.size()-1 and not vis[x+1][y] and G[x+1][y] != 'X'){
      if(G[x+1][y] == 't') return dist;
      Q.push(make_pair(x+1,y));
      distQ.push(dist);
      vis[x+1][y] = true;
    }
    Q.pop(); //ens carreguem la casella visitada
    distQ.pop(); //ens carreguem la distancia anterior
  }
  return -1;
}
void llegir_matriu(Graph& G, int n, int m){
  for(int i = 0; i < n; ++i){ //llegim matriu
    for(int j = 0; j < m; ++j){
      char c;
      cin >> c;
      G[i][j] = c;
    }
  }
}
int main(){
  int n,m;
  cin >> n >> m;
  Graph G(n,Fila(m));
  llegir_matriu(G,n,m);
  int f,c;
  cin >> f >> c;
  int dist = bfs_dist(G,f-1,c-1);
  if(dist == -1) cout <<"no es pot arribar a cap tresor" << endl;
  else cout <<"distancia minima: "<< dist << endl;
}

//Alex Rubio i Quintana
