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



int main() {
	// freopen("input.txt","r",stdin);

	double a,b;
	double ans = -1;

	scanf("%lf%lf", &a, &b);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		double x,y,v;
		scanf("%lf%lf%lf", &x, &y, &v);
		double t = sqrt((x-a)*(x-a) + (y-b)*(y-b))/v;
		if (ans == -1) ans =t;
		else ans = min(ans, t);
	}
	printf("%.20lf\n", ans);


	return 0;
}
