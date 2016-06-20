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

#define maxN 5010

typedef pair<int, int> PII;

PII p[maxN];
int n, s;

long long area(PII a, PII b, PII c) {
	return (long long)(b.first - a.first)*(c.second - a.second) 
		- (long long)(c.first - a.first)*(b.second - a.second);
}

int main() {
	// freopen("input.txt","r",stdin);
	scanf("%d%d", &n, &s);
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &p[i].first, &p[i].second);
	}
	int a = 0, b = 1, c = 2;
	long long ans = area(p[a], p[b], p[c]);
	while(true) {
		bool flag = true;
		for(int i = 0; i < n; i++) {
			long long t = area(p[i], p[b], p[c]);
			if (t > ans) {
				ans = t; a = i; flag = false;
			}
		}
		for(int i = 0; i < n; i++) {
			long long t = area(p[a], p[i], p[c]);
			if (t > ans) {
				ans = t; b = i; flag = false;
			}
		}
		for(int i = 0; i < n; i++) {
			long long t = area(p[a], p[b], p[i]);
			if (t > ans) {
				ans = t; c = i; flag = false;
			}
		}
		if (flag) break;
	}
	cout << p[a].first + p[b].first - p[c].first << ' ' << p[a].second + p[b].second - p[c].second << endl;
	cout << p[b].first + p[c].first - p[a].first << ' ' << p[b].second + p[c].second - p[a].second << endl;
	cout << p[c].first + p[a].first - p[b].first << ' ' << p[c].second + p[a].second - p[b].second << endl;
	return 0;
}

