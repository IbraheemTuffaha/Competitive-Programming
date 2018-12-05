#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 200000 + 5;
int n, a[N];
multiset<int> st;
ll sum;
int main() {
  scanf("%d", &n);
  for(int i=0; i<n; ++i) {
    scanf("%d", a+i);
    sum += a[i];
    st.insert(a[i]);
  }
  vector<int> v;
  for(int i=0; i<n; ++i) {
    auto it = st.lower_bound(a[i]);
    st.erase(it);
    it = st.end();
    --it;
    if(sum-a[i] == 2LL * (*it))
      v.push_back(i+1);
    st.insert(a[i]);
  }
  printf("%d\n", int(v.size()));
  for(auto x : v)
    printf("%d ", x);
  puts("");

  return 0;
}