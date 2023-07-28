/*
* LCS 최장 공통 부분 수열
* 참고 : https://velog.io/@emplam27/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EA%B7%B8%EB%A6%BC%EC%9C%BC%EB%A1%9C-%EC%95%8C%EC%95%84%EB%B3%B4%EB%8A%94-LCS-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Longest-Common-Substring%EC%99%80-Longest-Common-Subsequence#longest-common-subsequence-substring
* 
* 생각해내기 힘든 다이나믹 프로그래밍 문제
* 
* 문자열은 연속적일 때만 LCS가 늘어나기 때문에 2차원 테이블의 대각선 합만 올려주면 되지만
* 공통 부분 수열은 연속적이지 않을 때도 이때까지의 길이가 저장되어야 하기 때문에
* 위의 값과 왼쪽 값 중에 최대값을 이어가야 함을 유의한다. (코드 30번째 줄)
* 
*/

#include <iostream>

int map[1001][1001] = {};
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int LCS = 0;

	std::string a, b;
	std::cin >> a >> b;

	for (int i = 1; i <= a.length(); ++i) {
		for (int j = 1; j <= b.length(); ++j) {
			if (a[i - 1] == b[j - 1]) //문자열은 0번 index부터 시작하기 때문
				map[i][j] = map[i - 1][j - 1] + 1;
			else
				map[i][j] = std::max(map[i - 1][j], map[i][j - 1]);

			if (LCS < map[i][j])
				LCS = map[i][j];
		}
	}
	std::cout << LCS;
	return 0;
}