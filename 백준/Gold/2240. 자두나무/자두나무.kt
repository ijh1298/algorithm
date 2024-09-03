import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val (t, w) = br.readLine().split(' ').map { it.toInt() }

    val list = mutableListOf<Int>()
    repeat(t) {
        list += br.readLine().toInt()
    }

    val dp = Array(t) { IntArray(w + 1) { _ -> 0 } }

    if (list.first() == 1)
        dp[0][0] = 1
    else
        dp[0][1] = 1

    for (i in 1 until t) {
        dp[i][0] = dp[i - 1][0]
        if (list[i] == 1) dp[i][0]++
    }

    // i : 현재 위치, j : 이동 횟수
    for (i in 1 until t) {
        for (j in 1..w) {
            // j번 이동했을 때, 현재 위치에 자두가 있는지 판단
            val zadu = if (list[i] - 1 == j % 2) 1 else 0

            if (j > i + 1 || j > 30) {
                break
            }
            else if (j == i + 1) {
                dp[i][j] = dp[i - 1][j - 1] + zadu
            }
            else {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + zadu
            }
        }
    }

    var max = 0
    dp[t - 1].forEach {
        if (max < it) max = it
    }
    println(max)
}