#include <vector>

using namespace std;

bool water[101][101];
int dp[101][101];
long long mod = 1'000'000'007;

int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };

int dfs(int x, int y, int m, int n) {
    // 도착지일 때
    if (x == m - 1 && y == n - 1) return 1;
    // 방문한 적 있으면
    if (dp[x][y] != -1) return dp[x][y];
    
    dp[x][y] = 0; // 방문 처리
    
    for (int i = 0; i < 2; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (nextX >= m || nextY >= n || water[nextX][nextY]) continue;
        dp[x][y] = (dp[x][y] + dfs(nextX, nextY, m, n)) % mod;
    }
    return dp[x][y];
}

int solution(int m, int n, vector<vector<int>> puddles) {
    // !visit 설정
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }
    
    // 물웅덩이 설정
    for (auto p : puddles) {
        int x = p[0];
        int y = p[1];
        water[x - 1][y - 1] = true; 
    }
        
    return dfs(0, 0, m, n);
}
