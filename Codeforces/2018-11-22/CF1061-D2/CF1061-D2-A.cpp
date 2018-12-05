#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
  int n, s;
  cin >> n >> s;
  cout << s / n + (s%n != 0) << endl;
  return 0;
}