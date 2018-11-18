/*
  Author: Ibraheem Tuffaha
  Idea:   - For each of the two points, try to walk towards the
            line until you hit it, you can do it by bruteforcing
            all directions for each point and trying all pairs
            and storing the minimum result in minRes
          - Now the result is min(Manhattan distance, minRes)
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
ll a, b, c, x1, x2, y11, y2;
ld EPS = 1e-8;

struct point { ld x, y; };

ld distance(ld x1, ld y1, ld x2, ld y2) {
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main() {
  cin >> a >> b >> c >> x1 >> y11 >> x2 >> y2;
  
  // Manhattan distance
  ld res = abs(x1-x2) + 0.0 + abs(y11-y2);
  if(a != 0 && b != 0) {
    point p1, p2;

    // try all possible scenarios for moving towards the line
    p1.x = x1;
    p1.y = (-c-a*p1.x)/b;

    p2.y = y2;
    p2.x = (-c-b*p2.y)/a;

    res = min(res, distance(p1.x, p1.y, p2.x, p2.y)
                  + distance(p2.x, p2.y, x2, y2)
                  + distance(p1.x, p1.y, x1, y11));

    p1.x = x2;
    p1.y = (-c-a*p1.x)/b;

    p2.y = y11;
    p2.x = (-c-b*p2.y)/a;

    res = min(res, distance(p1.x, p1.y, p2.x, p2.y)
                  + distance(p2.x, p2.y, x1, y11)
                  + distance(p1.x, p1.y, x2, y2));

    p1.x = x1;
    p1.y = (-c-a*p1.x)/b;


    p2.x = x2;
    p2.y = (-c-a*p2.x)/b;

    res = min(res, distance(p1.x, p1.y, p2.x, p2.y)
                  + distance(p2.x, p2.y, x2, y2)
                  + distance(p1.x, p1.y, x1, y11));

    p1.y = y11;
    p1.x = (-c-b*p1.y)/a;


    p2.y = y2;
    p2.x = (-c-b*p2.y)/a;

    res = min(res, distance(p1.x, p1.y, p2.x, p2.y)
                  + distance(p2.x, p2.y, x2, y2)
                  + distance(p1.x, p1.y, x1, y11));

  }
  cout << fixed << setprecision(10) << res << endl;
  return 0;
}