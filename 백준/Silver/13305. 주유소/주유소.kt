val br = System.`in`.bufferedReader()
var N: Int = 0
lateinit var distances: List<Long>
lateinit var oilPrices: List<Long>

fun input() {
    N = br.readLine().toInt()
    distances = br.readLine().split(' ').map { it.toLong() }
    oilPrices = br.readLine().split(' ').map { it.toLong() }
}

fun solve(): Long {
    var ans = 0L
    var minOilPrice = oilPrices[0]

    for (i in 1..<N) {
        ans += minOilPrice * distances[i - 1]
        if (minOilPrice > oilPrices[i]) {
            minOilPrice = oilPrices[i]
        }
    }
    return ans
}

fun main() {
    input()
    println(solve())
}