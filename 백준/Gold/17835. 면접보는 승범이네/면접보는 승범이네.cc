// Dijkstra는 여러 시작점을 가질 수 있다!
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
long long dist[100001]; // 각 도시의 면접장까지 최단 거리 배열
vector<int> goals; // 면접장 번호
vector<pair<long long, int>> graph[100001];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

void dijkstra() {
    // 모든 면접장을 시작점으로 다익스트라 알고리즘 수행
    fill(dist + 1, dist + 1 + N, 1e11);

    // 모든 면접장을 큐에 삽입하고 거리 0으로 설정
    for (auto goal : goals) {
        dist[goal] = 0;
        pq.emplace(0, goal);
    }

    while (!pq.empty()) {
        auto [curW, curV] = pq.top();
        pq.pop();

        if (dist[curV] != curW) continue;

        for (auto e : graph[curV]) {
            auto [nextW, nextV] = e;
            if (dist[nextV] > dist[curV] + nextW) {
                dist[nextV] = dist[curV] + nextW;
                pq.emplace(dist[nextV], nextV);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL);
    // 입력
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[v].emplace_back(w, u); // 도로가 u -> v이므로, 반대로 저장해서 면접장 기준으로 다익스트라 수행
    }

    for (int i = 0; i < K; i++) {
        int goal;
        cin >> goal;
        goals.emplace_back(goal);
    }

    // 다익스트라 알고리즘 수행 (모든 면접장에서 출발)
    dijkstra();

    // 최소 거리 중 최대값 찾기
    long long ans = 0;
    int idx = 1;
    for (int i = 1; i <= N; i++) {
        if (dist[i] != 1e11 && dist[i] > ans) {
            ans = dist[i];
            idx = i;
        }
    }

    cout << idx << '\n' << ans;
    return 0;
}
