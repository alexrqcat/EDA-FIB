#include <iostream>

using namespace std;

int exp_modular(int n, int k, int m) {
  if (k == 0) return 1;
  else {
    int aux = exp_modular(n, k/2, m) % m;
    if (k%2 == 0) return (aux*aux) % m;
    else return (((aux*aux) % m) * n) % m;
  }
}
int main() {
    int n,k,m;
    while(cin >> n >> k >> m)
      cout << exp_modular(n, k, m) << endl;
}

//Alex Rubio i Quintana
