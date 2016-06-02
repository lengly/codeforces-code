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
	long long n,h,k;
	scanf("%I64d%I64d%I64d",&n,&h,&k);
	long long ans = 0, t;
	long long now_h = 0;
	for(int i=0;i<n;i++) {
		scanf("%I64d",&t);
		if (now_h + t <= h) {
			now_h += t;
		} else {
			long long c = now_h + t - h;
			long long kk = (c + k - 1) / k;
			ans += kk;
			now_h -= kk * k;
			if (now_h < 0) now_h = 0;
			now_h += t;
		}
	}
	if (now_h > 0) {
		long long kk = (now_h + k - 1) / k;
		ans += kk;
	}
	printf("%I64d\n", ans);

	return 0;
}

