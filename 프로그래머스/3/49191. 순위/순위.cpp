#include <vector>

using namespace std;

bool visit[101];
vector<int> win[101], lose[101]; // win: A -> B, lose: A <- B

int dfs_win_order(int from) {
    int cnt = 0;
    for (auto next : win[from]) {
        if (visit[next]) continue;
        visit[next] = true;
        cnt++;
        cnt += dfs_win_order(next);
    }
    return cnt;
}

int dfs_lose_order(int from) {
    int cnt = 0;
    for (auto next : lose[from]) {
        if (visit[next]) continue;
        visit[next] = true;
        cnt++;
        cnt += dfs_lose_order(next);
    }
    return cnt;
}

void init_visit() {
    fill(visit, visit + 101, false);
}

int solution(int n, vector<vector<int>> results) {
    // init
    int lastNum = 1;
    for (auto r : results) {
        int u = r[0];
        int v = r[1];
        
        if (u > lastNum) lastNum = u;
        if (v > lastNum) lastNum = v;
        
        win[u].push_back(v);
        lose[v].push_back(u);
    }
    
    int answer = 0;
    for (int i = 1; i <= lastNum; i++) {
        int winners = dfs_win_order(i);
        int losers = dfs_lose_order(i);
        
        // 순위 확정 (이기는 사람 수 + 지는 사람 수 == n - 1)
        if (winners + losers == n - 1) answer++;
        init_visit();
    }
    
    return answer;
}
