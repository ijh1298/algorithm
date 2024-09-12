fun main() {
    val br = System.`in`.bufferedReader()
    val N = br.readLine().toInt()
    val wines = mutableListOf<Int>()

    // dp[몇 연속 마시고 있는지][현재 위치]
    val dp = List<MutableList<Int>>(3) { MutableList<Int>(N + 1) { 0 } }

    repeat(N) {
        wines += br.readLine().toInt()
    }

    dp[1][1] = wines[0]
    for (i in 2..N) {
        dp[0][i] = maxOf(dp[0][i - 1], dp[1][i - 1], dp[2][i - 1])
        dp[1][i] = dp[0][i - 1] + wines[i - 1]
        dp[2][i] = dp[1][i - 1] + wines[i - 1]
    }

    println(maxOf(dp[0][N], dp[1][N], dp[2][N]))
}