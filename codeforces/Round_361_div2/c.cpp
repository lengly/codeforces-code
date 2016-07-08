#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<set>
#include<unordered_set>
#include<queue>
#include<algorithm>
using namespace std;

long long solve(long long x) {
	long long k = int(cbrt(x)), ans = 0;
	for(long long i = 2; i <= k; i++) {
		ans += x / (i * i * i);
	}
	return ans;
}

int main() {
	// freopen("input.txt","r",stdin);
	long long m;
	cin >> m;
	long long l = 8, r = 100000000000000000;
	while(l < r) {
		long long mid = (l + r) / 2;
		long long s = solve(mid);
		if (s < m) {
			l = mid + 1;
		} else if (s > m) {
			r = mid - 1;
		} else if (s == m) {
			r = mid;
		}
	}
	if (solve(l) == m) {
		cout << l << endl;
	} else {
		printf("-1\n");
	}
	return 0;
}

