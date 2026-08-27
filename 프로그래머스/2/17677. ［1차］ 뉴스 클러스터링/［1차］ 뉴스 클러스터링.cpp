#include <string>
#include <unordered_map>

using namespace std;

bool isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - ('A' - 'a'); 
    }
    return c;
}

int count_union(string str1, string str2) {
    int count = 0;
    // str1 파싱 문자열 등장 횟수를 unordered_map<string, int>에 기록
    unordered_map<string, int> um;
    for (int i = 0; i < str1.length() - 1; i++) {
        if (isAlpha(str1[i]) && isAlpha(str1[i + 1])) {
            string key = "";
            key += toLower(str1[i]);
            key += toLower(str1[i + 1]);
            
            // 최초 key 접근이면
            if (um.find(key) == um.end()) {
                um[key] = 1;
            } else {
                um[key] = um[key] + 1;
            }
            count++;
        }
    }
    
    // str2 파싱 문자열 순회
    for (int i = 0; i < str2.length() - 1; i++) {
        if (isAlpha(str2[i]) && isAlpha(str2[i + 1])) {
            string key = "";
            key += toLower(str2[i]);
            key += toLower(str2[i + 1]);
            
            // 최초 key 접근이거나 값이 0인 경우
            if (um.find(key) == um.end() || um[key] == 0) {
                count++;
            } else {
                um[key] = um[key] - 1;
            }
        }
    }
    return count;
}

int count_intersection(string str1, string str2) {
    int count = 0;
    // str1 파싱 문자열 등장 횟수를 unordered_map<string, int>에 기록
    unordered_map<string, int> um;
    for (int i = 0; i < str1.length() - 1; i++) {
        if (isAlpha(str1[i]) && isAlpha(str1[i + 1])) {
            string key = "";
            key += toLower(str1[i]);
            key += toLower(str1[i + 1]);
            
            // 최초 key 접근이면
            if (um.find(key) == um.end()) {
                um[key] = 1;
            } else {
                um[key] = um[key] + 1;
            }
        }
    }
    
    // str2 파싱 문자열 순회
    for (int i = 0; i < str2.length() - 1; i++) {
        if (isAlpha(str2[i]) && isAlpha(str2[i + 1])) {
            string key = "";
            key += toLower(str2[i]);
            key += toLower(str2[i + 1]);
            
            // 최초 key 접근이거나 값이 0인 경우
            if (um.find(key) == um.end() || um[key] == 0) continue;
            
            um[key] = um[key] - 1;
            count++;
        }
    }
    return count;
}

int solution(string str1, string str2) {
    int answer = 0;
    // 합집합의 크기
    int union_size = count_union(str1, str2);
    if (union_size == 0) return 65536;
    
    // 교집합의 크기
    int intersection_size = count_intersection(str1, str2);
    
    double similarlity = (double) intersection_size / (double) union_size;
    
    return (int)(similarlity * 65536);
}
