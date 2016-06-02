#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
#include<cmath>
#include<unordered_set>
#include<algorithm>

#define md 1000000007
#define maxN 1010

using namespace std;

int n;
int g[maxN][maxN];
int d[8][maxN][maxN];
double lg[8][maxN][maxN];
//   1 2 3
//   0   4
//   7 6 5
int a[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int b[8] = {-1, -1, 0, 1, 1, 1, 0, -1};


int main() {
	// freopen("input.txt", "r", stdin);
	memset(g,0,sizeof(g));
	scanf("%d\n",&n);
	char ch; 
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%c",&ch);
			g[i][j] = ch - '0';
		}
		scanf("\n");
	}
	memset(d,0,sizeof(d));
	memset(lg,0,sizeof(lg));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 0; k < 4; k++) {
				if (g[i][j] == 0) {
					d[k][i][j] = 0;
					lg[k][i][j] = -1;
				// } else if (i == 1 || j == 1) {
				// 	d[k][i][j] = 1;
				// 	lg[k][i][j] = log(g[i][j]);
				} else {
					d[k][i][j] = d[k][i + a[k]][j + b[k]] + 1;
					lg[k][i][j] = lg[k][i + a[k]][j + b[k]] + log(g[i][j]);
				}
			}
		}
	}
	for(int i = n; i > 0; i--) {
		for(int j = n; j > 0; j--) {
			for(int k = 4; k < 8; k++) {
				if (g[i][j] == 0) {
					d[k][i][j] = 0;
					lg[k][i][j] = -1;
				// } else if (i == n || j == n) {
				// 	d[k][i][j] = 1;
				// 	lg[k][i][j] = log(g[i][j]);
				} else {
					d[k][i][j] = d[k][i + a[k]][j + b[k]] + 1;
					lg[k][i][j] = lg[k][i + a[k]][j + b[k]] + log(g[i][j]);
				}
			}
		}
	}

	double maxlg = -1;
	int x, y, rr = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			int r;
			r = min(min(d[0][i][j], d[2][i][j]), min(d[4][i][j], d[6][i][j]));
			double tmp = 0;
			for(int k = 0; k < 8; k += 2) {
				tmp += lg[k][i][j] - lg[k][i + a[k] * r][j + b[k] * r];
			}
			if (g[i][j] > 0) {
				tmp -= log(g[i][j]) * 3;	
			}
			if (maxlg < tmp) {
				maxlg = tmp;
				x = i; y = j; rr = r;
			}

			r = min(min(d[1][i][j], d[3][i][j]), min(d[5][i][j], d[7][i][j]));
			tmp = 0;
			for(int k = 1; k < 8; k += 2) {
				tmp += lg[k][i][j] - lg[k][i + a[k] * r][j + b[k] * r];
			}
			if (g[i][j] > 0) {
				tmp -= log(g[i][j]) * 3;	
			}
			if (maxlg < tmp) {
				maxlg = tmp;
				x = i; y = j; rr = -r;
			}
		}
	}

	long long ans = 0;
	if (rr > 0) {
		ans = g[x][y];
		for(int k = 0;  k < 8; k += 2) {
			for(int i = 1; i < rr; i++) {
				ans *= g[x + a[k]*i][y + b[k]*i];
				if (ans >= md) {
					ans %= md;
				}
			}
		}
	} else if (rr < 0) {
		ans = g[x][y];
		for(int k = 1;  k < 8; k += 2) {
			for(int i = 1; i < -rr; i++) {
				ans *= g[x + a[k]*i][y + b[k]*i];
				if (ans >= md) {
					ans %= md;
				}
			}
		}
	}

	printf("%I64d\n", ans);
	return 0;
}
