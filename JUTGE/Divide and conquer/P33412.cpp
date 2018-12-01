#include <iostream>
#include <vector>
using namespace std;

 bool resistant_search(double x, const vector<double>& v){
   if(v.size() == 0) return false;
   int esq = 0, dre = v.size() - 1,pos;
   while(esq + 1 < dre){
     pos = (esq+dre)/2;
     if(v[pos] == x or v[pos-1] == x or v[pos+1] == x) return true;
     else if(v[pos] > x) dre = pos;
     else esq = pos;
   }
   return (x == v[esq] or x == v[dre]);
 }
//Alex Rubio i Quintana
