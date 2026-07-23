#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, bool> exists_num;

// const (자료형)& 방식으로 작성하면, 값을 복사하지 않고 원본 값에 접근하므로 성능 효율이 좋다.
// 즉 쓰기 없이 읽기만 할 경우 다음처럼 작성하자.
bool less_length(const string& a, const string& b) {
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
    
    return true;
}
