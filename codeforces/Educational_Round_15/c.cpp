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

#define maxN 100010
int n, m;
long long a[maxN], b[maxN];

int main() {
	// freopen("input.txt","r",stdin);

	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%I64d", &a[i]);
	}

	for(int i = 1; i <= m; i++) {
		scanf("%I64d", &b[i]);
	}

	int j = 1;
	long long r = 0;
	for(int i = 0; i < n; i++) {
		while(j < m && a[i] > b[j]) j++;
		long long dis;
		if (j == 1) {
			dis = abs(b[j] - a[i]);
		} else {
			dis = min(abs(b[j]-a[i]), abs(b[j-1]-a[i]));
		}
		r = max(r, dis);
	}
	printf("%I64d\n", r);
	return 0;
}
