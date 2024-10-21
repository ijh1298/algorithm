const val MAX = 100001
val graph = List<MutableList<Int>>(MAX) { mutableListOf() }
val visit = BooleanArray(MAX)
val subtreeNodes = MutableList(MAX) { 1 }

// DFS 이용해 subtressNodes 개수 저장
fun dfs(s: Int): Int {
    for (c in graph[s]) {
        if (!visit[c]) {
            visit[c] = true
            subtreeNodes[s] += dfs(c)
        }
    }
    return subtreeNodes[s]
}

fun main() {
    val br = System.`in`.bufferedReader()
    val (N, R, Q) = br.readLine().split(' ').map { it.toInt() }

    // 입력
    repeat(N - 1) {
        val (u, v) = br.readLine().split(' ').map { it.toInt() }
        graph[u].add(v)
        graph[v].add(u)
    }
    visit[R] = true
    dfs(R)
    // 출력
    repeat(Q) {
        val r = br.readLine().toInt()
        println(subtreeNodes[r])
    }
}