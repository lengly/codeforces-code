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

int main() {

	string s;
	int l, r, p;
	// freopen("input.txt","r",stdin);
	getline(cin, s);
	p = s.size(); l = 0;
	for(int i = 0; i < s.size(); i++) {
		if (s[i] == '.') {
			p = i;break;
		}
	}
	l = p;
	for(int i = 0; i < p; i++) {
		if (s[i] != '0') {
			l = i;break;
		}
	}
	r = p - 1;
	for(int i = s.size() - 1; i > p; i--) {
		if (s[i] != '0') {
			r = i;break;
		}
	}
	string t = s.substr(l, r-l+1);
	p = t.size();
	for(int i = 0; i < t.size(); i++) {
		if (t[i] == '.') { p = i;break;}
	}
	// cout << t << endl;
	int nl = p, nr = t.size()-1 - p;
	if (nr < 0) nr = 0;
	// cout << nl << ' ' << nr << endl;
	if (nl == 0 && nr == 0) {
		printf("0\n");
	} else if (nl == 0) {
		bool flag = true;
		int cnt = 0;
		for(int i = 1; i < t.size(); i++) {
			if (flag && t[i] == '0') {
				cnt++;
				continue;
			}
			if (flag) {
				printf("%c", t[i]);
				if (i < t.size() - 1) printf(".");
				flag = false;
			} else {
				printf("%c", t[i]);
			}
		}
		printf("E-%d\n", cnt+1);
	} else if (nl + nr == 1) {
		printf("%c\n", t[0]);
	} else {
		int tmp = 0;
		for(int i = 0; i < t.size(); i++) {
			if (t[i] >= '1' && t[i] <= '9') tmp++;
		}
		if (tmp == 1) {
			printf("%c", t[0]);
		} else {
			printf("%c.", t[0]);	
		}
		int cnt = 0;
		bool flag = true;
		for(int i = 1; i < t.size(); i++) {
			if (t[i] == '.') {
				flag = false;
				continue;
			}
			if (flag) cnt++;
			if (tmp != 1) {
				if (nr == 0 && t[i]>='1' && t[i]<='9') tmp--;
				printf("%c", t[i]);	
			}
			
		}
		if (cnt == 0) {
			printf("\n");
		} else {
			printf("E%d\n", cnt);
		}
	}
	
	return 0;
}
