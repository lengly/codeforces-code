#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;


int main() {
	// freopen("input.txt","r",stdin);
	int n, a;
	scanf("%d%d",&n,&a);
	int d[200];
	memset(d,0,sizeof(d));
	for(int i=1;i<=n;i++) {
		scanf("%d",&d[i]);
	}
	int l = a-1, r = a+1, ans = d[a];
	while (l >= 1 || r <= n) {
		if (l < 1) {
			ans += d[r];
		} else if (r > n) {
			ans += d[l];
		} else if (d[l] + d[r] == 2) {
			ans += 2;
		}
		l--;r++;
	}
	cout << ans << endl;

	return 0;
}

