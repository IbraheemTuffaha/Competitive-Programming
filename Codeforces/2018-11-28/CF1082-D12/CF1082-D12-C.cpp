#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 100000 + 5;
int n, m;

vector<int> v[N], idx;

bool cmp(int a, int b) {
  return v[a].size() > v[b].size();
}

int main() {
  scanf("%d%d", &n, &m);
  for(int i=0, s, r; i<n; ++i) {
    scanf("%d%d", &s, &r);
    v[s-1].push_back(r);
  }
  for(int i=0; i<m; ++i) {
    idx.push_back(i);
    sort(v[i].begin(), v[i].end());
    reverse(v[i].begin(), v[i].end());
    for(int j=1; j<v[i].size(); ++j)
      v[i][j] += v[i][j-1];
  }

  sort(idx.begin(), idx.end(), cmp);
  ll res = 0, tmp;

  for(int i=1; i<=n; ++i) {
    tmp = 0;
    for(int j=0; j<m && i-1 < v[idx[j]].size(); ++j) {
      if(v[idx[j]][i-1] < 0) continue;
      tmp += v[idx[j]][i-1];
    }
    res = max(res, tmp);
  }

  cout << res << endl;
  return 0;
}