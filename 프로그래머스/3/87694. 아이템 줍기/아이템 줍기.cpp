/*
범위를 두 배로 늘리고 답을 구한 후 두 배 줄여야 풀 수 있다.
1대1 매핑으로는 점과 선을 표현할 수 없기 때문. 

예를 들어, 다음은 ㄷ 형인지 ㅁ 형인지 구분 불가능하다.
|1, 1|
|1, 1|
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x, y, depth;
};

bool matrix[102][102]; // 둘레만 남긴 matrix
bool visited[102][102];

void fillMatrix(int x1, int y1, int x2, int y2) {
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            matrix[i][j] = true;
        }
    }
}

// 둘레가 아닌 내부를 false화
void innerFalse(int x1, int y1, int x2, int y2) {
    for (int i = x1 + 1; i < x2; i++) {
        for (int j = y1 + 1; j < y2; j++) {
            matrix[i][j] = false;
        }
    }
}

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int bfs(int startX, int startY, int goalX, int goalY) {
    queue<Point> q;
    q.push({startX, startY, 0});
    visited[startX][startY] = true;
    
    while (!q.empty()) {
        auto [x, y, depth] = q.front(); q.pop();
        
        if (x == goalX && y == goalY) return depth;
        
        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            
            if (nextX < 0 || nextX > 101 || nextY < 0 || nextY > 101) continue;
            if (visited[nextX][nextY] || !matrix[nextX][nextY]) continue;
            
            visited[nextX][nextY] = true;
            q.push({nextX, nextY, depth + 1});
        }
    }
    
    return 0;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    for (auto r : rectangle) {
        fillMatrix(r[0] * 2, r[1] * 2, r[2] * 2, r[3] * 2);
    }
    for (auto r : rectangle) {
        innerFalse(r[0] * 2, r[1] * 2, r[2] * 2, r[3] * 2);
    }
    
    return bfs(characterX * 2, characterY * 2, itemX * 2, itemY * 2) / 2;
}
