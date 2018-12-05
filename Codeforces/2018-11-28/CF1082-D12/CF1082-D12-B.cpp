#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 100000 + 5;
int n;
char st[N];
string s;
vector<pair<int, int> > v;
int calc(string s) {
  bool ok = false;
  int ret = 0, len1 = 0, cnt = 0, prv = 0;

  for(int i=0; i<s.length(); ++i) {
    if(s[i] == 'G')  {
      ++len1;
    }
    else  {

      if(len1 != 0)
        ++cnt;
      len1 = 0;
    }
  }

  len1 = 0;

  for(int i=0; i<s.length(); ++i) {
    if(s[i] == 'G')  {
      ++len1;
    }
    else  {
      if(prv != 0 && len1 != 0)
        ret = max(ret, len1 + prv + (cnt >= 3));
      prv = len1;
      len1 = 0;
    }
    ret = max(ret, len1 + (cnt >= 2));
  }

  return ret;
}

int main() {
  scanf("%d%s", &n, st);
  s = st;

  s += 'S';

  int res = calc(s);

  cout << res << endl;
  return 0;
}
