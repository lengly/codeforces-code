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

struct node
{
	int val,cnt;
	node *left;
	node *right;
	node(int x) : val(x), cnt(0), left(NULL), right(NULL) {}
};

void insert(long long x, node* r, int dep) {
	r->cnt++;
	if (dep == -1) {
		return;
	}

	if ((x & (1 << dep)) == 0) {
		if (r->left == NULL) {
			r->left = new node(0);
		}
		insert(x, r->left, dep-1);
	} else {
		if (r->right == NULL) {
			r->right = new node(1);
		}
		insert(x, r->right, dep-1);
	}
}

void remove(long long x, node* r, int dep) {
	r->cnt--;
	if (dep == -1) {
		return;
	}

	if ((x & (1 << dep)) == 0) {
		remove(x, r->left, dep-1);
	} else {
		remove(x, r->right, dep-1);
	}

	r->cnt = 0;
	if (r->left != NULL) {
		r->cnt += r->left->cnt;
		if (r->left->cnt == 0) {
			r->left = NULL;
		}
	}
	if (r->right != NULL) {
		r->cnt += r->right->cnt;
		if (r->right->cnt == 0) {
			r->right = NULL;
		}
	}
}

long long query(long long x, node* r, int dep, long long ans) {
	if (dep == -1) {
		return ans;
	}

	if ((x & (1 << dep)) == 0) {
		if (r->right != NULL) {
			return query(x, r->right, dep-1, ans+(1<<dep));
		} else {
			return query(x, r->left, dep-1, ans);
		}
	} else {
		if (r->left != NULL) {
			return query(x, r->left, dep-1, ans+(1<<dep));
		} else {
			return query(x, r->right, dep-1, ans);
		}
	}
}

int main() {
	// freopen("input.txt","r",stdin);
	node* root = new node(0);
	insert(0, root, 30);
	int n;
	scanf("%d\n", &n);
	for(int i = 0; i < n; i++) {
		char ch;
		long long x;
		scanf("%c %I64d\n", &ch, &x);
		if (ch == '+') {
			insert(x, root, 30);
		} else if (ch == '-') {
			remove(x, root, 30);
		} else if (ch == '?') {
			printf("%I64d\n", query(x, root, 30, 0));
		}
	}
	return 0;
}
