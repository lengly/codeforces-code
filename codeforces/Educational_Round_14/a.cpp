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
	int cnt = 0 ,a;
	scanf("%d", &n);;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a);
		cnt += a;
	}
	if ((n == 1 && cnt == 1) || (n > 1 && cnt == n - 1)) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}

	return 0;
}
