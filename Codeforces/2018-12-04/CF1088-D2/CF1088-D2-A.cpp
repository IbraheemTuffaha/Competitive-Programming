#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
  int x;
  cin >> x;
  for(int a=1; a<=x; ++a) {
    for(int b=1; b<=x; ++b) {
      if(a%b == 0 && a*b > x && 1.0*a/b<x) {
        cout << a << " " << b << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}