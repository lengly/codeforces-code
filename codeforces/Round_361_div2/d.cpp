#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<queue>
#include<algorithm>
using namespace std;

#define maxN 200010

int a[maxN], b[maxN], n;

long long pmax[maxN][20], pmin[maxN][20];
long long gmax[maxN][20], gmin[maxN][20];

map<pair<int, int>, int> record;

long long f(int l, int r) {
	if (l >= r) return 0;
	if (r == l + 1) {
		return a[l] == b[l];
	}
	pair<int, int> p = make_pair(l, r);
	if (record.find(p) != record.end()) {
		return record[p];
	}
	int k = 0;
	while( (1 << (k+1)) <= (r - l) ) k++;
	long long maxnum = max(pmax[l][k], pmax[r-(1 << k)][k]);
	long long minnum = min(pmin[l][k], pmin[r-(1 << k)][k]);
	long long g1, g2;
	if (pmax[l][k] > pmax[r-(1 << k)][k]) {
		g1 = gmax[l][k];
	} else {
		g1 = gmax[r-(1 << k)][k];
	}
	if (pmin[l][k] < pmin[r-(1 << k)][k]) {
		g2 = gmin[l][k];
	} else {
		g2 = gmin[r-(1 << k)][k];
	}
	long long ans = 0;
	if (g2 < g1) swap(g1, g2);
	if (maxnum == minnum) {
		ans = (g1-l+1) * (r-g2);
	}
	ans += f(l, g2) + f(g1+1, r) - f(g1+1, g2);
	record[p] = ans;
	return ans;
}

int main() {
	// freopen("input.txt","r",stdin);
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d",&b[i]);
	}

	for(int i = 0; i < n; i++) {
		pmax[i][0] = a[i]; gmax[i][0] = i;
		pmin[i][0] = b[i]; gmin[i][0] = i;
	}
	for(int k = 1; (1 << k) < n; k++) {
		for(int i = 0; i < n; i++) {
			if (i + (1 << k) > n) break; 
			if (pmax[i][k-1] > pmax[i + (1 << (k-1))][k-1]) {
				gmax[i][k] = gmax[i][k-1];
			} else {
				gmax[i][k] = gmax[i + (1 << (k-1))][k-1];
			}
			if (pmin[i][k-1] < pmin[i + (1 << (k-1))][k-1]) {
				gmin[i][k] = gmin[i][k-1];
			} else {
				gmin[i][k] = gmin[i + (1 << (k-1))][k-1];
			}
			pmax[i][k] = max(pmax[i][k-1], pmax[i + (1 << (k-1))][k-1]);
			pmin[i][k] = min(pmin[i][k-1], pmin[i + (1 << (k-1))][k-1]);	
		} 
	}
	cout << f(0, n) << endl;

	return 0;
}

