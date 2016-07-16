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
	// freopen("input.txt","r",stdin);

	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> a;

	vector<pair<string, int> > ans;
	string s;
	int num = 0;
	for(int i = 0; i < n; i++) {
		cin >> s;
		if (s == "insert") {
			cin >> num;
			ans.push_back(make_pair("insert", num));
			a.push(num);
		} else if (s == "getMin") {
			cin >> num;
			while (a.size() != 0 && a.top() < num) {
				ans.push_back(make_pair("removeMin", 0));
				a.pop();
			}
			if (a.size() == 0 || a.top() > num) {
				ans.push_back(make_pair("insert", num));
				a.push(num);
			}
			ans.push_back(make_pair("getMin", num));
		} else if (s == "removeMin") {
			if (a.size() == 0) {
				ans.push_back(make_pair("insert", 1));
			} else {
				a.pop();
			}
			ans.push_back(make_pair("removeMin", 0));
		}
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size();i++) {
		if (ans[i].first == "removeMin") {
			printf("%s\n", ans[i].first.c_str());
		} else {
			printf("%s %d\n", ans[i].first.c_str(), ans[i].second);
		}
	}
	return 0;
}

