#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 100000 + 10;
int n, k, sum, a[N];
map<int,int> freq;

int main() {
  scanf("%d%d", &n, &k);
  for(int i=0; i<n; ++i) {
    scanf("%d", a+i);
    ++freq[a[i]];
  }
  sum = 0;
  for(auto f : freq) {
    printf("%d\n", f.first - sum);
    --k;
    if(k == 0) break;
    sum = f.first;
  }

  while(k > 0) {
    --k;
    puts("0");
  }
  return 0;
}