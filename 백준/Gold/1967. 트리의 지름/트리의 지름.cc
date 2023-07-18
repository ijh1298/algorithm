#include <iostream>
#include <vector>

using namespace std;

pair<int, int> mx = { 0, 0 };
vector<pair<int, int>> t[10001];
bool visit[10001] = {};

void dfs(int start, int curW) {
	//최대 거리 갱신
	if (curW > mx.second) {
		mx.first = start;
		mx.second = curW;
	}
	
	for (int i = 0; i < t[start].size(); i++)
		if (!visit[t[start][i].first]) {
			visit[t[start][i].first] = true;
			dfs(t[start][i].first, curW + t[start][i].second);
		}
}

int main() {
	int N;
	cin >> N;

	int u, v, w;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v >> w;
		t[u].push_back({ v, w });
		t[v].push_back({ u, w });
	}

	/*
	트리의 지름 찾기
	1. 임의의 점(1)에서 가장 거리가 먼 vf 찾기
	2. vf에서 가장 거리가 먼 wf 찾기
	3. vf와 wf가 트리의 지름
	*/
	visit[1] = true;
	dfs(1, 0);

	pair<int, int> vf;
	vf.first = mx.first;
	vf.second = mx.second; //1번 끝

	//mx, visit 초기화
	mx = { 0, 0 };
	for (int i = 0; i <= N; i++)
		visit[i] = false;

	visit[vf.first] = true;
	dfs(vf.first, 0); //2번 끝
	//이제 mx는 { vf와 wf간 거리, wf 노드 번호 }를 담고 있음

	cout << mx.second;

	return 0;
}