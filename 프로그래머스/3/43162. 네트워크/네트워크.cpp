#include <string>
#include <vector>

using namespace std;

bool visited[201], edges[201][201];

void dfs(int n, int u) {
    for (int v = 0; v <= n; v++) {
        if (edges[u][v] && !visited[v]) {
            visited[v] = true;
            dfs(n, v);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    // init
    for (int i = 0; i < computers.size(); i++) {
        for (int j = 0; j < computers[0].size(); j++) {
            edges[i + 1][j + 1] = computers[i][j];
        }
    }
    
    int answer = 0;
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            answer++;
            dfs(n, i);
        }
    }
    
    return answer;
}
