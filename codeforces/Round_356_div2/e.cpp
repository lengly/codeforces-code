#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<algorithm>
using namespace std;

int n, m, num;
int g[510][510], cnt[250000], outside[250000];
bool flag[250000];

void dfs(int x, int y) {
	g[x][y] = num;
	if (g[x+1][y] == -1) dfs(x+1, y);
	if (g[x-1][y] == -1) dfs(x-1, y);
	if (g[x][y+1] == -1) dfs(x, y+1);
	if (g[x][y-1] == -1) dfs(x, y-1);
}

void init() {
	memset(g, 0, sizeof(g));
	memset(cnt, 0, sizeof(cnt));
	memset(outside, 0, sizeof(outside));
	scanf("%d%d\n", &n, &m);
	string s;
	for(int i = 1; i <= n; i++) {
		getline(cin, s);
		for(int j = 0; j < s.size(); j++) {
			if (s[j] == '.') g[i][j+1] = -1;
		}
	}

	num = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if (g[i][j] == -1) {
				num++;
				dfs(i, j);
			}
			cnt[g[i][j]]++;
		}
	}
	memcpy(outside, cnt, sizeof(cnt));
}

int check(int x, int y) {
	memset(flag,1,sizeof(flag));
	int ret = m * m;
	for(int k = x; k < x + m; k++) {
		if (g[k][y-1] > 0 && flag[g[k][y-1]]) {
			flag[g[k][y-1]] = false;
			ret += outside[g[k][y-1]];
		}
		if (g[k][y+m] > 0 && flag[g[k][y+m]]) {
			flag[g[k][y+m]] = false;
			ret += outside[g[k][y+m]];
		}
	}
	for(int k = y; k < y + m; k++) {
		if (g[x-1][k] > 0 && flag[g[x-1][k]]) {
			flag[g[x-1][k]] = false;
			ret += outside[g[x-1][k]];
		}
		if (g[x+m][k] > 0 && flag[g[x+m][k]]) {
			flag[g[x+m][k]] = false;
			ret += outside[g[x+m][k]];
		}
	}
	return ret;
}

void work() {
	for(int i = 1; i < m; i++) {
		for(int j = 1; j <= m; j++) {
			outside[g[i][j]] --;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n-m+1; i++) {
		if (i & 1) {
			// move down
			for(int k = 1; k <= m; k++) {
				outside[g[i+m-1][k]]--;
				outside[g[i-1][k]]++;
			}
			ans = max(ans, check(i, 1));
			// move right
			for(int j = 2; j <= n-m+1; j++) {
				for(int k = i; k < i+m; k++) {
					outside[g[k][j+m-1]]--;
					outside[g[k][j-1]]++;
				}
				ans = max(ans, check(i, j));
			}
		} else {
			// move down
			for(int k = n-m+1; k <= n; k++) {
				outside[g[i+m-1][k]]--;
				outside[g[i-1][k]]++;
			}
			ans = max(ans, check(i, n-m+1));
			//move left
			for(int j = n-m; j > 0; j--) {
				for(int k = i; k < i+m; k++) {
					outside[g[k][j]]--;
					outside[g[k][j+m]]++;;
				}
				ans = max(ans, check(i, j));
			}
		}
	}
	cout << ans << endl;
}

int main() {
	// freopen("input.txt","r",stdin);
	init();
	work();
	return 0;
}

