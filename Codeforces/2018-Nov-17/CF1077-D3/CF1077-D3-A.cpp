#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  ll a, b, k;
  while(t--) {
    scanf("%lld%lld%lld", &a, &b, &k);
    printf("%lld\n", a * ((k+1)/2) - b * (k/2));
  }
  return 0;
}