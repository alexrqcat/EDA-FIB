#include <iostream>
#include <vector>

using namespace std;

int posicio(double x, const vector<double>& v, int esq, int dre){
  if(esq > dre) return -1; //no existeix
  int pos = (dre+esq)/2;
  if(esq == dre){ //será igual si no existeix "x" o si existeix "x" i es la primera ocurrencia
    if(x == v[esq])  return pos; //si esq=dre i v[esq] (=v[dre]) = x, em trobat la primera ocurrencia.
    else return -1;
  }
  if(x > v[pos]) return posicio(x,v,pos+1,dre);
  else return posicio(x,v,esq,pos); //no fem pos-1 (com a cerca dicotòmica) ja que es probable que pos sigui la sol·lucio.
}
 int first_occurrence(double x, const vector<double>& v){
   int pos = posicio(x,v,0,v.size()-1);
   return pos;
 }

 //Alex Rubio i Quintana
