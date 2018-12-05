#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 1000 + 5;
int dp[N][N];

int calc(int egg, int floor) {
  if(floor == 0) return 0;
  if(egg == 1) return floor;

  int &ret = dp[egg][floor];
  if(ret != -1) return ret;

  ret = 1e9;
 
  for(int i=1, x; i<=floor; ++i) {
    x = 1 + max(calc(egg-1, i-1), calc(egg, floor-i));
    ret = min(ret, x);
  }
  return ret;
}


int main() {
  int x, y;
  
  memset(dp, -1, sizeof dp);

  while(true) {
    scanf("%d%d", &x, &y);
    if(x == 0 && y == 0)
      break;
    x = min(x, int(log2(y)+1e-9) + 1);
    printf("%d\n", calc(x, y));
  }

  return 0;
}