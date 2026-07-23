#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, bool> exists_num;

bool less_length(string a, string b) {
    return a.length() < b.length();
}

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end(), less_length);
    exists_num[phone_book[0]] = true;
    
    for (int i = 1; i < phone_book.size(); i++) {
        string cur = phone_book[i];
        
        string phone = "";
        for (auto c : cur) {
            phone += c;
            if (exists_num[phone] == true) return false;
        }
        exists_num[phone_book[i]] = true;
    }
    
    // 처음 등록한 0번 인덱스 번호도 검사
    for (auto c : phone_book[0]) {
        string phone = "";
        phone += c;
        if (exists_num[phone] == true) return false;
    }
    
    return true;
}
