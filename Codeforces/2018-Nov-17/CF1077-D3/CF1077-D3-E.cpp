#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 200000 + 5;
int n, k, a[N], f[N];
map<int,int> f2;
int main() {
  scanf("%d", &n);
  for(int i=0; i<n; ++i) {
    scanf("%d", a+i);
    ++f2[a[i]];
  }
  vector<int> v;
  for(auto x : f2)
    v.push_back(x.second);
  sort(v.begin(), v.end());
  int ans = 0;
  for(int i=1; i<=n; ++i) {
    int idx = -1, res = 0, val = i;
    while(true) {
      idx = lower_bound(v.begin()+idx+1, v.end(), val) - v.begin();
      if(idx >= v.size()) break;
      res += val;
      val += val;
    }
    ans = max(ans, res);
  }
  printf("%d\n", ans);
  return 0;
}