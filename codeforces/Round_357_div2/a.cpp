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
	for(int i = 0; i < n; i++) {
		string s;
		int a,b;
		cin >> s >> a >> b;
		if (a >= 2400 && a < b) {
			flag = true;
		}
	}
	if (flag) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	
	return 0;
}

