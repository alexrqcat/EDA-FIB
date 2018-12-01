#include <iostream>
#include <vector>

using namespace std;

int posicio(const int a, const vector<int>& v, int esq, int dre){
  if(esq > dre) return -1;
  int pos = (dre+esq)/2;
  if(v[pos]+a == pos + 1 and (pos == 0 or v[pos-1] + a != pos)) return pos+1; //retorna la posicio sempre i quan el nombre anterior del vector queid descartat
  if(v[pos]+a < pos+1) return posicio(a,v,pos+1,dre);
  else return posicio(a,v,esq,pos-1);
}

int main(){
  int n,seq = 0,x;
  while(cin >> n){
    cout << "Sequence #" << ++seq << endl;
    vector<int> v(n);
    for(int i = 0; i < n; ++i){ //llegim vector
        cin >> x;
        v[i] = x;
    }
    int m;
    cin >> m;
    while(m > 0){ //farem el bucle tants cops com a's que insertarem
      int a;
      cin >> a;
      int pos = posicio(a,v,0,v.size()-1);
      --m;
      if(pos == -1) cout <<"no fixed point for " << a << endl;
      else cout <<"fixed point for " << a << ": " << pos << endl;
    }
    cout << endl;
  }
}
//Alex Rubio i Quintana
