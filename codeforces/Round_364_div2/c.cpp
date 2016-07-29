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

#define maxN 100010

int n;
string s;
int ans[maxN];
map<char, int> cnt;
int now;

int main() {
	// freopen("input.txt","r",stdin);
	scanf("%d\n", &n);
	getline(cin, s);
	now = 0;
	int tp = 0;
	for(int i = 0; i <= n; i++) ans[i] = n+1;
	for(int i = 0; i < s.size(); i++) {
		if (cnt.find(s[i]) == cnt.end()) {
			cnt[s[i]] = 1;
		} else {
			cnt[s[i]]++;	
		}
		
		if (cnt[s[i]] == 1) now++;
		while(tp < i) {
			if (cnt[s[tp]] > 1) {
				cnt[s[tp]]--;
				tp++;
			} else {
				break;
			}
		}
		ans[now] = min(ans[now], i - tp + 1);
	}

	printf("%d\n", ans[now]);
	return 0;
}
