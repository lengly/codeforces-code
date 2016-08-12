#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

#define maxN 100100
int n;
string a[maxN], b[maxN];
long long c[maxN], f[maxN][2];

int main() {
	// freopen("input.txt","r",stdin);
	memset(f, 0, sizeof(f));
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%I64d\n", &c[i]);
	}
	for(int i = 0; i < n; i++) {
		getline(cin, a[i]);
		b[i].assign(a[i].rbegin(), a[i].rend());
		f[i][0] = 1e16;
		f[i][1] = 1e16;
	}

	f[0][0] = 0;
	f[0][1] = c[0];
	for(int i = 1; i < n; i++) {
		if (a[i] >= a[i-1]) {
			f[i][0] = min(f[i][0], f[i-1][0]);
		}
		if (a[i] >= b[i-1]) {
			f[i][0] = min(f[i][0], f[i-1][1]);
		}
		if (b[i] >= a[i-1]) {
			f[i][1] = min(f[i][1], f[i-1][0] + c[i]);
		}
		if (b[i] >= b[i-1]) {
			f[i][1] = min(f[i][1], f[i-1][1] + c[i]);
		}
	}
	long long ans = min(f[n-1][0], f[n-1][1]);
	if (ans == 1e16) ans = -1;
	cout << ans << endl;
	return 0;
}
