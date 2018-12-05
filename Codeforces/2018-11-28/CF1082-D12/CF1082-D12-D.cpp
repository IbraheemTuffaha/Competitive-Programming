#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 500 + 5;
int n, a[N], f[N];
vector<pair<int, int> > v, e;

bool addEdge(int u, int v) {
  if(!f[u] || !f[v]) return false;
  --f[u], --f[v];
  e.push_back({u, v});
  return true;
}

priority_queue<pair<int,int> > q;

int main() {
  scanf("%d", &n);
  v.resize(n);
  for(int i=0; i<n; ++i) {
    scanf("%d", a+i);
    v[i] = {a[i], i};
  }

  vector<int> nodes;
  sort(v.begin(), v.end());
  bool ok;
  for(int res=n-1; res>=2; --res) {
    e.clear();
    for(int i=0; i<n; ++i)
      f[i] = a[i];
    ok = true;

    if(!addEdge(v[0].second, v[n-1].second))
      continue;

    for(int i=n-2; i>=1 && e.size()+1 < res; --i) {
      if(!addEdge(v[i+1].second, v[i].second)) {
        ok = false;
        break;
      }
    }

    if(!addEdge(v[1].second, e.back().second))
      continue;

    while(!q.empty())
      q.pop();

    for(int i=2, u; i<n; ++i) {
      u = v[i].second;
      if(f[u] && f[u] != a[u])
        q.push({f[u], u});
    }

    for(int i=n-2, u, fr; i>=2; --i) {
      int vv = v[i].second;
      if(f[vv] == a[vv]) {
        if(q.empty()) {
          ok = false;
          break;
        }

        fr = q.top().first-1;
        u = q.top().second;
        q.pop();

        if(!addEdge(vv, u)) {
          ok = false;
          break;
        }


        if(fr)
          q.push({fr, u});

        if(f[vv])
          q.push({f[vv], vv});
      }
    }

    if(ok) {
      printf("YES %d\n", res);
      printf("%d\n", int(e.size()));
      for(auto p : e)
        printf("%d %d\n", p.first+1, p.second+1);
      return 0;
    }
  }
  puts("NO");
  return 0;
}