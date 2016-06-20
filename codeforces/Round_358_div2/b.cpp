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


int main() {
	// freopen("input.txt","r",stdin);
	int n;
	int a[100010];
	scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int ans = 1;
	for(int i = 0; i < n; i++) {
		if (ans <= a[i]) ans++;
	}
	printf("%d\n", ans);
	return 0;
}

