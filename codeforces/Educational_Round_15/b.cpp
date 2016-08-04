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
int n;
unordered_map<long long, int> h;

int main() {
	// freopen("input.txt","r",stdin);
	long long a, ans=0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%I64d", &a);

		for(int i = 0; i < 31; i++) {
			long long p = (long long)(1) << i;
			// printf("%d %lld\n", i, p);
			if (p > a && (h.find(p-a) != h.end())) {
				ans += h[p-a];
			}
		}

		if (h.find(a) == h.end()) {
			h[a] = 1;
		} else {
			h[a] ++;
		}
	}
	printf("%I64d\n", ans);
	return 0;
}
