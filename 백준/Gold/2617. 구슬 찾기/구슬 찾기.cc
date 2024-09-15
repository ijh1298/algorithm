#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<int> moreThan[100], lessThan[100];
bool visit_more[100];
bool visit_less[100];

void dfs_more(int i) {
    visit_more[i] = true;
    for (auto e : moreThan[i]) {
        if (!visit_more[e]) {
            dfs_more(e);
        }
    }
}

void dfs_less(int i) {
    visit_less[i] = true;
    for (auto e : lessThan[i]) {
        if (!visit_less[e]) {
            dfs_less(e);
        }
    }
}

bool dfs(int type, int i) {
    int sum = 0;

    if (type == 1) {
        dfs_more(i);
        for (int j = 1; j <= N; j++) {
            if (visit_more[j]) sum++;
        }
        fill(visit_more, visit_more + N + 1, false);
    }
    else {
        dfs_less(i);
        for (int j = 1; j <= N; j++) {
            if (visit_less[j]) sum++;
        }
        fill(visit_less, visit_less + N + 1, false);
    }

    return sum - 1 >= (N + 1) / 2; // sum - 1 : 자기 자신 visit은 제외
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int v, w;
        cin >> v >> w;
        moreThan[v].push_back(w);
        lessThan[w].push_back(v);
    }

    int ans = 0;

    for (int i = 1; i <= N; i++) {
        if (dfs(1, i) || dfs(2, i)) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}
