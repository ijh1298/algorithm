#include <iostream>
#include <string>
#include <vector>

using namespace std;

int B;
vector<string> lows, highs;

void input();
void solve();
int bitmask(string dataBit, string bitString);
long long toBits(string bitString);

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    input();
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        solve();
    }
    return 0;
}

void input() {
    cin >> B;
    
    for (int i = 0; i < B; i++) {
        string low;
        cin >> low;
        lows.push_back(low);
    }
    
    for (int i = 0; i < B; i++) {
        string high;
        cin >> high;
        highs.push_back(high);
    }
}

void solve() {
    string dataBit;
    cin >> dataBit;

    int lowCnt = 0, highCnt = 0;
    for (auto low : lows) {
        lowCnt += bitmask(dataBit, low);
    }
    for (auto high: highs) {
        highCnt += bitmask(dataBit, high);
    }
    
    if (lowCnt > highCnt) {
        cout << "HIGH " << lowCnt - highCnt << '\n';
    } else if (lowCnt < highCnt) {
        cout << "LOW " << highCnt - lowCnt << '\n';
    } else {
        cout << "GOOD\n";
    }
}

// 비트마스킹 연산으로 같은 패턴이 등장하는 개수 반환
int bitmask(string dataBit, string bitString) {
    int len = bitString.length();
    long long pattern = toBits(bitString);
    long long mask = (1LL << len) - 1;

    long long val = 0;
    int count = 0;

    for (int i = 0; i < dataBit.length(); i++) {
        val = ((val << 1) | (dataBit[i] - '0')) & mask;

        if (i >= len - 1 && val == pattern) {
            count++;
        }
    }

    return count;
}

// 문자열을 비트(길이가 최대 50이라 64비트의 long long형)로 변환
long long toBits(string bitString) {
    long long value = 0;
    for (auto c : bitString) {
        value = (value << 1) | (c - '0');
    }
    return value;
}
