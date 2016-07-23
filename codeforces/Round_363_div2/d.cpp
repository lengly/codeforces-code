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

#define maxN 200010

int n, a[maxN], fa[maxN];
vector<int> e[maxN], root, circle;
int flag[maxN];

void dfs(int x) {
	flag[x] = 1;
	for(int i = 0; i < e[x].size(); i++) {
		int y = e[x][i];
		if (flag[y] == 0) {
			dfs(y);
		} else if (flag[y] == 1) {
			circle.push_back(y);
		}
	}
	flag[x] = 2;
}

int main() {
	// freopen("input.txt","r",stdin);
	scanf("%d", &n);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		fa[i] = a[i];
		if (a[i] != i) {
			e[a[i]].push_back(i);
		} else {
			root.push_back(i);
		}
	}
	memset(flag, 0, sizeof(flag));
	for(int i = 1; i <= n; i++) {
		if (flag[i] == 0) dfs(i);
	}

	if (root.size() > 1) {
		for(int i = 1; i < root.size(); i++) {
			a[root[i]] = root[0];
			ans++;
		}
	}
	int aim;
	if (root.size() > 0) {
		aim = root[0];
	} else {
		aim = circle[0];
	}
	for(int i = 0; i < circle.size(); i++) {
		a[circle[i]] = aim;
		ans++;
	}
	printf("%d\n", ans);
	for(int i = 1; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("%d\n", a[n]);
	// for(int i = 0; i < root.size(); i++) {
	// 	printf("%d ", root[i]);
	// }
	// printf("\n");
	// for(int i = 0;i < circle.size(); i++) {
	// 	printf("%d ", circle[i]);
	// }
	// printf("\n");
	return 0;
}
