#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
bool visited[101][101];
vector<int> graph_out[101];
vector<int> graph_in[101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph_out[u].push_back(v);
        graph_in[v].push_back(u);
    }
    
    for (int i = 1; i <= N; i++) {
        queue<int> q_out;
        queue<int> q_in;
        q_out.push(i);
        q_in.push(i);
        visited[i][i] = true;
        
        // 오른쪽으로만 단방향
        while (!q_out.empty()) {
            int cur = q_out.front();
            q_out.pop();
            
            for (int next : graph_out[cur]) {
                if (!visited[i][next]) {
                    visited[i][next] = true;
                    q_out.push(next);
                }
            }
        }
        
        // 왼쪽으로만 단방향
        while (!q_in.empty()) {
            int cur = q_in.front();
            q_in.pop();
            
            for (int next : graph_in[cur]) {
                if (!visited[i][next]) {
                    visited[i][next] = true;
                    q_in.push(next);
                }
            }
        }
    }
    
    // 방문 수 체크
    for (int i = 1; i <= N; i++) {
        int count = 0;
        for (int j = 1; j <= N; j++) {
            if (!visited[i][j]) count++;
        }
        cout << count << '\n';
    }
    
    return 0;
}
