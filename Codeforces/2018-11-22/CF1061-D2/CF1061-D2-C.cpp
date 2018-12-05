/*
  Author: Ibraheem Tuffaha
  Idea:   - Run a modified sieve to find the divisors for numbers <= 1e6,
            Running a bottom up dp[x] where dp[x] is the number of sequences
            that starts with index x.
          - Loop over the numbers backwards and loop on the divisors x of
            a[i] and add dp[x] += 1 + d[x+1], where the 1 corresponds
            to starting the sequence (from the end) at index x from here,
            and dp[x+1] stands for the number of sequences ahead of me
            that reached x+1 as index so far, answer will be at dp[1];
            the number of sequences starting with index 1.
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 100000 + 10, M = 1000000 + 10, MOD = 1000000007;
int n, a[N], dp[N];
vector<int> pr[M];


int main() {
  for(int i=1; i<N; ++i)
      for(int j=i; j<M; j += i)
        pr[j].push_back(i);

  scanf("%d", &n);
  for(int i=0; i<n; ++i)
    scanf("%d", a+i);

  for(int i=n-1; i>=0; --i)
    for(auto x : pr[a[i]])
      dp[x] = (1 + dp[x] + dp[x+1]) % MOD;


  printf("%d\n", dp[1]);


  return 0;
}