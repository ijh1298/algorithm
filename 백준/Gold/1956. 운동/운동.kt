val br = System.`in`.bufferedReader()

var v = 0
var e = 0
lateinit var minDist: List<MutableList<Int>>

fun initializeMinDist() {
    minDist = List(v + 1) { MutableList(v + 1) { _ -> 1e9.toInt() } }
}

fun input() {
    val input = br.readLine().split(' ').map { it.toInt() }
    v = input[0]
    e = input[1]
    initializeMinDist()

    repeat(e) {
        val (u, v, w) = br.readLine().split(' ').map { it.toInt() }
        minDist[u][v] = w
    }
}

fun setShortestPath() {
    for (t in 1..v) {
        for (i in 1..v) {
            for (j in 1..v) {
                if (minDist[i][t] + minDist[t][j] < minDist[i][j]) {
                    minDist[i][j] = minDist[i][t] + minDist[t][j]
                }
            }
        }
    }
}

fun getShortestCycleDist(): Int {
    val minCycleDist = List(v) { i -> minDist[i + 1][i + 1] }.min()

    if (minCycleDist == 1e9.toInt())
        return -1
    return minCycleDist
}

fun main() {
    input()
    setShortestPath()
    println(getShortestCycleDist())
}