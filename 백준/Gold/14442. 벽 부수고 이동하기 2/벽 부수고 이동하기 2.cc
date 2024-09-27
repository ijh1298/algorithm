#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

#define MAX 1001
int N, M, K;
int map[MAX][MAX];
bool visit[11][MAX][MAX]; // [i번 break 했을 때][r][c] 방문 여부 기록

void bfs() {
    queue<tuple<int, int, int, int>> q; // {현재 행, 현재 열, 벽을 부순 횟수, 이동 횟수}
    visit[0][0][0] = true; 
    q.push({ 0, 0, 0, 1 }); // {행, 열, 부순 횟수, 이동 거리}

    // 상, 우, 하, 좌
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    while (!q.empty()) {
        auto [row, col, breakCount, depth] = q.front();
        q.pop();

        // 목표 지점 도달 시, 이동 거리를 출력하고 종료
        if (row == N - 1 && col == M - 1) {
            cout << depth << '\n';
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nextR = row + dx[i];
            int nextC = col + dy[i];

            if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= M)
                continue;

            if (map[nextR][nextC] == 0 && !visit[breakCount][nextR][nextC]) {
                visit[breakCount][nextR][nextC] = true;
                q.push({ nextR, nextC, breakCount, depth + 1 });
            }
            if (map[nextR][nextC] == 1 && breakCount < K && !visit[breakCount + 1][nextR][nextC]) {
                visit[breakCount + 1][nextR][nextC] = true;
                q.push({ nextR, nextC, breakCount + 1, depth + 1 });
            }
        }
    }

    // 목표 지점에 도달할 수 없는 경우
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            map[i][j] = s[j] - '0';
        }
    }

    bfs();

    return 0;
}
