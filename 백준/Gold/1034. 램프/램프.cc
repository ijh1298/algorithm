#include <iostream>
#include <queue>

using namespace std;

int N, M, k;
bool matrix[50][50];
int sameLine[50]; // n번 라인과 완전히 같은 라인의 개수
int turnOff[50]; // n번 라인의 꺼진 램프 수
priority_queue<pair<int, int>> pq;

bool isValid(int k, int turnOffs);

int main() {
    ios::sync_with_stdio(); cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            if (c == '1') matrix[i][j] = true;
        }
    }
    cin >> k;
    
    // 0. n번 라인의 꺼진 램프 수 확인
    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int j = 0; j < M; j++) {
            if (!matrix[i][j]) count++;
        }
        turnOff[i] = count;
    }
    
    // 1. 완전히 같은 라인(행)이 있는지 판단
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            bool same = true;
            for (int h = 0; h < M; h++) {
                if (matrix[i][h] != matrix[j][h]) {
                    same = false;
                    break;
                }
            }
            
            if (same) sameLine[i]++;
        }
    }
    
    // 2. 같은 행은 많고 꺼진 램프가 적은 순위로 확인
    for (int i = 0; i < N; i++) {
        pq.push({sameLine[i], -turnOff[i]});
    }
    
    while (!pq.empty()) {
        // 유효성 검사
        int sameLines = pq.top().first;
        int turnOffs = -pq.top().second;
        pq.pop();
        
        if (isValid(k, turnOffs)) {
            cout << sameLines << '\n';
            return 0;
        }
    }
    cout << "0\n";
    return 0;
}

bool isValid(int k, int turnOffs) {
    if (k < turnOffs) return false;
    // 더 누를 수 있을 경우 같은 것을 두 번 눌러 무효화 시킬 수 있어야함
    return (turnOffs - k) % 2 == 0;
}
