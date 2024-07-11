#include <iostream>
#include <vector>
using namespace std;

int matrix[10][10] = {};
bool visit[10][10] = {};
int curNum = 1;

// dir 방향 0-3 (우, 하, 좌, 상)
void dfs(int size, int row, int col, int dir) {
    if (size == 1) {
        matrix[row][col] = curNum;
        return;
    }
    matrix[row][col] = curNum++;

    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };

    int nextRow = row + dx[dir];
    int nextCol = col + dy[dir];

    // 다음 갈 곳이 사이즈를 넘어가거나, 방문한 곳이라면 방향 변경
    if (nextRow >= size || nextCol >= size || nextRow < 0 || nextCol < 0 || visit[nextRow][nextCol]) {
        dir = (dir + 1) % 4;
        nextRow = row + dx[dir];
        nextCol = col + dy[dir];
    }
    // 방향을 바꿨는데도 갈 수 없으면 종료
    if (visit[nextRow][nextCol]) {
        return;
    }
    visit[nextRow][nextCol] = true;
    dfs(size, nextRow, nextCol, dir);
}

void display(int tc, int size) {
    cout << "#" << tc << "\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void init(int size) {
    curNum = 1;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            matrix[i][j] = 0;
            visit[i][j] = false;
        }
}

int main(int argc, char** argv) {
    int test_case;
    int T;

    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        int size;
        cin >> size;
        visit[0][0] = true;
        dfs(size, 0, 0, 0);
        display(test_case, size);
        init(size);
    }

    return 0;
}