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
	int n,h;
	scanf("%d%d",&n,&h);
	int a, ans = 0;
	for(int i=0;i<n;i++) {
		scanf("%d",&a);
		if (a <= h) ans++;
		else ans += 2;
	}
	printf("%d\n", ans);

	return 0;
}

