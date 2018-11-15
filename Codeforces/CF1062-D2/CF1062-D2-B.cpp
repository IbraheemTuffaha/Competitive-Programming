/*
	Author:	Ibraheem Tuffaha
	Idea:		- Find the frequency of the prime factors, the result will be
						the multiplication of each prime factor once, and the number
						of operations is ceil(log(max(frequency))), because to taking
						the square root halves the powers of the prime factors.
					- We should add 1 to the number of operations if not all powers
						are equal or the max power is not a power of 2.
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 100 + 5;
int n, a[N];

int Log2(int x) {
	int y = 1, ret = -1;
	while (y < x) ++ret, y *= 2;
	return ret;
}


int main() {
	scanf("%d", &n);
	vector<int> pr;
	vector<bool> is(n+10);
	is[0] = is[1] = true;
	for(int i=2; i<=n; ++i)
		if(!is[i]) {
			pr.push_back(i);
			for(ll j=(ll)i*i; j<=n; j += i)
				is[j] = true;
		}
	vector<int> v;
	int r1 = 1;
	int mx = -1;
	for(auto x : pr) {
		int cnt = 0, y = n;
		while(y % x == 0) {
			y /= x;
			++cnt;
		}
		mx = max(mx, cnt);
		if(cnt) {
			v.push_back(cnt);
			r1 *= x;
		}
	} 	
	int r2 = 0;
	bool ok = false;
	for(auto x : v) {
		if(x < mx)
			ok = true;
	}
	if(mx > 1) {
		r2 = Log2(mx)+1;
		if((mx & (mx-1)) != 0)
			ok = true;
	}
	printf("%d %d\n", r1, r2 + ok);
	return 0;
}