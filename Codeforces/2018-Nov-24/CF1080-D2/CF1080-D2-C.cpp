#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

pair<ll, ll> calc(ll r, ll c, ll r1, ll c1) {
  bool black = (!(r1&1) && !(c1&1)) || ((r1&1) && (c1&1));
  black = !black;
  ll b = 0, w = 0;
  if(r&1) {
    --r;
    w = (c+1)/2;
    b = c/2;
  }
  ll all = r*c;
  w += all/2;
  b += all/2;
  if(black) swap(b, w);
  return {w, b};
}


ll sz(ll r1, ll c1, ll r2, ll c2) {
  return (r2-r1+1) * (c2-c1+1);
}

bool overlap(int r1,int c1,int r2,int c2,int r3,int c3,int r4,int c4)  {
    if (r1 > r4 || r3 > r2) 
        return false; 
    
    if (c1 > c4 || c3 > c2) 
        return false; 
  
    return true; 
} 

int main() {
  int t;
  scanf("%d", &t);
  int R,C,r1,c1,r2,c2,r3,c3,r4,c4;
  swap(R, C);
  pair<ll,ll> res, t1, t2, t3;
  while(t--) {
    scanf("%d%d", &R, &C);
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    scanf("%d%d%d%d", &r3, &c3, &r4, &c4);
    res = calc(R, C, 1, 1);
    
    
    t1 = calc(r2-r1+1, c2-c1+1, r1, c1);
    t2 = calc(r4-r3+1, c4-c3+1, r3, c3);

    
    
    res.first += sz(r1, c1, r2, c2);
    res.first -= t1.first;
    res.second -= t1.second;


    res.second += sz(r3, c3, r4, c4);
    res.first -= t2.first;
    res.second -= t2.second;

    if(overlap(r1,c1,r2,c2,r3,c3,r4,c4)) {
      int rr1 = max(r1, r3);
      int cc1 = max(c1, c3);
      int rr2 = min(r2, r4);
      int cc2 = min(c2, c4);
      t3 = calc(rr2-rr1+1, cc2-cc1+1, rr1, cc1);
      res.first -= t3.second;
      res.second += t3.second;

    }

    printf("%lld %lld\n", res.first, res.second);
  }
  return 0;
}
