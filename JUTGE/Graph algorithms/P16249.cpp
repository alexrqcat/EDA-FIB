//EEE ALS PRIVATS - TRY NEW SOL WITH ADJ LIST.

#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <set>

using namespace std;

typedef map<string,list<string>> Graph;
typedef map<string,int> Apuntadors;
typedef priority_queue<string, vector<string>, greater<string>> Prio;

void llegir_graf(Graph& A, int n, Apuntadors& Ap, Prio& PQ){
  set<string> apuntats;
  for(int i = 0; i < n; ++i){
    string task;
    cin >> task;
    list<string> l;
    A.insert(make_pair(task,l));
    Ap.insert(make_pair(task,0));
    apuntats.insert(task);
  }
  int m;
  cin >> m;
  while(m > 0){
    string t1,t2;
    cin >> t1 >> t2;
    A[t1].push_back(t2);
    apuntats.erase(t2);
    ++Ap[t2];
    --m;
  }
  for(string s : apuntats)
    PQ.push(s);
}
list<string> task_ordering(const Graph& G, Apuntadors& A, Prio& PQ){
  list<string> L;
  while(!PQ.empty()){
    string task = PQ.top();
    PQ.pop();
    L.push_back(task);
    list<string> tasques =  G.find(task)->second;
    for(string t2 : tasques){
      if(--A[t2] == 0) PQ.push(t2);
    }
  }
  return L;
}
void escriu_llista(list<string>& L){
  while(!L.empty()){
    cout << L.front();
    L.pop_front();
  }
}
int main(){
  int n;
  while(cin >> n){
    Graph G;
    Apuntadors AP;
    Prio PQ;
    llegir_graf(G,n,AP,PQ);
    list<string> L = task_ordering(G,AP,PQ);
    if(!L.empty()) escriu_llista(L);
    else
      cout << "NO VALID ORDERING";
    cout << endl;
  }
}
//Alex Rubio i Quintana
