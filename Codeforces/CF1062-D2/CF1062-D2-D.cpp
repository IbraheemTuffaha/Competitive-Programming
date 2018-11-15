/*
  Author: Ibraheem Tuffaha
  Idea:   - for every number i, if j = i*m (multiple of i) then
            i -> j -> -i -> -j -> i transformations are always
            valid, so for every j = i*m, add 4*m =4*j/i.
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 1000000 + 5, M = 1000000007;
bool vis[N];
int main() {
  int n;
  scanf("%d", &n);
  ll res = 0;
  for(int i=2; i<=n; ++i) {

    for(ll j = (ll)i+i; j<=n; j += i) {
      res += 4LL*j/i;
      vis[j] = true;
    }
  }
  cout << res << endl;
}