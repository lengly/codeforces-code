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

char ch[15] = {'A','H','I','M','O','o','T','U','V','v','W','w','X','x','Y'};


bool judge_single(char x) {
	for(int i = 0; i < 15; i++) {
		if (ch[i] == x) return true;
	}
	return false;
}

bool judge(char a, char b) {
	if (a == 'b' && b == 'd') return true;
	if (a == 'd' && b == 'b') return true;
	if (a == 'p' && b == 'q') return true;
	if (a == 'q' && b == 'p') return true;
	if (a == b && judge_single(a) && judge_single(b)) return true;
	return false;
}

int main() {
	// freopen("input.txt","r",stdin);
	string s;
	getline(cin, s);
	bool flag = true;
	int n = s.size();
	for(int i = 0; i < n; i++) {
		if (!judge(s[i], s[n-i-1])) {
			flag = false;
			break;
		}
	}
	if (flag) {
		printf("TAK\n");
	} else {
		printf("NIE\n");
	}
	return 0;
}
