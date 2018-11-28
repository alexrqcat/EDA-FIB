#include <iostream>
#include <sstream>
#include <set>

using namespace std;

bool diferent (int a, int b){
    if((a+b)%2 != 0) return true;
    else return false;
}
int main(){
    string s;
    while (getline(cin, s)){
        istringstream ss(s);
        set<int> seq;
        int n, cont = 1,max=1;
	    while(ss >>n)
            seq.insert(n);
        if(seq.empty())cout << 0 << endl;
        else{
    	    set<int>::iterator act;
            set<int>::iterator seg = seq.begin();
            set<int>::iterator end = seq.end();
            --end;
            for(act = seq.begin(); act!=end;++act){
                ++seg;
                if(diferent(*act,*seg)){
                    if(*act < *seg) ++cont;
                    else cont = 1;
                }
                if(max < cont) max = cont;
            end = seq.end();
            --end;
            }
            cout << max << endl;
	    }
    }
}

//Alex Rubio i Quintana
