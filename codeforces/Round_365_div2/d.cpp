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

struct node {
	int l, r, p;
	void init(int _p) {
		scanf("%d%d", &l, &r);
		p = _p;
	}
};

#define maxN 1000100
int n, m, a[maxN], s[maxN], ans[maxN], f[maxN];
vector<node> q;
unordered_map<int, int> last;

bool cmp(node a, node b) {
	return a.r < b.r;
}

void update(int x, int value) {
	while (x <= n) {
		f[x] ^= value;
		x += x & (-x);
	}
}

int query(int x) {
	int s = 0;
	while(x > 0) {
		s ^= f[x];
		x -= x & (-x);
	}
	return s;
}

int main() {
	// freopen("input.txt","r",stdin);
	memset(s, 0, sizeof(s));
	memset(f, 0, sizeof(f));
	scanf("%d", &n);
	for(int i = 1; i <= n ; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i-1] ^ a[i];
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		node t;t.init(i);
		q.push_back(t);
	}
	sort(q.begin(), q.end(), cmp);
	int tp = 0;
	for (int i = 1; i <= n; i++) {
		if (last.find(a[i]) == last.end()) {
			last[a[i]] = i;
		} else {
			update(last[a[i]], a[i]);
			last[a[i]] = i;
		}
		update(i, a[i]);
		while(q[tp].r == i && tp < q.size()) {
			int tmp = s[q[tp].r] ^ s[q[tp].l-1] ^ query(q[tp].r) ^ query(q[tp].l-1);
			ans[q[tp].p] = tmp;
			tp++;
		}
	}

	for(int i = 0; i < m; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
