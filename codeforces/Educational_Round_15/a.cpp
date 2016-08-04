#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<queue>
#include<algorithm>
using namespace std;

#define maxN 100010
int n, a[maxN];

int main() {
	// freopen("input.txt","r",stdin);
	int n;
	vector<int> p;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int ans = 1, now = 1;
	for(int i = 1; i < n; i++) {
		if (a[i] > a[i-1]) {
			now ++;
			ans = max(ans, now);
		} else {
			now = 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}
