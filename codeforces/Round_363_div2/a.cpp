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

#define maxN 200010

int n;
long long a[maxN];
string s;

int main() {
	// freopen("input.txt","r",stdin);
	scanf("%d\n", &n);
	getline(cin, s);
	for(int i=0;i<n;i++) {
		scanf("%I64d", &a[i]);
	}
	long long ans=1e15;
	for(int i = 0; i < s.size()-1; i++) {
		if (s[i] == 'R' && s[i+1] == 'L') {
			ans = min(ans, (a[i+1] - a[i]+1) / 2);
		}
	}
	if (ans == 1e15) ans = -1;
	cout << ans << endl;


	return 0;
}
