#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;


int main() {
	// freopen("input.txt","r",stdin);
	int n;
	cin >> n;
	bool flag = false;

	for(int i = 0; i <= n / 1234567; i++) {
		for(int j = 0; j <= (n - i * 1234567) / 123456; j++) {
			int k = n - i * 1234567 - j * 123456;
			if (k >= 0 && k % 1234 == 0) {
				flag = true;
				break;
			}
		}
	}

	if (flag) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	
	return 0;
}

