/*
  Author: Ibraheem Tuffaha
  Idea:   - The same DP solution for the easier version will work,
            but to reduce the complexity, now instead of looping
            on the k previous dp states to get the max, we will
            use a data structure to do that, in order to avoid
            O(log n) in DS like Segment Tree for example, we
            use the max queue data structure.
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 5000 + 5;
int n, k, x, a[N];
ll dp[N][N];
ll oo = 1e18;

// Max queue data structure that gives 
// the max element at any point
struct Queue {
  stack<pair<ll, ll> > s1, s2;
  
  int size() {
    return s1.size() + s2.size();
  }
  
  bool isEmpty() {
    return size() == 0;
  }
  
  long long getMax() {
    if (isEmpty()) {
      return -oo;
    }
    if (!s1.empty() && !s2.empty()) {
      return max(s1.top().second, s2.top().second);
    }
    if (!s1.empty()) {
      return s1.top().second;
    }
    return s2.top().second;
  }
  
  void push(long long val) {
    if (s2.empty()) {
      s2.push(make_pair(val, val));
    } else {
      s2.push(make_pair(val, max(val, s2.top().second)));
    }
  }
  
  void pop() {
    if (s1.empty()) {
      while (!s2.empty()) {
        if (s1.empty()) {
          s1.push(make_pair(s2.top().first, s2.top().first));
        } else {
          s1.push(make_pair(s2.top().first, max(s2.top().first, s1.top().second))); 
        }
        s2.pop();
      }
    }
    assert(!s1.empty());
    s1.pop();
  }

  void clear() {
    while(!s1.empty())
      s1.pop();
    while(!s2.empty())
      s2.pop();
  }
};

int main() {
  scanf("%d%d%d", &n, &k, &x);
  for(int i=0; i<n; ++i)
    scanf("%d", a+i);

  for(int i=0; i<N; ++i)
    for(int j=0; j<N; ++j)
      dp[i][j] = -oo;

  dp[0][0] = 0;
  Queue q;
  for(int j=1; j<=x; ++j) {
    q.clear();
    for(int i=1; i<=n; ++i) {

      q.push(dp[i-1][j-1]);
      while(q.size() > k) q.pop();
      
      if(q.getMax() != -oo)
        dp[i][j] = q.getMax() + a[i-1];
    }
  }
  
  ll res = -oo;
  for(int i=max(n-k+1, 0); i<=n; ++i)
    res = max(res, dp[i][x]);
  printf("%lld\n", res == -oo ? -1 : res);
  return 0;
}