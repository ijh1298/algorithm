#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;
    int cnt = 0;

    for (int i = 0; i < s.size(); i++) {
        std::vector<std::string> v;

        for (int j = 0; j < s.size() - i; ++j) {
            std::string tmp = s.substr(j, 1 + i);
            v.push_back(tmp);
        }

        std::sort(v.begin(), v.end());
        v.erase(std::unique(v.begin(), v.end()), v.end());
        cnt += v.size();
    }
    std::cout << cnt;
}