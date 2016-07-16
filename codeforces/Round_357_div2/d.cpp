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

#define maxN 100010

int n, m, a[maxN], d[maxN], aim[maxN];
vector<int> e[maxN];
bool flag[maxN];

void dfs(int x, int atr) {
	aim[x] = atr;
	for(int i = 0; i < e[x].size(); i++) {
		int y = e[x][i];
		if (aim[y] == 0) {
			dfs(y, atr);
		}
	}
}

int main() {
	// freopen("input.txt","r",stdin);
	memset(d, 0, sizeof(d));
	memset(flag, 0, sizeof(flag));
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int p, q;
		scanf("%d%d", &p, &q);
		e[p].push_back(q);
		d[q]++;
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		flag[a[i]] = true;
	}
	queue<int> q;
	for(int i = 1; i <= n; i++) {
		if (d[i] == 0) q.push(i);
	}
	vector<int> ans;
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		if (flag[x]) {
			ans.push_back(x);
		}

		for(int i = 0; i < e[x].size(); i++) {
			int y = e[x][i];
			d[y]--;
			if (d[y] == 0) {
				q.push(y);
			}
		}
	}
	reverse(ans.begin(), ans.end());

	memset(aim, 0, sizeof(aim));;
	for(int i = 0; i < ans.size(); i++) {
		if (aim[ans[i]] == 0) {
			dfs(ans[i], ans[i]);	
		}
	}

	for(int i = 1; i <= n; i++) {
		if (a[i] != aim[i]) {
			printf("-1\n");
			return 0;
		}
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
