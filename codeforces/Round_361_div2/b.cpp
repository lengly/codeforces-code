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

int n;
int a[maxN], f[maxN];
bool flag[maxN];
queue<int> q;

int main() {
	// freopen("input.txt","r",stdin);
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		f[i] = 100000000;
	}
	f[1] = 0;

	memset(flag, 1, sizeof(flag));
	q.push(1);
	while(!q.empty()) {
		int x = q.front();
		q.pop();flag[x] = true;

		int y;

		for(int i = 1; i < 4; i++) {
			if (i == 1) {
				y = a[x];
			} else if (i == 2) {
				if (x == 1) continue;
				y = x - 1;
			} else if (i == 3) {
				if (x == n) continue;
				y = x + 1;
			}

			if (f[y] > f[x] + 1) {
				f[y] = f[x] + 1;
				if (flag[y]) {
					q.push(y);
					flag[y] = false;
				}
			}
		}
	}

	for(int i = 1; i < n; i++) {
		printf("%d ", f[i]);
	}
	printf("%d\n", f[n]);

	return 0;
}

