#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<set>
#include<unordered_set>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

int n, m, p;
double s, v1, v2;

int main() {
	// freopen("input.txt","r",stdin);
	cin >> n >> s >> v1 >> v2 >> m;
	p = (n + m - 1) / m;

	double k = (p + (p-1) * (v2-v1)/(v1+v2));
	double ans = s * k / (v2 - v1 + v1 * k);
	printf("%.10lf\n", ans);

	return 0;
}
