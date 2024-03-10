#include <iostream>

using namespace std;

int arr[1000001];

int find(int target) {
	if (arr[target] != target)
		arr[target] = find(arr[target]);			
		// 추후 검색에서 시간복잡도 향상을 위해
		// 재귀 함수를 빠져 나오는 과정에서 대표 노드를 하나로 통일
	return arr[target];
}

void make_union(int x, int y) {
	x = find(x);
	y = find(y);
    // 더 작은 값을 대표 노드로 설정
	if (x > y)
		arr[x] = y;
	else
		arr[y] = x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i < n + 1; i++)
		arr[i] = i;	// 초기화

	int t, a, b;
	for (int i = 0; i < m; i++) {
		cin >> t >> a >> b;
		if (t == 0)
			make_union(a, b);
		else {
			if (find(a) == find(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}