#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 100 + 5;
int n, k, a[N], f[N];
int main() {
  scanf("%d%d", &n, &k);
  int mx = 0;
  set<int> st;
  for(int i=0; i<n; ++i) {
    scanf("%d", a+i);
    ++f[a[i]];
    mx = max(mx, f[a[i]]);
    st.insert(a[i]);
  }
  int res = (mx + k - 1) / k * k * int(st.size()) - n;
  cout << res << endl;
  return 0;
}