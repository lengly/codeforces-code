#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<set>
#include<unordered_set>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

#define maxN 200010

int n,m;
vector<int> e[maxN];
int s[maxN];
bool flag[maxN];

void dfs(int x) {
	flag[x] = false;
	for(int i = 0; i < e[x].size(); i++) {
		int y = e[x][i];
		if (flag[y]) {
			dfs(y);
			s[x] += s[y];
		}
	}
}

int main() {
	// freopen("input.txt","r",stdin);
	scanf("%d%d", &n, &m);
	memset(s, 0, sizeof(s));
	for(int i = 0; i < m*2; i++) {
		int a;
		scanf("%d", &a);
		s[a] = 1;
	}
	for(int i = 1; i < n; i++) {
		int a,b;
		scanf("%d%d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	memset(flag, 1, sizeof(flag));
	dfs(1);
	long long ans = 0;
	for(int i = 2; i <= n; i++) {
		ans += min((long long)s[i], (long long)(m) * 2 - s[i]);
	}
	cout << ans << endl;
	return 0;
}
