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

#define maxN 1000010

int n,m,p[maxN];
vector<int> e[maxN], position, value;
bool flag[maxN];

void dfs(int x) {
	position.push_back(x);
	value.push_back(p[x]);
	flag[x] = false;
	for(int i = 0; i < e[x].size(); i++) {
		int y = e[x][i];
		if (flag[y]) dfs(y);
	}
}

int main() {
	// freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	memset(flag, 1, sizeof(flag));
	for(int i = 1; i <= n; i++) {
		if (flag[i]) {
			position.clear();
			value.clear();
			dfs(i);
			sort(position.begin(), position.end());
			sort(value.begin(), value.end(), greater<int>());
			for(int i = 0; i < position.size(); i++) {
				p[position[i]] = value[i];
			}
		}
	}
	for(int i = 1; i < n; i++) {
		printf("%d ", p[i]);
	}
	printf("%d\n", p[n]);
	return 0;
}
