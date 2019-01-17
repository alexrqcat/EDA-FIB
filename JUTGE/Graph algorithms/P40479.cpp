#include <iostream>
#include <list>
#include <vector>

using namespace std;

typedef vector<vector<char>> Tauler;

list<pair<int,int>> llegir_tauler(Tauler& A){
  list<pair<int,int>> L;
  for(int i = 0; i < A.size(); ++i){
    for(int j = 0; j < A[0].size(); ++j){
      char c;
      cin >> c;
      A[i][j] = c;
      if(c!= '.' and c!= '#') L.push_back(make_pair(i,j));
    }
  }
  return L;
}
void pintar_tauler_rec(Tauler& T, pair<int,int> FC, const char& car, vector<vector<bool>>& vis){
  int f = FC.first;
  int c = FC.second;
  if(!vis[f][c]){
    vis[f][c] = true;
    if(T[f][c] != '#'){
      T[f][c] = car;
      if(f + 1 < T.size() and T[f+1][c] == '.') pintar_tauler_rec(T,make_pair(f+1,c),car,vis);
      if(f + -1 >= 0 and T[f-1][c] == '.') pintar_tauler_rec(T,make_pair(f-1,c),car,vis);
      if(c + 1 < T[0].size() and T[f][c+1] == '.') pintar_tauler_rec(T,make_pair(f,c+1),car,vis);
      if(c - 1 >= 0 and T[f][c-1] == '.') pintar_tauler_rec(T,make_pair(f,c-1),car,vis);
    }
  }
}
void pintar_tauler(Tauler& T, list<pair<int,int>>& L){
  vector<vector<bool>> vis (T.size(),vector<bool>(T[0].size(),false));
  while(!L.empty()){ //mentre hi hagi lletres que encara no he utilitzat
    pintar_tauler_rec(T,L.front(),T[L.front().first][L.front().second],vis);
    L.pop_front();
  }
  for(int i = 0; i < T.size() ; ++i){ // escric el resultat
    for(char c : T[i])
      cout << c ;
    cout << endl;
  }
}
int main(){
  int n, m;
  while(cin >> n >> m){
    Tauler T(n,vector<char>(m));
    list<pair<int,int>> L = llegir_tauler(T); //torna la llista de caselles on hi ha una lletra
    pintar_tauler(T,L);
    cout << endl;
  }
}

//Àlex Rubio i Quintana
