val br = System.`in`.bufferedReader()
val bw = System.`out`.bufferedWriter()

lateinit var graph: Array<MutableList<Int>>
lateinit var visited: BooleanArray
lateinit var order: IntArray
var cnt = 0

fun bfs(R: Int) {
    val queue = ArrayDeque<Int>()
    visited[R] = true
    queue.add(R)

    while (queue.isNotEmpty()) {
        val next = queue.removeFirst()
        order[next] = ++cnt

        for (v in graph[next]) {
            if (!visited[v]) {
                visited[v] = true
                queue.add(v)
            }
        }
    }
}

fun main() {
    val (N, M, R) = br.readLine().split(' ').map { it.toInt() }

    graph = Array(N + 1) { mutableListOf() }
    visited = BooleanArray(N + 1) { false }
    order = IntArray(N + 1) { 0 }

    repeat(M) {
        val (u, v) = br.readLine().split(' ').map { it.toInt() }
        graph[u] += v
        graph[v] += u
    }
    graph.forEach { it.sort() }

    bfs(R)
    for (i in 1..N) {
        bw.write("${order[i]}\n")
    }
    bw.flush()
}
