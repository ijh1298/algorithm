#include <iostream>
#include <vector>
#include <queue>

#define MAX 200'000

using namespace std;

bool visited[MAX + 1]; // dijkstra 방문 배열
bool pathVisited[MAX + 1]; // 역추적 방문 배열
int N, M, A, B;
long long dist[MAX + 1];
vector<int> path[MAX + 1]; // 최단 경로에서 parent 경로
vector<pair<long long, int>> graph[MAX + 1]; // pair<거리, 다음 노드>

void input();
void dijkstra();
void init_dist();
void track();
void output();

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    input();
    init_dist();
    dijkstra();
    track();
    output();

    return 0;
}

void input() {
    cin >> N >> M >> A >> B;

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({-w, v});
        graph[v].push_back({-w, u});
    }
}

void init_dist() {
    fill(dist, dist + N + 1, 2e18);
}

void dijkstra() {
    priority_queue<pair<long long, int>> pq;
    pq.push({0, A});
    dist[A] = 0;

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
                pq.push({ -dist[nextV], nextV });
                path[nextV].clear();
                path[nextV].push_back(curV);
            } else if (dist[nextV] == dist[curV] + nextW) {
                path[nextV].push_back(curV);
            }
        }
    }
}

void track() {
    queue<int> q;

    pathVisited[B] = true;
    for (auto next : path[B]) {
        q.push(next);
        pathVisited[next] = true;
    }

    while (!q.empty()) {
        int parent = q.front();
        q.pop();

        for (auto p : path[parent]) {
            if (pathVisited[p]) continue;
            pathVisited[p] = true;
            q.push(p);
        }
    }
}

void output() {
    vector<int> answer;
    for (int i = 1; i <= N; i++) {
        if (pathVisited[i])
            answer.push_back(i);
    }
    cout << answer.size() << '\n';
    for (auto e : answer) {
        cout << e << ' ';
    }
}
