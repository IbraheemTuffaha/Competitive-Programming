#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  ll n, x, y, d, diff, res = 1e18;
  while(t--) {
    res = 1e18;
    cin >> n >> x >> y >> d;
    diff = labs(x-y);
    if(diff % d == 0)
      res = diff / d;
    diff = labs(1-y);
    if(diff % d == 0)
      res = min(res, diff / d + (labs(x-1) + d - 1) / d);
    diff = labs(n-y);
    if(diff % d == 0)
      res = min(res, diff / d + (labs(x-n) + d - 1) / d);
    if(res > 1e17)
      res = -1;
    cout << res << endl;
  }
  return 0;
}
