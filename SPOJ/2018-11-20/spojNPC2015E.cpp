#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 62, M = 1817121 + 10;
ll dp[N][M], oo = 3e18+10;

ll calc(int egg, int tri) {
  if(egg == 1) return tri;
  if(tri == 1) return 1;

  ll &ret = dp[egg][tri];
  if(ret != -1) return ret;
  ret = 0;
  ret = calc(egg, tri-1) + calc(egg-1, tri-1);
  ret = min(ret, oo);

  return ret;
}
 
int main() {
  ll x, y;  
  for(int i=1; i<N; ++i)
    dp[i][1] = 1;
  for(int i=1; i<M; ++i)
    dp[1][i] = i;

  for(int i=2; i<N; ++i)
    for(int j=2; j<M; ++j)
        dp[i][j] = min(oo, dp[i-1][j-1] + dp[i][j-1]);
        
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%lld%lld", &y, &x);
    if(x == 1) printf("%lld\n", y);
    else if(x == 2)  {
      ll l = 1, r = 2e9+100, mid, res=-1;
      while(l <= r) {
        mid = (l+r)/2;
        if(mid * (mid-1) / 2 + 1 <= y) {
          res = mid;
          l = mid+1;
        } else r = mid-1;
      }
      printf("%lld\n", res);
    } else {
      x = min(x, N - 1LL);
      int l = 1, r = M-1, mid, res=-1;
      while(l <= r) {
        mid = (l+r)/2;
        if(dp[x][mid] > y) {
          res = mid;
          r = mid-1;
        } else l = mid+1;
      }
      printf("%d\n", res-1);
    }
  }
 
  return 0;
} 