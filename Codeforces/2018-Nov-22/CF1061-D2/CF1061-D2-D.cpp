/*
  Author: Ibraheem Tuffaha
  Idea:   - Let's discuss a greedy approach, where you sort the TV shows
          by the starting time, now we will store the used TV's in a queue
          by storing the last minute they were used and only return the
          TV when it's more expensive to use one.
          - For every TV show, if the queue is empty, we have to borrow
          a new TV, if not, we dispose of the TVs that are more expensive
          to keep (if y * (the time this TV isn't used) is bigger than x)
          then it's cheaper to get a new TV, so return this one.
          Now from all TV's left, the greedy step will be to choose the
          closest one to the TV show, because if there are 2 shows and 2
          TVs in the past and you want to assign each show a TV then the
          cost will be the same either way (write examples to verify that)
          But sometimes if you give the closer TV to the earlier show then
          the later show will be too far from the further TV, thus returning
          this TV and borrowing a new one will give a better result.
        - This can be implemented in priority_queue and queue as shown in code.
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 100000 + 10, M = 1000000007;
int n, x, y;

// stores the borrowed TV's last moments
priority_queue<int,vector<int>, greater<int> > pq; // TV's that will be free
                                                   // in the future.
deque<int> q; // TV's that are free form the past, only these can be used.
vector<pair<int,int> > v;

int main() {
  scanf("%d%d%d", &n, &x, &y);
  for(int i=0, a, b; i<n; ++i) {
    scanf("%d%d", &a, &b);
    v.push_back({a, b});
  }
  sort(v.begin(), v.end());
  int res = 0;
  for(auto seg : v) {
    // Move the TVs from past to the queue
    // (can't use TVs that aren't available yet)
    while(!pq.empty() && pq.top() < seg.first) {
      q.push_back(pq.top());
      pq.pop();
    }

    // no TVs, take a new one
    if(q.empty()) {
      res = ((ll)res + x) % M;
      res = ((ll)res + ((ll)y * (seg.second - seg.first)) % M) % M;
    } else {
      // while the TV is too old (borrowing new one is cheaper than keeping it)
      // then return it
      while(!q.empty() && (ll)y * (seg.first - q.back()) >= x)
        q.pop_back();

      // if there is a TV avaiable before I start then take it..
      // the loop above ensures that it is cheaper than new TV
      if(!q.empty()) {
        res = ((ll)res + ((ll)y * (seg.second - q.back())) % M) % M;
        q.pop_back();
      } // otherwise take a new TV
      else {
        res = ((ll)res + x) % M;
        res = ((ll)res + ((ll)y * (seg.second - seg.first)) % M) % M;
      }
    }
    // add the TV to the pqueue (the finishing time)
    pq.push(seg.second);
  }
  printf("%d\n", res);
  return 0;
}