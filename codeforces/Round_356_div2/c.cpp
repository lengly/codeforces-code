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

int p[19] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49};

int main() {
	// freopen("input.txt","r",stdin);
	int n = 19, cnt = 0;
	string s;
	for(int i = 0; i < n; i++) {
		fflush(stdout);
		printf("%d\n", p[i]);
		getline(cin, s);
		if (s == "yes") {
			cnt ++;
			if (cnt == 2) break;
		}
	}
	if (cnt >= 2) {
		printf("composite\n");
	} else {
		printf("prime\n");
	}
	return 0;
}

