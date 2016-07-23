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

int n,m,g[maxN][maxN];
int row[maxN], col[maxN];

int main() {
	// freopen("input.txt","r",stdin);
	scanf("%d%d\n", &n, &m);
	char ch;
	int tot = 0;
	memset(g, 0, sizeof(g));
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%c", &ch);
			if (ch == '*') {
				g[i][j] = 1;
				row[i]++;col[j]++;tot++;
			}
		}
		scanf("\n");
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if (row[i] + col[j] - g[i][j] == tot) {
				printf("YES\n");
				printf("%d %d\n", i+1, j+1);
				return 0;
			}
		}
	}
	
	printf("NO\n");
	return 0;
}