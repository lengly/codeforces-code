#include<bits/stdc++.h>
using namespace std;

#define maxN 100010
char ch[maxN];
int n;

int main() {
	// freopen("input.txt","r",stdin);
	string s;
	getline(cin, s);
	n = s.size();
	int flag = 0;
	for(int i = 0; i < s.size(); i++) {
		if (s[i] != 'a' && flag == 0) {
			flag = 1;
		} else if (s[i] == 'a' && flag == 1) {
			flag = 2;
		}
		if (flag == 1) {
			ch[i] = s[i] - 1;
		} else {
			ch[i] = s[i];
		}
	}
	if (flag == 0) {
		ch[n-1] = 'z';
	}

	for(int i = 0; i < n; i++) {
		printf("%c", ch[i]);
	}
	printf("\n");
	return 0;
}
