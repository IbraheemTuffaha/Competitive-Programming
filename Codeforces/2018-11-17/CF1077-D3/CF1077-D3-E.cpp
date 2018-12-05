/*
  Author: Ibraheem Tuffaha
  Idea:   - Suppose you start with x elements, you can greedily choose the
            smallest frequency more than or equal to x to take them, then
            you need 2*x items, do the same greedy step and repeat,
          - This can be done with a lower bound on a sorted array of frequencies
          - Since we keep multiplying by 2 then the complexity for trying
            a single x is log(n)*log(n) (the other log is for lower_bound)
          - Loop on all possible x's and take the best result, n log(n)^2 total.
*/
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

  // sorted vector of frequencies
  vector<int> v;
  for(auto x : f2)
    v.push_back(x.second);
  sort(v.begin(), v.end());
  
  // bruteforce on all possible starting frequencies
  int ans = 0;
  for(int i=1; i<=n; ++i) {
    int idx = -1, res = 0, val = i;
    // test the starting frequency 'i'
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