#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 100 + 5;
int n, k, a[N], f[N];
int main() {
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  int len = s.length();
  for(int i=1; i<=5; ++i) {
    int j = (len+i-1) / i;
    if(j > 20) continue;
    cout << i << " " << j << endl;
    int stars = i*j - len;
    for(int k=0; k<i; ++k) {
      string res = "";
      int x = stars / i + (stars % i > k);
      while(x--)
        res += "*";
      while(res.size() < j && s.size()) {
        res += s.back();
        s.pop_back();
      }
      cout << res << endl;
    }
    return 0;
  }
  return 0;
}