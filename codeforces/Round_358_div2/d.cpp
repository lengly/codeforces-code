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

#define maxN 1010
int g[maxN][maxN], f[11][maxN][maxN];

int main() {
	// freopen("input.txt","r",stdin);
	int n, m, kk;
	string s,t;

	scanf("%d%d%d\n",&n,&m,&kk);
	getline(cin, s);
	getline(cin, t);

	memset(g,0,sizeof(g));
	memset(f,0,sizeof(f));

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if (s[i-1] == t[j-1]) {
				g[i][j] = g[i-1][j-1] + 1;
			}
		}
	}

	for(int k = 1; k <= kk; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				f[k][i][j] = max(f[k][i-1][j], f[k][i][j-1]);
				int d = g[i][j];
				f[k][i][j] = max(f[k][i][j], f[k-1][i-d][j-d] + d);
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= kk; i++) {
		ans = max(ans, f[i][n][m]);
	}
	printf("%d\n", ans);
	return 0;
}

