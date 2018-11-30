#include <iostream>
#include <vector>
using namespace std;

int posicio(double x, const vector<double>& v, int esq, int dre){
  if(esq > dre) return -1;
  int pos = (dre+esq)/2;
  if(x < v[pos]) return posicio(x,v,esq,pos-1);
  if(x > v[pos]) return posicio(x,v,pos+1,dre);
  return pos;
}
//Alex Rubio i Quintana
