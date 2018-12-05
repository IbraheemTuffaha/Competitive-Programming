#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 500000 + 5;
int n, c, a[N], mx, zeros, res = 0, tz = 0;

map<int, int> f;

int main() {
  scanf("%d%d", &n, &c);
  for(int i=0; i<n; ++i) {
    scanf("%d", a+i);
    a[i] -= c;
    if(a[i] == 0)
      ++tz;
  }
  res = tz;
  for(int i=0; i<n; ++i) {

    int &fr = f[a[i]];

    if(a[i] == 0) {
      ++zeros;
    }
    else {
      fr = max(fr, zeros);
      ++fr;
      mx = max(mx, fr);
      res = max(res, tz + mx - zeros);
    }

  }
  cout << res << endl;
  return 0;
}