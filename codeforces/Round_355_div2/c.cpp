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

#define md 1000000007

int getNum(char ch) {
	if (ch >= '0' && ch <= '9') {
		return ch - '0';
	}
	if (ch >= 'A' && ch <= 'Z') {
		return ch - 'A' + 10;
	}
	if (ch >= 'a' && ch <= 'z') {
		return ch - 'a' + 36;
	}
	if (ch == '-') return 62;
	if (ch == '_') return 63;
}

int main() {
	// freopen("input.txt","r",stdin);
	string s;
	getline(cin, s);
	int cnt[100];
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<64;i++) {
		for(int j=0;j<64;j++) {
			cnt[i&j] ++;
		}
	}
	long long ans = 1;
	for(int i=0;i<s.size();i++) {
		ans *= cnt[getNum(s[i])];
		if (ans >= md) ans %= md;
	}
	if (ans >= md) ans %= md;
	if (ans < 0) ans += md;

	printf("%I64d\n", ans);

	return 0;
}

