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

#define maxN 200010

int main() {
	// freopen("input.txt","r",stdin);

	int n, a[200], b[200];
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = i;
	}
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
				swap(b[i], b[j]);
			}
		}
	}
	for(int i = 0; i < n/2; i++) {
		printf("%d %d\n", b[i]+1, b[n-i-1]+1);
	}
	return 0;
}
