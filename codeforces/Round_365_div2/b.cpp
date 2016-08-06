#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

#define maxN 100010
int n, m;
long long c[maxN], s = 0;
bool flag[maxN];

int main() {
	// freopen("input.txt","r",stdin);
	memset(flag, 0, sizeof(flag));
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%I64d", &c[i]);
		s += c[i];
	}
	c[0] = c[n]; c[n+1] = c[1];
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += c[i] * c[i-1];
	}

	for(int i = 0; i < m; i++) {
		int t;
		scanf("%d", &t);
		flag[t] = true;
		if (t == n) flag[0] = true;
		else if (t == 1) flag[n+1] = true;
		s -= c[t];
		long long now = s;
		if (!flag[t-1]) now -= c[t-1];
		if (!flag[t+1]) now -= c[t+1];
		ans += now * c[t];
	}

	cout << ans << endl;
	return 0;
}
