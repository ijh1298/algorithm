#include <vector>
#include <queue>

using namespace std;

struct Move {
    int x, y, depth;
};

int answer = -1;
bool visited[101][101];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int n, int m, vector<vector<int>>& maps) {
    queue<Move> q;
    q.push({0, 0, 1});
    visited[0][0] = true;
    
    while (!q.empty()) {
        auto [x, y, depth] = q.front();
        q.pop();
        
        // 도착 시
        if (x == n - 1 && y == m - 1) {
            answer = depth;
            return;
        }
        
        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            
            if (visited[nextX][nextY] || nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || maps[nextX][nextY] == 0)
                continue;
            
            visited[nextX][nextY] = true;
            q.push({nextX, nextY, depth + 1});
        }
    }
}

int solution(vector<vector<int>> maps) {
    bfs(maps.size(), maps[0].size(), maps);
    return answer;
}
