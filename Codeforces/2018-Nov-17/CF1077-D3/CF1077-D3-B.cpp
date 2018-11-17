#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 100 + 5;
int n, a[N];
int main() {
  scanf("%d", &n);
  for(int i=0; i<n; ++i)
    scanf("%d", a+i);
  int res = 0;
  for(int i=1; i+1<n; ++i) {
    if(a[i-1] == 1 && a[i+1] == 1 && a[i] == 0) {
      ++res;
      a[i+1] = 0;
    }
  }
  cout << res << endl;
  return 0;
}