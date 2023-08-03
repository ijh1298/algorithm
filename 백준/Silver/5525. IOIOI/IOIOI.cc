#include <iostream>
#include <string>
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int N, M;
    std::string s;
    std::cin >> N >> M >> s;

    int sum = 0;
    for (int i = 1; i < s.size(); ++i) {
        int cnt = 0;
        if (s[i - 1] == 'I') {
            while (s[i] == 'O' && s[i + 1] == 'I') {
                i += 2;
                cnt++;
                if (cnt == N) {
                    --cnt;
                    ++sum;
                }
            }
        }
    }
    std::cout << sum;

    return 0;
}