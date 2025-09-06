fun main() {
    val br = System.`in`.bufferedReader()

    val (c, h) = br.readLine().split(' ').map { it.toInt() }
    val hotels: List<Pair<Int, Int>> = List(h) {
        val (cost, value) = br.readLine().split(' ').map { it.toInt() }
        cost to value
    }.sortedBy { it.first }

    val dp = IntArray(100001) { 0 }

    for (hotel in hotels) {
        val (cost, value) = hotel
        for (i in cost..100000) {
            dp[i] = maxOf(dp[i], dp[i - cost] + value)
        }
    }

    for (i in dp.indices) {
        if (dp[i] >= c) {
            println(i)
            return
        }
    }
}