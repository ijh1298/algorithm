import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readLine().toInt()

    val schedule = MutableList<Pair<Int, Int>>(n + 1) { _ -> 0 to 0 }
    val dp = MutableList<Int>(n + 1) { _ -> 0 }

    for (i in 0 until n) {
        val (day, value) = br.readLine().split(' ').map { it.toInt() }
        schedule[i] = day to value
    }

    for (i in 0 until n) {
        val (d, v) = schedule[i]
        if (i > 0)
            dp[i] = max(dp[i], dp[i - 1])
        // dp 갱신
        if (i + d <= n) {
            dp[i + d] = max(dp[i + d], dp[i] + v)
        }
    }
    println(max(dp[n], dp[n - 1]))
}