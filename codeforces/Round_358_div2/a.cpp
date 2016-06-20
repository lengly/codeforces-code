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
	int n,m;
	cin >> n >> m;
	long long a[5], b[5];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(int i = 1; i <= 5; i++) {
		a[i % 5] = n / 5;
		if (i <= (n % 5)) {
			a[i % 5] ++;
		}
		b[i % 5] = m / 5;
		if (i <= (m % 5)) {
			b[i % 5]  ++;
		}
	}
	// for(int i = 0; i<5;i++){
	// 	printf("%d|%d\n", a[i], b[i]);
	// }
	long long ans = 0;
	for(int i = 0; i < 5; i++) {
		ans += a[i] * b[(5 - i) % 5];
	}
	cout << ans << endl;
	return 0;
}

