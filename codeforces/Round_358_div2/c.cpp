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
#define maxN 100100
int n;
long long a[maxN];
vector<pair<int, long long> > e[maxN];
int ans = 0;

void dfs(int x, int fa, long long now) {
	if (now < 0) now = 0;
	ans++;

	for(int i = 0; i < e[x].size(); i++) {
		int y = e[x][i].first;
		if (y == fa) continue;
		long long w = e[x][i].second + now;
		if (w > a[y]) {
			continue;
		}
		dfs(y, x, w);
	}
}

int main() {
	// freopen("input.txt","r",stdin);

	scanf("%d",&n);
	for(int i = 1; i <= n; i++) {
		scanf("%I64d\n", &a[i]);
	}
	for(int i = 2; i <= n; i++) {
		int p, c;
		scanf("%d%d", &p, &c);
		e[i].push_back(make_pair(p, c));
		e[p].push_back(make_pair(i, c));
	}
	dfs(1, 0, 0);
	ans = n - ans;
	cout << ans << endl;

	return 0;
}

