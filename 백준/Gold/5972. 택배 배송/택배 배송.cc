#include <iostream>
#include <vector>
#include <queue>

#define MAX 50'000

using namespace std;

bool visited[MAX + 1];
int N, M;
int dist[MAX + 1];
vector<pair<int, int>> graph[MAX + 1]; // pair<거리, 다음 노드>

void input();
void initDist();
void dijkstra();

int main() {    
    ios::sync_with_stdio(0); cin.tie(0);

    input();
    initDist();
    dijkstra();
    cout << dist[N];

    return 0;
}

void input() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({-w, v});
        graph[v].push_back({-w, u});
    }
}

void initDist() {
    fill(dist, dist + N + 1, 1e9);
}

void dijkstra() {
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while (!pq.empty()) {
        int curV = pq.top().second;
        pq.pop();

        if (visited[curV]) continue;
        visited[curV] = true;

        for (auto next : graph[curV]) {
            int nextV = next.second;
            int nextW = -next.first;

            if (dist[nextV] > dist[curV] + nextW) {
                dist[nextV] = dist[curV] + nextW;
                pq.push({-dist[nextV], nextV});
            }
        }
    }
}
