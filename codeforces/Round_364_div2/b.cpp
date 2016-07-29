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

long long n, m;
set<long long> row, col;

int main() {
	// freopen("input.txt","r",stdin);
	scanf("%I64d%I64d", &n, &m);
	for(int i = 0; i < m; i++) {
		long long x, y;
		scanf("%I64d%I64d", &x, &y);
		row.insert(x);col.insert(y);
		long long ans = n*n - n * (row.size() + col.size()) + (long long)(row.size()) * (long long)(col.size());
		printf("%I64d ", ans);
	}
	printf("\n");
	return 0;
}
