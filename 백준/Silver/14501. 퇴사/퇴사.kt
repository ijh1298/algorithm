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
        // dp 갱신
        for (j in i + d..n) {
            dp[j] = max(dp[j], dp[i] + v)
        }
    }
    println(dp[n])
}