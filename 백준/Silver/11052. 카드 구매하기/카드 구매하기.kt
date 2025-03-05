fun main() {
    val br = System.`in`.bufferedReader()

    val N = br.readLine().toInt()
    val packs = br.readLine().split(' ').map { it.toInt() }

    val dp = IntArray(N + 1) { _ -> 0 }

    for ((index, value) in packs.withIndex()) {
        for (i in index + 1..N) {
            dp[i] = maxOf(dp[i], dp[i - (index + 1)] + value)
        }
    }
    println(dp.max())
}