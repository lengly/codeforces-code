#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<queue>
#include<algorithm>
using namespace std;

#define maxN 200010

int n, p;
vector<pair<int, int> > a;
long long f[maxN], invf[maxN];
long long MOD = 1e9+7;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

long long power(long long x, long long k) {
	long long ret = 1;
	while (k) {
		if (k & 1) {
			ret = (ret * x) % MOD;
		}
		x = (x * x) % MOD;
		k /= 2;
	}
	return ret;
}

long long inv(long long x) {
	return power(x, MOD - 2);
}

long long C(long long n, long long m) {
	if (m > n) return 0;
	if (m == 0 || m == n) return 1;
	return ((f[n] * invf[m]) % MOD * invf[n-m]) % MOD;
}

int main() {
	// freopen("input.txt","r",stdin);
	scanf("%d%d",&n, &p);
	for(int i = 0; i < n; i++) {
		int l, r;
		scanf("%d%d",&l, &r);
		a.push_back(make_pair(l, 1));
		a.push_back(make_pair(r+1, -1));
	}
	sort(a.begin(), a.end(), cmp);

	memset(f,0,sizeof(f));
	f[0] = 1;invf[0] = 1;
	for(int i = 1; i <= n; i++) {
		f[i] = (f[i-1] * i) % MOD;
		invf[i] = inv(f[i]);
	}
	int cnt = 0;
	long long ans = 0;
	int i = 0;
	for(int i = 0; i < a.size() - 1; i++) {
		cnt += a[i].second;

		if (a[i].first == a[i+1].first) {
			continue;
		}
		ans = (ans + (a[i+1].first - a[i].first) * C(cnt, p)) % MOD;
	}
	
	cout << ans << endl;
	return 0;
}

