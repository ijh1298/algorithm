#include <string>
#include <vector>

using namespace std;

char before[31][31], after[31][31];

void init(int m, int n, vector<string> board) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            before[i][j] = after[i][j] = board[i][j];
        }
    }
}

int pop(int m, int n) {
    int cnt = 0;
    
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (before[i][j] == 'X') continue;
            
            if (before[i][j] == before[i][j + 1] 
                && before[i][j] == before[i + 1][j] 
                && before[i][j] == before[i + 1][j + 1]) {
                
                if (after[i][j] != 'X') cnt++;
                if (after[i][j + 1] != 'X') cnt++;
                if (after[i + 1][j] != 'X') cnt++;
                if (after[i + 1][j + 1] != 'X') cnt++;
                
                after[i][j] = after[i][j + 1] = after[i + 1][j] = after[i + 1][j + 1] = 'X';
            }       
        }
    }
    return cnt;
}

void update_after_to_before(int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            before[i][j] = after[i][j];
        }
    }
}

void update_before_to_after(int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            after[i][j] = before[i][j];
        }
    }
}

void dropdown(int m, int n) {
    // 가장 아래 행부터 시작
    for (int i = m - 1; i > 0; i--) {
        for (int j = 0; j < n; j++) {
            // 빈 칸일 경우 위의 값이 있을 때까지 올라간 후 swap
            if (before[i][j] == 'X') {
                int h = i - 1;
                while (h >= 0 && before[h][j] == 'X') h--;
                if (h < 0) continue;
                
                before[i][j] = before[h][j];
                before[h][j] = 'X';
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    init(m, n, board);
    
    int answer = 0;

    while (true) {
        int cnt = pop(m, n);
        if (cnt == 0) break;
        answer += cnt;
        update_after_to_before(m, n);
        dropdown(m, n);
        update_before_to_after(m, n);
    }
    
    return answer;
}
