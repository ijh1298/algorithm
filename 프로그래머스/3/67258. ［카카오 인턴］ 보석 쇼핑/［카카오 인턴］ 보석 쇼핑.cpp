#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    set<string> gem_types;
    for (auto g : gems) gem_types.insert(g);
    
    unordered_map<string, int> gem_counts;
    for (auto gt : gem_types) gem_counts[gt] = 0;
    
    int start = 0, end = 0;
    set<string> cur_gems;
    cur_gems.insert(gems[0]);
    gem_counts[gems[0]]++;
    
    vector<int> answer = { 1, (int)gems.size() };
    while (true) {
        if (cur_gems.size() == gem_types.size()) {
            // 더 짧은 구간으로 갱신
            if (end - start < answer[1] - answer[0]) {
                answer[0] = start + 1;
                answer[1] = end + 1;
            }
            
            gem_counts[gems[start]]--;
            if (gem_counts[gems[start]] == 0) cur_gems.erase(gems[start]);
            start++;
        } else {
            end++;
            if (end >= (int)gems.size()) break;
            gem_counts[gems[end]]++;
            cur_gems.insert(gems[end]);
        }
    }
    
    return answer;
}
