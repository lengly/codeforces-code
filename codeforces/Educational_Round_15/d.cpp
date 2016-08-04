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

long long d, k, a, b, t;

int main() {
	// freopen("input.txt","r",stdin);
	long long ans;
	cin >> d >> k >> a >> b >> t;
	if (k >= d) {
		ans = d * a;
	} else if (k*a+t >= k*b) {
		long long dis_car = min(k, d);
		ans = k * a + (d - k) * b;
	} else {
		long long tm = d / k;
		ans = tm * (k*a+t) + (d-tm*k)*a;
		if (d % k == 0) {
			ans -= t;
		}

		long long tmp = tm *(k*a+t) - t + (d-tm*k)*b;
		ans = min(ans, tmp);
	}

	cout << ans << endl;

	return 0;
}
