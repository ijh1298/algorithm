#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct Move {
    int x;
    int y;
    int depth;
};

queue<Move> q;
bool visit[101][101];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int solution(vector<vector<int>> maps) {
    int answer = 1e9;
    
    // BFS
    q.push({0, 0, 1});
    visit[0][0] = true;
    while (!q.empty()) {
        auto [x, y, depth] = q.front();
        q.pop();
        
        if (x == maps.size() - 1 && y == maps[0].size() - 1) {
            answer = min(answer, depth);
        }
        
        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            
            if (nextX < 0 || nextX >= maps.size() || nextY < 0 || nextY >= maps[0].size()) continue;
            if (visit[nextX][nextY] || maps[nextX][nextY] == 0) continue;
            
            visit[nextX][nextY] = true;
            Move nextMove{nextX, nextY, depth + 1};
            q.push(nextMove);
        }
    }
    
    if (answer == 1e9) return -1;
    return answer;
}
