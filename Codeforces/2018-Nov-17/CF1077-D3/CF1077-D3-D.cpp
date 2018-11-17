#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 200000 + 5;
int n, k, a[N], f[N];

bool check(int x) {
  int ret = 0;
  for(int i=0; i<N; ++i)
    ret += f[i] / x;
  return ret >= k;
}

int main() {
  scanf("%d%d", &n, &k);
  for(int i=0; i<n; ++i) {
    scanf("%d", a+i);
    ++f[a[i]];
  }
  int l = 1, r = n + 10, mid, res = -1;
  while(l <= r) {
    int mid = (l+r)/2;
    if(check(mid)) {
      l = mid+1;
      res = mid;
    } else r = mid-1;
  }
  vector<int> v;
  for(int i=0; i<N; ++i) {
    while(f[i] >= res && k) {
      --k;
      v.push_back(i);
      f[i] -= res;
    }
  }
  for(auto x : v)
    printf("%d ", x);
  puts("");

  return 0;
}