#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 100000 + 10;
int n, m, a[N];
int main() {
  scanf("%d%d", &n, &m);
  ll sum = 0;
  int mx = 0;
  for(int i=0; i<n; ++i) {
    scanf("%d", a+i);
    mx = max(mx, a[i]);
    sum += a[i];
  }
  sort(a,a+n);
  int x = 0;
  for(int i=1, j=0; i<=mx; ++i) {
    while(j < n && a[j] < i) ++j;
    if(j < n)
      ++x, ++j;
    else break;
  }
  ll res = n + mx - x;
  cout << max(0LL, sum - res) << endl;
  return 0;
}