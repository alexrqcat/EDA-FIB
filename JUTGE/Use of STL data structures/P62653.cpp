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
  set<string,cmp> supp;
  set<string>:: iterator it;
  int entrades= 0;
  char op;
  cin >> op; //no fa res
  while(cin >> op){
    it = supp.begin();
    if(op == 'E'){
      cout << entrades <<" ticket(s) left"<< endl;
      cout << supp.size() << " supporter(s) with no ticket" << endl;
      entrades = 0;
      for(it = supp.begin(); it != supp.end();++it){
        cout << *it << endl;
      }
      supp.clear();
    }
    else if(op == 'T'){
      ++ entrades;
      if(entrades > 0 and not supp.empty()){
        --entrades;
        supp.erase(it);
      }
    }
    else if(op == 'S'){
      string supporter;
      cin >> supporter;
      if(entrades > 0 and supp.empty())--entrades;
      else supp.insert(supporter);
    }
  }
}
