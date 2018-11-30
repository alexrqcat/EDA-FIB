#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(){
    string op;
    map<string,int> classificacio; //ordenat per noms
    map<int,set<string> > ranking; //ordenat per puntuacions
    set<string> online;
    while(cin >> op){
        if(op == "LOGIN"){
            string nom;
            cin >> nom;
            if(classificacio.end() == classificacio.find(nom)){ //inserim el jugador dins els dos taulells
                classificacio.insert(pair<string,int>(nom,1200));
                ranking[1200].insert(nom);
            }
            if(online.end() == online.find(nom)) online.insert(nom); //si no esta online l'inserim a la llista de conectats
        }
        else if(op == "PLAY"){
            string j1,j2;
            cin >> j1 >> j2;
            if(online.end() == online.find(j1)) cout << "jugador(s) no connectat(s)" << endl;
            else if(online.end() == online.find(j2)) cout << "jugador(s) no connectat(s)" << endl;
            else{
                map<int,set<string> >::iterator ir_rank1,ir_rank2;
                ranking[classificacio[j1]].erase(j1);
                ranking[classificacio[j2]].erase(j2);

                classificacio[j1] = classificacio[j1] +10;
                classificacio[j2] = classificacio[j2] -10;

                if(classificacio[j2] < 1200) classificacio[j2] = 1200;
                ranking[classificacio[j1]].insert(j1);
                ranking[classificacio[j2]].insert(j2);
            }
        }
        else if(op == "LOGOUT"){
            string nom;
            cin >> nom;
            online.erase(nom);
        }
        else if(op == "GET_ELO"){
            string nom;
            cin >> nom;
            map<string,int>::iterator it;
            it = classificacio.find(nom);
            if(it != classificacio.end()) cout << it->first << " " << it->second << endl;
            else
				cout << "jugador(s) no connectat(s)" << endl;
        }
    }
    map<int,set<string> >::iterator it_map = ranking.end(); //A PARTIR D'AQUI PREPAREM I IMPRIMIM EL RANKING PER ORDRE DE PUNTS
    --it_map;
    cout << endl << "RANKING" << endl;
    while(not ranking.empty()){
        set<string>::iterator it_set;
        for(it_set = it_map->second.begin();it_set != it_map->second.end(); ++it_set){
            cout << *it_set << " " << it_map->first << endl;
        }
        ranking.erase(it_map);
        --it_map;
    }
}
//Alex Rubio i Quintana
