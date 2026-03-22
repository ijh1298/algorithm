#include <string>
using namespace std;

bool move(int x, int y, int dx, int dy);

int answer = 0;
// (0, 0) -> (0, 1) 이동 시
// [5][5][5][6], [5][6][5][5]을 true로 변경
bool visit[11][11][11][11];

int solution(string dirs) {
    int curX = 5;
    int curY = 5;
    for (int i = 0; i < dirs.length(); i++) {
        if (dirs[i] == 'U') {
            if (move(curX, curY, 1, 0)) curX++;
        } else if (dirs[i] == 'D') {
            if (move(curX, curY, -1, 0)) curX--;
        } else if (dirs[i] == 'R') {
            if (move(curX, curY, 0, 1)) curY++;
        } else {
            if (move(curX, curY, 0, -1)) curY--;
        }
    }
    return answer;
}

bool move(int x, int y, int dx, int dy) {
    int nextX = x + dx;
    int nextY = y + dy;
    
    if (nextX < 0 || nextX >= 11 || nextY < 0 || nextY >= 11) return false;
    
    if (!visit[x][y][nextX][nextY] && !visit[nextX][nextY][x][y]) {
        visit[x][y][nextX][nextY] = true;
        visit[nextX][nextY][x][y] = true;
        answer++;
    }
    return true;
}
