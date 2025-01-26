import java.util.PriorityQueue
import kotlin.math.pow
import kotlin.math.sqrt

data class Path(
    val start: Int,
    val end: Int,
    val dist: Double
)

val br = System.`in`.bufferedReader()
var n = 0
lateinit var stars: List<Pair<Double, Double>>
val pq = PriorityQueue<Path>(compareBy { it.dist })
val visit = BooleanArray(100) { _ -> false }

fun input() {
    n = br.readLine().toInt()
    stars = List(n) {
        val (x, y) = br.readLine().split(' ').map { it.toDouble() }
        x to y
    }
}

fun addPathsToPQ(start: Int) {
    for (i in 0..<n) {
        if (visit[i])
            continue
        val dist = sqrt((stars[start].first - stars[i].first).pow(2) + (stars[start].second - stars[i].second).pow(2))
        pq.add(Path(start, i, dist))
    }
}

fun isAllVisited(): Boolean {
    for (i in 0..<n) {
        if (!visit[i])
            return false
    }
    return true
}

fun solve(): Double {
    var distSum = 0.0
    visit[0] = true
    var next = 0

    do {
        addPathsToPQ(next)
        var nearestStar = pq.poll()
        while (visit[nearestStar.end]) {
            nearestStar = pq.poll()
        }
        distSum += nearestStar.dist
        next = nearestStar.end
        visit[next] = true
    } while (pq.isNotEmpty() && !isAllVisited())
    return distSum
}

fun main() {
    input()
    val ans = solve()
    println(String.format("%.2f", ans))
}