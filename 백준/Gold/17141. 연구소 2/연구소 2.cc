// backtracking으로 조합을 생성하면 생성 시간만 해도 O(10^10)가 되기 때문에,
// next_permutation을 사용하여 조합을 생성한다.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, ans = 1e9;
int matrix[51][51];
int firstMatrix[51][51];
vector<pair<int, int>> virusCandidates, usingVirus;
bool visit[51][51];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void input();
void generate_virus_combinations();
void checkIfDone();
void bfs();
void init();
void output();

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 2) { // 2를 입력받으면, virus 후보에 넣고 0으로 입력
                virusCandidates.emplace_back(i, j);
                matrix[i][j] = 0;
            }
            firstMatrix[i][j] = matrix[i][j];
        }
}

void generate_virus_combinations() {
    int n = virusCandidates.size();
    vector<int> indices(n, 0);

    // 뒤에서부터 M개의 요소를 1로 설정하여 초기 조합 설정
    fill(indices.end() - M, indices.end(), 1);

    do {
        usingVirus.clear();
        for (int i = 0; i < n; ++i) {
            if (indices[i] == 1) {
                usingVirus.emplace_back(virusCandidates[i]);
            }
        }
        bfs(); // 각 조합에 대해 bfs 호출
    } while (next_permutation(indices.begin(), indices.end()));
}

void checkIfDone() {
    bool isDone = true;
    int maxTime = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            maxTime = max(maxTime, matrix[i][j]);
            if (matrix[i][j] == 0) {
                isDone = false;
                break;
            }
        }

    if (!isDone)
        return;

    ans = min(ans, maxTime - 2);
}

void bfs() {
    for (auto v : virusCandidates) { // 초기화
        auto [r, c] = v;
        matrix[r][c] = 0;
    }

    queue<pair<int, int>> q;
    for (auto v : usingVirus) {
        auto [r, c] = v;
        matrix[r][c] = 2;
        visit[r][c] = true;
        q.emplace(r, c);
    }

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextR = r + dx[i];
            int nextC = c + dy[i];

            if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N || visit[nextR][nextC] || matrix[nextR][nextC] == 1)
                continue;

            visit[nextR][nextC] = true;
            matrix[nextR][nextC] = matrix[r][c] + 1; // matrix에서 2는 0초, 3는 1초, ... 의 시간이 지남을 가르킴
            q.emplace(nextR, nextC);
        }
    }
    checkIfDone();
    init();
}

void init() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            visit[i][j] = false;
            matrix[i][j] = firstMatrix[i][j];
        }
}

void output() {
    if (ans == 1e9)
        cout << -1;
    else
        cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    generate_virus_combinations();
    output();

    return 0;
}
