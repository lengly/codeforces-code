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
	int a[10];
	cin >> n;
	for(int i = 0; i < n; i++) {
		char ch;
		cin >> ch;
		a[i] = ch - '0';
	}

	int x[10] = {4,1,1,1,2,2,2,3,3,3};
	int y[10] = {2,1,2,3,1,2,3,1,2,3};

	int cnt = 0;
	for(int i = 0; i < 10; i++) {
		bool flag = true;
		int px = x[i], py = y[i];
		for(int j = 0; j < n-1; j++) {
			px += x[a[j+1]] - x[a[j]];
			py += y[a[j+1]] - y[a[j]];

			if (px == 4 && py == 2) continue;
			if (min(px, py) <= 0 || max(px, py) > 3) {
				flag = false; break;
			}
		}

		if (flag) cnt++;
	}
	if (cnt == 1) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}


	return 0;
}

