#include <string>
#include <vector>

#define N_MAX 200

using namespace std;

int dist[N_MAX + 1][N_MAX + 1];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    // dist 배열 초기화
    for (int i = 1; i <= n; i++) fill(dist[i] + 1, dist[i] + n + 1, 1e9);
    for (int i = 1; i <= n; i++) dist[i][i] = 0;
    
    // 도로 요금 반영
    for (auto f : fares) {
        int u = f[0], v = f[1], w = f[2];
        dist[u][v] = w;
        dist[v][u] = w;
    }
    
    // 플로이드 워셜
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    // 최소 거리 찾기
    int minA = 1e9, minB = 1e9, minIdx = 1, minResult = 1e9;
    for (int i = 1; i <= n; i++) {
        if (i == s) continue;
        if (dist[s][i] == 1e9 || dist[i][a] == 1e9 || dist[i][b] == 1e9) continue;
        
        int curResult = dist[s][i] + dist[i][a] + dist[i][b];
        
        if (curResult < minResult) {
            minResult = curResult;
        }
    }
    
    // 바로 가는 게 더 빠른 경우 확인
    if (minResult > dist[s][a] + dist[s][b]) {
        minResult = dist[s][a] + dist[s][b];
    }

    return minResult;
}
