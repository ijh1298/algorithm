#include <vector>
#include <queue>

using namespace std;

int dist[51];
vector<pair<int, int>> graph[51];

void dijkstra() {
    // 최소힙 우선순위큐, pair<거리, 다음 노드 번호>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[1] = 0;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        auto [curDist, curNode] = pq.top();
        pq.pop();
        
        if (curDist > dist[curNode]) continue;
        
        for (auto next : graph[curNode]) {
            int nextNode = next.second;
            int nextDist = next.first;
            
            if (dist[nextNode] > curDist + nextDist) {
                dist[nextNode] = curDist + nextDist;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    // input
    for (auto r : road) {
        int u = r[0], v = r[1], w = r[2];
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }
    
    // init dist
    for (int i = 1; i <= N; i++) dist[i] = 1e9;
    
    dijkstra();
    
    // count
    int answer = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] <= K) answer++;
    }

    return answer;
}
