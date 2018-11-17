#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 200 + 5;
int n, k, x, a[N];
ll dp[N][N][N];

ll calc(int i, int prv, int taken) {
  if(taken > x || prv >= k) return -1e17;
  if(i == n) return taken == x ? 0 : -1e17;

  ll &ret = dp[i][prv][taken];
  if(ret != -1) return ret;

  ret = calc(i+1, prv+1, taken);
  ret = max(ret, a[i] + calc(i+1, 0, taken+1));
  return ret;
}

int main() {
  scanf("%d%d%d", &n, &k, &x);
  for(int i=0; i<n; ++i)
    scanf("%d", a+i);  
  memset(dp, -1, sizeof dp);
  printf("%lld\n", calc(0, 0, 0) < -1e14 ? -1 : calc(0, 0, 0));
  return 0;
}