#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    bool alphabet[26] = {};
    // 사용한 알파벳 체크
    int skillLen = skill.length();
    for (int i = 0; i < skillLen; i++)
        alphabet[skill[i] - 'A'] = true;
    
    int tLen = skill_trees.size();
    for (int t = 0; t < tLen; t++) {
        vector<char> check;
        int curLen = skill_trees[t].length();
        for (int j = 0; j < curLen; j++) {
            // 사용된 알파벳이면 push
            if (alphabet[skill_trees[t][j] - 'A'])
                check.push_back(skill_trees[t][j]);
        }

        // 투포인터로 두 string 순서가 동일한지 확인
        bool flag = true;
        int ptr = 0;
        for (int i = 0; i < check.size(); i++) {
            if (check[ptr] == skill[i]) {
                ptr++;
            }
            else {
                flag = false;
                break;
            }
        }
        if (flag) answer++;
    }
    return answer;
}