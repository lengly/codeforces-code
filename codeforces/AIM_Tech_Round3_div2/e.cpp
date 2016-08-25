#include<bits/stdc++.h>
using namespace std;

#define maxN 400010
int n, h;
vector<int> e[maxN];
int ans[maxN], sum[maxN], half[maxN];

void dfs(int x, int fa) {
	sum[x] = 1;
	ans[x] = 1;
	for(int i = 0; i < e[x].size(); i++) {
		int y = e[x][i];
		if (y == fa) continue;
		dfs(y, x);
		sum[x] += sum[y];
		half[x] = max(half[x], half[y]);
		if (sum[y] > h && (sum[y] - half[y] > h)) {
			ans[x] = 0;
		}
	}
	if (sum[x] <= h) {
		half[x] = max(half[x], sum[x]);
	}
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

void dfs2(int x, int fa, int now) {
	vector<pair<int, int> > red;
	for(int i = 0; i < e[x].size(); i++) {
		int y = e[x][i];
		if (y == fa) continue;
		red.push_back(make_pair(half[y], y));
	}
	sort(red.begin(), red.end(), cmp);
	for(int i = 0; i < e[x].size(); i++) {
		int y = e[x][i];
		if (y == fa) continue;
		int next = now;
		if (n - sum[y] <= h) {
			next = max(next, n - sum[y]);
		}
		if (y != red[0].second) {
			next = max(next, red[0].first);
		} else {
			if (red.size() > 1) {
				next = max(next, red[1].first);	
			}
		}
		if (y != fa) {
			dfs2(y, x, next);
		}
	}
	if (n-sum[x] > h && (n-sum[x]-now > h)) {
		ans[x] = 0;
	}
}

int main() {
	// freopen("input.txt","r",stdin);
	scanf("%d", &n);
	h = n / 2;
	for(int i = 1; i < n; i++) {
		int a,b;
		scanf("%d%d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	memset(ans,0,sizeof(ans));
	memset(sum,0,sizeof(sum));
	memset(half,0,sizeof(half));
	dfs(1, 0);
	dfs2(1, 0, 0);
	for(int i = 1; i < n; i++) {
		printf("%d ", ans[i]);
	}
	printf("%d\n", ans[n]);

	return 0;
}
