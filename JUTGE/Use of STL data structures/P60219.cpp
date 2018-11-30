#include <iostream>
#include <set>

using namespace std;

struct cmp {
    bool operator()(const string& s1, const string& s2){
        if(s1.size() != s2.size())
            return s1.size()<s2.size();
        return s1 < s2;
    }
};

int main(){
  set<string> S;
  set<string,cmp> old;
  set<string>::iterator it;
  int game = 1;
  string n;
  while(cin >> n){
    if(n != "END" and n!= "QUIT"){
      pair<set<string>::iterator,bool> ret;
      ret = S.insert(n);
      if(not ret.second){
        S.erase(n);
        old.insert(n);
      }
      else old.erase(n);
    }
    else{
      cout << "GAME #" << game << endl << "HAS:" << endl;
      for(it = S.begin(); it != S.end() ; ++it){
        cout << *it << endl;
      }
      cout  << endl << "HAD:" << endl;
      for(it = old.begin(); it != old.end() ; ++it){
        cout << *it << endl;
      }
      if(n == "QUIT") return 0;
      cout << endl;
      ++game;
      S.clear();
      old.clear();
    }
  }
}
//Alex Rubio i Quintana
