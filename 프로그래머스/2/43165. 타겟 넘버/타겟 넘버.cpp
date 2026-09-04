#include <vector>

using namespace std;

int answer = 0;

void backtrack(int target, int sum, int idx, vector<int>& numbers) {
    if (idx == numbers.size()) {
        if (sum == target) answer++;
        return;
    }
    
    backtrack(target, sum + numbers[idx], idx + 1, numbers);
    backtrack(target, sum - numbers[idx], idx + 1, numbers);
}

int solution(vector<int> numbers, int target) {
    backtrack(target, 0, 0, numbers);
    return answer;
}
