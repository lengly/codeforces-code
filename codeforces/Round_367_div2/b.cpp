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

#define maxN 100100

int n,m, a[maxN], ans[maxN];
vector<pair<int, int> > p;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	// freopen("input.txt","r",stdin);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	a[0] = 0;
	sort(a, a+n+1);
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		p.push_back(make_pair(x, i));
	}
	sort(p.begin(), p.end(), cmp);
	int tp = 0;
	for(int i = 0; i < p.size(); i++) {
		while(tp < n && p[i].first>=a[tp+1]) tp++;
		ans[p[i].second] = tp;
	}
	for(int i = 0; i < m; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
