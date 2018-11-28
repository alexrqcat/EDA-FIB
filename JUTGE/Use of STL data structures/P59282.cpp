#include <iostream>
#include <map>

using namespace std;

int main(){
    string op;
    int cont = 0,numero;
    double sum = 0;
    map<int,int> me;
    map<int,int>::iterator min,max;
    cout.setf(ios::fixed);
    cout.precision(4);
    while(cin >> op){
            std::pair<std::map<int,int>::iterator,bool> ret;
            if(op == "number"){
                cin >> numero;
                ret = me.insert (pair<int,int>(numero,1));
                if(ret.second == false) ++(ret.first->second);
                ++cont;
                sum += numero;
            }
            else if(not me.empty()) {
                --cont;
                if(min->second > 1 ) --(min->second);
                else me.erase(me.begin());
                sum -= min->first;
            }
            if(me.empty())cout << "no elements" << endl;
            else{
                min = me.begin();
                max = me.end();
                --max;
                cout <<"minimum: " <<  min->first << ", maximum: " << max->first << ", average: "<<sum/cont << endl;
            }
    }
	return 0;
}
//Alex Rubio i Quintana
