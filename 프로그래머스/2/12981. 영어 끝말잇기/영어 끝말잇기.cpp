#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    unordered_map<string, bool> um;
    um.insert({words[0], true});
    
    for (int i = 1; i < words.size(); i++) {
        char prevLast = words[i - 1][words[i - 1].length() - 1];
        string cur = words[i];
    
        bool startWithPrevLast = cur[0] == prevLast;
        bool isUsedWord = um.find(cur) != um.end();
        
        if (!startWithPrevLast || isUsedWord) {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            return answer;
        }
        um.insert({cur, true});
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}
