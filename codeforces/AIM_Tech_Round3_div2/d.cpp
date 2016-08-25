#include<bits/stdc++.h>
using namespace std;

long long a[4];

bool solve(long long n0, long long n1) {
	if (n0 * (n0 - 1) / 2 != a[0]) return false;
	if (n1 * (n1 - 1) / 2 != a[3]) return false;
	if (a[1] > n0*n1) return false;
	if (a[2] > n0*n1) return false;

	long long n = n0 + n1;
	long long now1 = n0 * n1, now2 = 0;
	if (now1 - a[1] != a[2] - now2) {
		return false;
	}
	long long gap = now1 - a[1];
	if (n1 == 0) {
		if (a[1] != 0 || a[2] != 0) {
			return false;
		}
		for (int i = 0; i < n0; i++) printf("0");
		return true;
	}
	long long r = gap / n1;
	long long m = gap % n1;

	if (m == 0) {
		for (int i = 0; i < n0 - r; i++) printf("0");
		for (int i = 0; i < n1; i++) printf("1");
		for (int i = 0; i < r; i++) printf("0");
		printf("\n");
	}
	else {
		for (int i = 0; i < n0 - r - 1; i++) printf("0");
		for (int i = 0; i < m; i++) printf("1");
		printf("0");
		for (int i = 0; i < n1 - m; i++) printf("1");
		for (int i = 0; i < r; i++) printf("0");
		printf("\n");
	}
	return true;
}

int main() {
	//freopen("input.txt","r",stdin);
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}

	long long n0 = int(sqrt(2 * a[0])) + 1;
	long long n1 = int(sqrt(2 * a[3])) + 1;
	if (n0 > 1 && n1 > 1) {
		if (solve(n0, n1)) return 0;
	}
	if (n0 == 1) {
		if (solve(n0, n1)) return 0;
		if (solve(n0 - 1, n1)) return 0;
	}
	if (n1 == 1) {
		if (solve(n0, n1)) return 0;
		if (solve(n0, n1 - 1)) return 0;
	}
	if (n0 == 1 && n1 == 1) {
		if (solve(n0 - 1, n1 - 1)) return 0;
	}
	printf("Impossible\n");
	return 0;
}