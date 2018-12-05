/*
  Author: Ibraheem Tuffaha
  Idea:   - first trick to make implementation easy is to add 0
            at the start and 1001 at the end.
          - Let X be the longest consequtive subsequence, then the
            result is X-2 because removing the start or the end gives
            ambiguity
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 100 + 5;
int n, a[N];

int main() {
  scanf("%d", &n);
  for(int i=2; i<=n+1; ++i)
    scanf("%d", a+i);
  a[0] = -100;
  a[1] = 0;
  a[n+2] = 1001;
  a[n+3] = 1e4;
  n += 3;
  int res = 2;
  for(int i=1, cnt=1; i<n; ++i) {
    if(a[i-1]+1 == a[i])
      ++cnt;
    else cnt = 1;
    res = max(res, cnt);
  }
  printf("%d\n", res-2);
  return 0;
}