#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;


ll sum(ll n) {
  ll res = - n * (n+1) / 2;
  ll y = n/2;
  ll x = 2 * (y * (y+1)) / 2;
  res += 2 * x;

  return res;
}

int main() {
  int q, a, b;
  scanf("%d", &q);
  while(q--) {
    scanf("%d%d", &a, &b);
    printf("%lld\n", sum(b) - sum(a-1));
  }
  return 0;
}