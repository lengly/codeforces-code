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

int n;

int main() {
	// freopen("input.txt","r",stdin);
	int l = 0, r = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int a,b;
		scanf("%d%d", &a, &b);
		if (a < b) r++;
		else if (a > b) l++;
	}
	if (l > r) {
		printf("Mishka\n");
	} else if (l < r) {
		printf("Chris\n");
	} else {
		printf("Friendship is magic!^^\n");
	}

	return 0;
}
