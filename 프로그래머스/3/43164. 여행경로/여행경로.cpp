#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

unordered_map<string, vector<pair<string, int>>> flights;
unordered_map<string, bool> visited;

unordered_set<string> visited_cities = { "ICN" };

bool dfs(string airport, vector<string>& routes, int tickets_size) {
    if (routes.size() == tickets_size + 1) {
        return true;
    }
    
    for (auto& next_flight : flights[airport]) {
        auto [next_airport, idx] = next_flight;
        // key string: 출발지 + 목적지 + 티켓 idx
        // visited[key] 기준 방문 체크
        string key = airport + next_airport + to_string(idx);
        if (!visited[key]) {
            visited[key] = true;
            routes.emplace_back(next_airport);
            if (dfs(next_airport, routes, tickets_size)) {
                return true;
            }
            visited[key] = false;
            routes.pop_back();
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    // input
    unordered_set<string> cities;
    for (int i = 0; i < tickets.size(); i++) {
        auto ticket = tickets[i];
        flights[ticket[0]].push_back({ticket[1], i});
        cities.insert(ticket[0]);
        cities.insert(ticket[1]);
    }
    
    // 알파벳 순 정렬
    for (auto& [key, value] : flights) {
        sort(value.begin(), value.end());
    }
    
    // DFS
    vector<string> answer = { "ICN" };
    dfs("ICN", answer, tickets.size());
    
    return answer;
}
