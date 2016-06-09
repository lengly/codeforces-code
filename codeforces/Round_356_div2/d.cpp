#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<algorithm>
using namespace std;

long long m;
map<long long, pair<int, long long> > g;

pair<int, long long> solve(long long x) {
	if (x == 0) {
		return make_pair(0,0);
	}
	if (g.find(x) != g.end()) {
		return g[x];
	}

	long long a = cbrt(x);
	long long b = a - 1;
	pair<int, long long> ret1 = solve(x - a*a*a);
	pair<int, long long> ret2 = solve(a*a*a - 1 - b*b*b);
	if (ret1.first >= ret2.first) {
		g[x] = make_pair(ret1.first + 1, ret1.second + a*a*a);
	} else {
		g[x] = make_pair(ret2.first + 1, ret2.second + b*b*b);
	}
	return g[x];
}

int main() {
	// freopen("input.txt","r",stdin);
	cin >> m;
	solve(m);
	cout << g[m].first << ' ' << g[m].second << endl;
	return 0;
}