#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 2000 + 10;
int n, k, a[N];

int main() {
  scanf("%d", &n);
  for(int i=0; i<n; ++i)
    scanf("%d", a+i);
  int sum = 0;
  printf("%d\n", n+1);
  int x = 2500;
  int diff;
  for(int i=n-1; i>=0; --i) {
    a[i] += sum;
    diff = (i - a[i]);
    diff %= x;
    if(diff < 0) diff += x;
    a[i] += diff;
    printf("1 %d %d\n", i+1, diff);
    sum += diff;
  }
  printf("2 %d %d\n", n, x);

  return 0;
}