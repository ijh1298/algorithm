class Solution {
    fun solution(elements: IntArray): Int {
        // 누적합 생성
        val dp = mutableListOf<Int>(0)
        repeat(2) { elements.forEach { dp += it } }
        for (i in 1 until dp.size) {
            dp[i] += dp[i - 1]
        }
    
        val answer = mutableSetOf<Int>()
        // 길이가 1, 2, 3, ..인 연속 부분 수열의 가능한 합들 구하기
        for (i in 1..elements.size) {
            // 시작 idx
            for (j in 0 until elements.size) {
                answer += (dp[j + i] - dp [j])
            }
        }
        return answer.size
    }
}
