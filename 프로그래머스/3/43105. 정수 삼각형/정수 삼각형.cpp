#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
        int answer = 0;
    int dp[501][501] = {};
    int size = triangle.size();
    dp[1][0] = triangle[1][0] + triangle[0][0];
    dp[1][1] = triangle[1][1] + triangle[0][0];
    for (int i = 2; i < size; i++) {
        dp[i][0] = triangle[i][0] + dp[i - 1][0];
        for (int j = 1; j < i; j++) {
            dp[i][j] = triangle[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
        dp[i][i] = triangle[i][i] + dp[i - 1][i - 1];
    }
    for (int i = 0; i < triangle[size - 1].size(); i++) {
        if (dp[size - 1][i] > answer)
            answer = dp[size - 1][i];
    }
    return answer;
}