fun main() {
    val N = readln().toInt()

    // 길이가 1일 때 존재하는 계단수의 일의 자리 수들
    val dp = longArrayOf(0, 1, 1, 1, 1, 1, 1, 1, 1, 1)
    val nextDp = LongArray(10) { 0 }
    val MOD = 1_000_000_000L

    for (i in 2..N) {
        for (j in 0..9) {
            if (j == 0) {
                nextDp[1] = (nextDp[1] + dp[0]) % MOD
            } else if (j == 9) {
                nextDp[8] = (nextDp[8] + dp[9]) % MOD
            } else {
                nextDp[j + 1] = (nextDp[j + 1] + dp[j]) % MOD
                nextDp[j - 1] = (nextDp[j - 1] + dp[j]) % MOD
            }
        }

        for (j in 0..9) {
            dp[j] = nextDp[j]
        }
        // nextDp 초기화
        nextDp.forEachIndexed { idx, _ ->
            nextDp[idx] = 0L
        }
    }
    var ans = 0L
    dp.forEach {
        ans = (ans + it) % MOD
    }
    println(ans)
}
