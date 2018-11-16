/*
  Author: Ibraheem Tuffaha
  Idea:   - First observation is that the largest value 'mx' is always
            at one of the corners, thus the zero will be on some fixed
            diagonal and the opposite corner will have a fixed value
            for some fixed n and m (distance z will be the same despite
            of on which cell the zero is on the diagonal).
          - Suppose x and y is the position of the cell, then x (or y)
            is equal to the the first number i that has frequency less
            than 4*i (second observation)
          - Write down some formulas of n, m, mx, z, x, y and solve them
            you will get the value for y given n and m then test if this
            is a valid solution by trying to fill the grid
          - One can loop on t and find n and m using: n = t/m.
          - Time complexity -> O(t * tau(t)) (number if divisors)
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 1000000 + 5;
int f[N], c[N], t, mx;

bool check(int n, int m, int x, int y) {
  // make sure calculated indices are in range
  if(x < 1 || x > n || y < 1 || y > m) return false;

  // fill in the grid
  memset(c, 0, sizeof(int)*t);
  for(int i=n; i>=1; --i)
    for(int j=m; j>=1; --j) {
      int d = abs(i-x) + abs(j-y);
      if(++c[d] > f[d])
        return false;
    }
  // make sure the grid fits the input
  for(int i=0; i<=mx; ++i)
    if(c[i] != f[i])
      return false;
  return true;
}

int main() {
  scanf("%d", &t);
  for(int i=0, a; i<t; ++i) {
    scanf("%d", &a);
    ++f[a];
    mx = max(mx, a);
  }
  if(f[0] != 1) return puts("-1"), 0;
  // find the value of x
  int x = 1;
  for(int i=1; i<t; ++i)
    if(f[i] != 4*i) {
      x = i;
      break;
    }
  
  // loop on n
  for(int n=1, m, y; n*n<=t; ++n) {
    if(t % n != 0) continue;
    // calculate m and y
    m = t / n;
    y = n + m - mx - x;

    if(check(n, m, x, y)) {
      printf("%d %d\n%d %d\n", n, m, x, y);
      return 0;
    } else if(check(m, n, x, y)) {
      printf("%d %d\n%d %d\n", m, n, x, y);
      return 0;
    } 
  }
  puts("-1");
  return 0;
}
