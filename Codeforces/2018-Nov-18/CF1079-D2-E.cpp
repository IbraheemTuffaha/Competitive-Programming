/*
  Author: Ibraheem Tuffaha
  Idea:   - If the number of unique numbers is <= 2, the answer is n
            because you can ask about the first number and you will
            know it and the complement which is the second number.
          - Otherwise, the weights guessed should be equal to avoid
            confusion, it can be proven that there is no need to
            ask on the complement set to find the result for some value
            because if the set has a duplicate, then the complement set
            also has a duplicate, example: "9 2 2 1 3" -> 2 2 and 1 3 
            are duplicates, the complement to 2 2 is 9 1 3, but 9 2 2
            us a duplicate of 9 1 3 as well.
          - Now we have to check if you can uniquely find a sum equal to
            x * f using f elements or not (where x is a number in the array)
            otherwise it's a duplication, we can do that with a
            dp[index][sum][#elements], to avoid overflow (or collision with
            using mod), you only need to know if there is more than 1 way
            to find the sum, so ret = min(ret, 2).
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 100 + 2;
int n, a[N], f[N];
char dp[N][N*N][N];

char calc(int i, int sum, int num) {
  if(i == N) return sum == 0 && num == 0;

  char &ret = dp[i][sum][num];
  if(ret != -1) return ret;

  ret = calc(i+1, sum, num);
  for(int k=1; k<=f[i]; ++k)
    if(sum-i*k >= 0 && num-k >= 0)
      ret = min(50, (int)ret + calc(i+1, sum-i*k, num-k));

  return ret;
}

int main() {
  scanf("%d", &n);
  for(int i=0; i<n; ++i) {
    scanf("%d", a+i);
    ++f[a[i]];
  }
  int cnt = 0;
  for(int i=0; i<N; ++i)
    if(f[i])
      ++cnt;
  
  if(cnt <= 2) return printf("%d\n", n), 0;

  memset(dp, -1, sizeof dp);
  int res = 1;
  for(int i=1; i<N; ++i)
    for(int j=2; j<=f[i]; ++j)
      if(calc(0, i*j, j) == 1)
        res = max(res, j);

  cout << res << endl;
  return 0;
}