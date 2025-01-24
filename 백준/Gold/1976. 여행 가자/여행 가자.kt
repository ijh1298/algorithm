val br = System.`in`.bufferedReader()

var n = 0
var m = 0

val routes = MutableList(200) { listOf<Int>() }
lateinit var tripRoutes: List<Int>

val parent = MutableList(200) { i -> i }

fun input() {
    n = br.readLine().toInt()
    m = br.readLine().toInt()

    for (i in 0..<n) {
        routes[i] = br.readLine().split(' ').map { it.toInt() }
    }
    tripRoutes = br.readLine().split(' ').map { it.toInt() }
}

fun find(num: Int): Int {
    if (parent[num] != num) {
        parent[num] = find(parent[num])
    }
    return parent[num]
}


fun union(a: Int, b: Int) {
    val first = find(a)
    val second = find(b)

    parent[first] = second
}

fun unionConnectedRoutes() {
    for (i in 0..<n) {
        for (j in 0..<n) {
            if (routes[i][j] == 1) {
                union(i, j)
            }
        }
    }
}

fun solve(): String {
    val parents = tripRoutes.map { find(it - 1) }
    return if (parents.all { it == parents[0] }) "YES" else "NO"
}

fun main() {
    input()
    unionConnectedRoutes()
    println(solve())
}