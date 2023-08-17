// Minimum Spanning Tree(MST) 구하는 알고리즘 중 Kruskal Algorithm 사용함
// 참고 : https://blog.naver.com/ndb796/221230994142

#include <iostream>
#include <vector>
#include <algorithm>

// 부모 노드를 가져 오는 함수
int getParent(int set[], int x) {
	if (set[x] == x)
		return x;
	return set[x] = getParent(set, set[x]);
}

// 부모 노드를 병합하는 함수
void unionParent(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	
	// 더 숫자가 작은 부모로 병합
	if (a < b)
		set[b] = a;
	else
		set[a] = b;
}

// 같은 부모를 가지는지 확인
int find(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);

	return a == b ? 1 : 0;
}

class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator <(Edge& edge) {
		return this->distance < edge.distance;
	}
};

int set[10001];

int main() {
	int V, E;
	std::cin >> V >> E;

	std::vector<Edge> t;

	for (int i = 0; i < E; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;
		t.push_back(Edge(u, v, w));
	}

	// 가중치 기준으로 오름차순 정렬
	std::sort(t.begin(), t.end());

	// 부모 초기화
	for (int i = 1; i <= V; ++i)
		set[i] = i;

	int sum = 0;
	for (int i = 0; i < t.size(); ++i) {
		// *동일한 부모를 가리키지 않는 경우, 즉 사이클이 발생하지 않을 때만 선택하기*
		if (!find(set, t[i].node[0], t[i].node[1])) {
			sum += t[i].distance;
			unionParent(set, t[i].node[0], t[i].node[1]);
		}
	}

	std::cout << sum;

	return 0;
}