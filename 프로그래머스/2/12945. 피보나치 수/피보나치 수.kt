class Solution {
    val div = 1234567
    val dp = IntArray(100_001) { 0 }
    
    fun solution(n: Int): Int {
        dp[1] = 1
        for (i in 2..100_000) {
            dp[i] = (dp[i - 1] % div + dp[i - 2] % div) % div
        }
        return dp[n]
    }
}
