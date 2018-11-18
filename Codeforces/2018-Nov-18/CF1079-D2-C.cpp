/*
  Author: Ibraheem Tuffaha
  Idea:   - A standard DP with path problem.
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 100000 + 5;
int n, a[N], dp[N][5];
int calc(int i, int f) {
  if(i == n) return true;
  int &ret = dp[i][f];
  if(ret != -1) return ret;
  ret = false;
  for(int j=0; j<5; ++j) {
    if(j == f) continue;
    if(a[i-1] < a[i] && j < f) continue;
    if(a[i-1] > a[i] && j > f) continue;
    ret |= calc(i+1, j);
    if(ret) return ret;
  }
  return ret;
}

vector<int> v;
void print(int i, int f) {
  if(i == n) return;
  int ret = dp[i][f];

  for(int j=0; j<5; ++j) {
    if(j == f) continue;
    if(a[i-1] < a[i] && j < f) continue;
    if(a[i-1] > a[i] && j > f) continue;
    if(ret == calc(i+1, j)) {
      v.push_back(j+1);
      print(i+1, j);
      return;
    }
  }
}

int main() {
  scanf("%d", &n);
  for(int i=0; i<n; ++i)
    scanf("%d", a+i);
  memset(dp, -1, sizeof dp);
  int res = -1;
  for(int i=0; i<5; ++i)
    if(calc(1, i)) {
      res = i;
      break;
    }
  if(res == -1) puts("-1");
  else {
    v.push_back(res+1);
    print(1, res);
    for(auto x : v)
      printf("%d ", x);
    puts("");
  }

  return 0;
}