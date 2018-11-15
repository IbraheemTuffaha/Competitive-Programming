/*
	Author:	Ibraheem Tuffaha
	Idea:		- Count the number of ones and the number of zeros in the range
						using cumulative sum, it is always better to take the ones before
						the zeros because at any moment, if the one cells have value x
						then the zeros cells will have x-1, thus taking x will add x to 
						all the remaining cells instead if x-1.
					- Taking the ones first will give a sum of powers of 2
					  -> x = sum(2^i) for i (0->ones-1) = (2^ones)-1
					- Now the zeros have initial value x, so similarly the result of
						the zeros is x * (2^zeros)-1
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 1000000 + 5, M = 1000000007;
int n, q, a[N];
char st[N];

int power[N];

int main() {
	power[0] = 1;
	for(int i=1; i<N; ++i)
		power[i] = power[i-1] * 2LL % M;
	scanf("%d%d %s", &n, &q, st+1);
	for(int i=1; i<=n; ++i) {
		a[i] = st[i] - '0';
		a[i] += a[i-1];
	}
	int l, r;
	int res = 0, one, zero;
	while(q--) {
		scanf("%d%d", &l, &r);
		one = a[r] - a[l-1];
		zero = r-l+1 - one;
		int x = (power[one]-1LL + M) % M;
		res = (ll)x * ((1LL + (power[zero]-1LL + M) % M) % M) % M;
		printf("%d\n", res);
	}
	return 0;
}