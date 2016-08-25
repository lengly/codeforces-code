#include<bits/stdc++.h>
using namespace std;

#define maxN 1000010
int n,a,x[maxN];

int main() {
	// freopen("input.txt","r",stdin);
	scanf("%d%d", &n,&a);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &x[i]);
	}
	sort(x+1, x+n+1);
	if (n == 1) {
		printf("0\n");
		return 0;
	}
	int ans = 1e9;
	// 2 ~ n
	ans = min(ans,abs(a-x[2])+x[n]-x[2]);
	ans = min(ans,abs(a-x[n])+x[n]-x[2]);
	// 1 ~ n-1
	ans = min(ans,abs(a-x[1])+x[n-1]-x[1]);
	ans = min(ans,abs(a-x[n-1])+x[n-1]-x[1]);
	printf("%d\n", ans);;

	return 0;
}
