#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
  ll n, k;
  cin >> n >> k;
  ll a = 2*n, b = 5*n, c = 8*n;
  ll res = (a+k-1)/k + (b+k-1)/k + (c+k-1)/k;
  cout << res << endl;
  return 0;
}