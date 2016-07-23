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

#define maxN 110

int n, f[maxN][3];

int main() {
	// freopen("input.txt","r",stdin);
	scanf("%d", &n);
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		f[i][0] = max(f[i-1][0], max(f[i-1][1], f[i-1][2]));
		if ((a & 1) != 0) {
			f[i][1] = max(f[i-1][0], f[i-1][2]) + 1;
		}
		if ((a & 2) != 0) {
			f[i][2] = max(f[i-1][0], f[i-1][1]) + 1;
		}
		// printf("%d\t%d\t%d\t%d\n", i, f[i][0], f[i][1], f[i][2]);
	}
	int ans = n - max(f[n][0], max(f[n][1], f[n][2]));
	printf("%d\n", ans);
	return 0;
}
