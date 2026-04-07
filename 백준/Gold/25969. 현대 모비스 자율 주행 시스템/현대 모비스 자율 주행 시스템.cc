#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 200

using namespace std;

struct Move {
    int row;
    int col;
    int depth;
    int k;
    bool visitInter;
};

bool visited[MAX + 1][MAX + 1][31][2]; // [가로][세로][K 사용 수][중간 지점 거쳤는지 여부]
int N, M, K;
int answer = 1e9;
int matrix[MAX + 1][MAX + 1];
vector<pair<int, int>> moves;
vector<Move> inters;

void input();
void bfs(Move firstMove);

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    input();

    bfs({0, 0, 0, K, false});
    answer == 1e9 ? cout << "-1" : cout << answer;

    return 0;
}

void input() {
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int p;
            cin >> p;
            if (p == 1) moves.push_back({i - 2, j - 2});
        }
    }
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(Move firstMove) {
    queue<Move> q;
    q.push(firstMove);
    visited[firstMove.row][firstMove.col][firstMove.k][firstMove.visitInter] = true;

    while (!q.empty()) {
        auto curMove = q.front();
        auto [row, col, depth, k, visitInter] = curMove;
        q.pop();

        if (visitInter && row == N - 1 && col == M - 1) {
            answer = min(answer, depth);
        }

        // 중간 지점을 방문한 적 있는지 체크
        bool newVisitInter = visitInter || (matrix[row][col] == 2); 
        for (int i = 0; i < 4; i++) {
            int nextRow = row + dx[i];
            int nextCol = col + dy[i];

            if (nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= M) continue;
            if (visited[nextRow][nextCol][k][newVisitInter] || matrix[nextRow][nextCol] == 1) continue;
            visited[nextRow][nextCol][k][newVisitInter] = true;

            q.push({nextRow, nextCol, depth + 1, k, newVisitInter});
        }

        if (k < 1) continue;
        // 특수 패턴 사용 : k - 1
        for (auto m : moves) {
            int nextRow = row + m.first;
            int nextCol = col + m.second;

            if (nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= M) continue;
            if (visited[nextRow][nextCol][k - 1][newVisitInter] || matrix[nextRow][nextCol] == 1) continue;
            visited[nextRow][nextCol][k - 1][newVisitInter] = true;

            q.push({nextRow, nextCol, depth + 1, k - 1, newVisitInter});
        }
    }
}
