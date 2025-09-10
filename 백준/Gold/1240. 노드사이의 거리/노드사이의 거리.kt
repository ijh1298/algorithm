val br = System.`in`.bufferedReader()
val bw = System.`out`.bufferedWriter()

val trees: Array<MutableList<Pair<Int, Int>>> = Array(10001) { mutableListOf() }
val visit = BooleanArray(10001) { false }
var isDone = false

fun dfs(next: Int, goal: Int, dist: Int) {
    for (t in trees[next]) {
        if (isDone) return

        val (v, w) = t
        if (goal == v) {
            isDone = true
            bw.write("${dist + w}\n") // ← 수정: dist + w
            return
        }

        if (!visit[v]) {
            visit[v] = true
            dfs(v, goal, dist + w)
            visit[v] = false
        }
    }
}

fun main() {
    val (N, M) = br.readLine().split(' ').map { it.toInt() }

    repeat(N - 1) {
        val (u, v, w) = br.readLine().split(' ').map { it.toInt() }
        trees[u] += v to w
        trees[v] += u to w
    }

    repeat(M) {
        val (u, v) = br.readLine().split(' ').map { it.toInt() }
        visit[u] = true
        dfs(u, v, 0)

        visit.fill(false)
        isDone = false
    }

    bw.flush()
}
