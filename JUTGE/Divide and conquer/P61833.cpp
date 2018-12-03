#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> Fila;
typedef vector<Fila> Matriu;

Matriu mult_matriu(const Matriu& mat, int n, int m){
  Matriu aux = mat;
  if(n == 0){
    aux[0][0] = 1;
    aux[1][0] = 0;
    aux[0][1] = 0;
    aux[1][1] = 1;
    return aux;
  }
  while(n > 0){
    aux[0][0] = (mat[0][0]*mat[0][0] + mat[0][1]*mat[1][0])%m;
    aux[1][0] = (mat[1][0]*mat[0][0] + mat[1][1]*mat[1][0])%m;
    aux[0][1] = (mat[0][0]*mat[0][1] + mat[0][1]*mat[1][1])%m;
    aux[1][1] = (mat[1][0]*mat[0][1] + mat[1][1]*mat[1][1])%m;
    --n;
  }
  return aux;
}

int main(){
  int n;
  Matriu M(2,Fila(2));
  for(int i = 0; i < 2 ; ++i){ //llegim la matriu
    for(int j = 0; j < 2; ++j){
      cin >> n;
      M[i][j] = n;
    }
  }
  int m;
  cin >> n >> m;
  M = mult_matriu(M,n,m);
  for(int i = 0; i < 2 ; ++i){
    for(int j = 0; j < 2; ++j){
      cout << M[i][j] << " ";
    }
    cout << endl;
  }
}

//Alex Rubio i Quintana - FALTA ACABAR
