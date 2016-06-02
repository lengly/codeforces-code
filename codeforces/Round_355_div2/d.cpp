#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
#include<unordered_set>
#include<algorithm>
using namespace std;

#define LIMIT 1000000
#define inf 10000000
int n,m,p;

struct node {
	int x,y,dis;
	node(int _x, int _y, int _dis) {
		x = _x; y = _y; dis = _dis;
	}
};

bool cmp(const node &a, const node &b) {
	return a.dis < b.dis;
}

void bfs(int k, vector<vector<pair<int, int> > > &pst, vector<vector<int> > &ans) {
	int g[n+3][m+3];
	memset(g,0,sizeof(g));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			g[i][j] = inf;
	vector<node> rq;
	for(int i=0;i<pst[k-1].size();i++) {
		int x = pst[k-1][i].first;
		int y = pst[k-1][i].second;
		g[x][y] = ans[k-1][i];
		rq.push_back(node(x, y, ans[k-1][i]));
	}
	// for(int i=1;i<=n;i++) {
	// 	for(int j=1;j<=m;j++) {
	// 		printf("%d,", g[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("===========\n");
	// for(int i=0;i<pst[k].size();i++) {
	// 	g[pst[k][i].first][pst[k][i].second] = -2;
	// }
	sort(rq.begin(), rq.end(), cmp);
	queue<node> q;
	for(int i=0;i<rq.size();i++) {
		q.push(rq[i]);
	}
	bool flag[n+3][m+3];
	memset(flag,1,sizeof(flag));
	int a[4],b[4];
	a[0]=0;a[1]=1;a[2]=0;a[3]=-1;
	b[0]=1;b[1]=0;b[2]=-1;b[3]=0;
	while(!q.empty()) {
		node head = q.front();
		int dis = g[head.x][head.y];
		q.pop();
		flag[head.x][head.y] = true;

		for(int i=0;i<4;i++) {
			int tx = head.x + a[i];
			int ty = head.y + b[i];
			if (tx <= 0 || tx > n || ty <= 0 || ty > m) continue;
			if (g[tx][ty] > dis + 1) {
				g[tx][ty] = dis + 1;
				if (flag[tx][ty]) {
					flag[tx][ty] = false;
					q.push(node(tx, ty, g[tx][ty]));
				}
			}
		}
	}

	for(int i=0;i<pst[k].size();i++) {
		ans[k][i] = g[pst[k][i].first][pst[k][i].second];
	}
}

int main() {
	// freopen("input.txt","r",stdin);

	scanf("%d%d%d",&n,&m,&p);
	int g[310][310];
	vector<vector<pair<int, int> > > pst(p + 1);
	vector<vector<int> > ans(p + 1);
	memset(g,0,sizeof(g));
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			scanf("%d",&g[i][j]);
			pst[g[i][j]].push_back(make_pair(i,j));
			ans[g[i][j]].push_back(-1);
		}
	}

	for(int i=0;i<pst[1].size();i++) {
		ans[1][i] = pst[1][i].first + pst[1][i].second - 2;
	}

	for(int k=2;k<=p;k++) {
		if (pst[k].size() * pst[k-1].size() < LIMIT) {
			for(int i=0;i<pst[k].size();i++) {
				for(int j=0;j<pst[k-1].size();j++) {
					int dis = abs(pst[k][i].first - pst[k-1][j].first) 
							+ abs(pst[k][i].second - pst[k-1][j].second)
							+ ans[k-1][j];
					if (ans[k][i] == -1) {
						ans[k][i] = dis;
					} else {
						ans[k][i] = min(ans[k][i], dis);
					}
				}
			}
		} else {
			bfs(k, pst, ans);
		}
	}
	// for(int i=0;i<ans[1].size();i++) {
	// 	printf("%d,", ans[1][i]);
	// }
	// printf("\n");
	printf("%d\n", ans[p][0]);
	return 0;
}

