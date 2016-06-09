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
	n = 5;
	vector<int> a,b;
	int ans = 0;
	for(int i=0;i<n;i++) {
		int t;
		scanf("%d", &t);
		bool flag = true;
		for(int i=0;i<a.size();i++) {
			if (t == a[i]) {
				b[i] ++;
				flag = false;
				break;
			}
		}
		if (flag) {
			a.push_back(t);
			b.push_back(1);
		}
		ans += t;
	}
	int maxnum = 0;
	for(int i=0;i<a.size();i++) {
		if (b[i] >= 2) {
			maxnum = max(maxnum, a[i] * min(b[i], 3));
		}
	}
	ans -= maxnum;
	cout << ans << endl;
	
	return 0;
}

