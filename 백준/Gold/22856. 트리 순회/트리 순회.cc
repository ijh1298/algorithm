#include <iostream>
#include <vector>
using namespace std;

#define MAX 100001
int N;
int moves = 0;
int tree[MAX][2];
int parent[MAX];
bool visit[MAX] = { true };

// keep_right : 계속해서 오른쪽으로만 내려가는 경로는 부모를 방문하지 않음
void inorderLike(int cur, bool keep_right) {
	int lc = tree[cur][0];
	int rc = tree[cur][1];
	
	bool flag = true;
	if (!keep_right) {
		flag = false;
	}

	if (lc != -1 && !visit[lc]) {
		moves++;
		inorderLike(lc, false);
	}
	visit[cur] = true;
	if (rc != -1 && !visit[rc]) {
		moves++;
		inorderLike(rc, flag);
	}
	if (!keep_right)
		moves++;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	while (N--) {
		int p, lchild, rchild;
		cin >> p >> lchild >> rchild;
		tree[p][0] = lchild;
		tree[p][1] = rchild;
		parent[lchild] = p;
		parent[rchild] = p;
	}
	inorderLike(1, true);
	cout << moves;
	return 0;
}