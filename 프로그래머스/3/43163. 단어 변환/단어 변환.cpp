#include <string>
#include <vector>

using namespace std;

int answer = 1e9;
bool visited[51];
vector<string> word_list;

int diff(string str1, string str2) {
    int diff = 0;
    for (int i = 0; i < str1.length(); i++) {
        if (str1[i] != str2[i]) ++diff;
    }
    return diff;
}

void dfs(string cur, string target, int depth) {
    if (diff(cur, target) == 0) {
        if (answer > depth - 1) answer = depth - 1;
    }
    
    for (int i = 0; i < word_list.size(); i++) {
        if (visited[i]) continue;
        
        if (diff(cur, word_list[i]) == 1) {            
            visited[i] = true;
            dfs(word_list[i], target, depth + 1);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    word_list = words;
    
    for (int i = 0; i < words.size(); i++) {
        visited[i] = true;
        dfs(begin, target, 1);
        visited[i] = false;
    }
    
    return answer == 1e9 ? 0 : answer;
}
