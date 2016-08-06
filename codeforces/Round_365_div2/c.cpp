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

#define maxN 10010
int n;
long long v, u, w;
long long x[maxN], y[maxN];

int main() {
	// freopen("input.txt","r",stdin);
	scanf("%d%I64d%I64d%I64d", &n, &w, &v, &u);
	bool flag = true;
	int st = 1;
	for(int i = 1; i <= n; i++) {
		scanf("%I64d%I64d", &x[i], &y[i]);
		double t_car = (double)(x[i]) / v;
		double t_p = (double)(y[i]) / u;
		if (t_p > t_car && y[i] <= w) {
			flag = false;
		}
		if (y[i] < y[st]) {
			st = i;
		} else if (y[i] == y[st] && x[i] > x[st]) {
			st = i;
		}
	}
	x[0] = x[n]; y[0] = y[n];
	double ans = 0;
	if (flag) {
		ans = w;
		ans /= u;
		printf("%.10lf\n", ans);
		return 0;
	}
	double pst = 0;
	flag = false;
	for(int i = 1; i <= n; i++) {
		if (y[st] > w) {
			if (y[st] == y[st-1]) {
				ans = w; ans /= u;break;
			}
			y[st] = w;
			x[st] = (w - y[st-1]) / (y[st] - y[st-1]) * (x[st] - x[st-1]) + x[st-1];
			flag = true;
		}
		double t_car = (double)(x[st]) / v;
		ans = ((double)(y[st]) - pst) / u + ans;
		pst = y[st];
		if (ans < t_car) ans = t_car;

		if (++st == n+1) st = 1;
		if (pst > y[st]) break;
		if (flag) break;
	}
	ans += (w - pst) / u;
	printf("%.10lf\n", ans);

	return 0;
}
