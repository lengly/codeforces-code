#include<bits/stdc++.h>
using namespace std;

int main() {
	// freopen("input.txt","r",stdin);

	int n, b, d;
	scanf("%d%d%d", &n, &b, &d);
	int ans = 0, now = 0;
	for(int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (a > b) continue;
		now += a;
		if (now > d) {
			now = 0;
			ans++;
		}
	}
	printf("%d\n", ans);

	return 0;
}
