#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str_numbers;
    
    for (auto n : numbers) str_numbers.push_back(to_string(n));
    
    sort(str_numbers.begin(), str_numbers.end(), compare);
    
    for (auto sn : str_numbers) answer += sn;
    
    bool isZero = true;
    for (auto c : answer) {
        if (c != '0') isZero = false;
    }
    
    if (isZero) answer = "0";
    
    return answer;
}
