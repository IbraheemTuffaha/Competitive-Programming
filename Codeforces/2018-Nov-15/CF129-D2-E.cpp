/*
  Author: Ibraheem Tuffaha
  Idea:   - the trick to this problem is to think of each dimension
            on its own, where you have n-1 cells and you need to count
            the number of ways to do 2*k cuts to them, same goes for m.
          - The answer will be calc(n-1, 2*k) * calc(m-1, 2*k).
          - Cool observation is that the dp actually calculates nCk.
*/


#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 1000 + 5, M = 1000000007;
int n, m, k, dp[N][N+N];

int calc(int i, int j) {
  // make sure you don't go into negative number of cells
  if(i < 0) return 0;
  // if cuts are over or the number of cells is equal
  // to the number of cuts, the result is 1
  if(j == 0 || i == j) return 1;

  int &ret = dp[i][j];
  if(ret != -1) return ret;

  // try to skip a cut, or try to cut
  ret = (calc(i-1, j) + calc(i-1, j-1)) % M;
  return ret;
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  memset(dp, -1, sizeof dp);
  // The result is the number of ways to cut the rows times
  // the number of ways to cut the columns
  printf("%lld\n", ((ll)calc(n-1, k+k) * calc(m-1, k+k)) % M);
  return 0;
}
