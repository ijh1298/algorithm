fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    val (N, M) = br.readLine().split(' ').map { it.toInt() }

    val digraph = List<MutableList<Int>>(N + 1) { mutableListOf() }
    val indegree = MutableList<Int>(N + 1) { _ -> 0 }
    repeat(M) {
        val order = br.readLine().split(' ').map { it.toInt() }

        for (i in 2 until order.size) {
            val u = order[i - 1]
            val v = order[i]
            indegree[v]++
            digraph[u] += v
        }
    }

    // 위상 정렬 구현
    val queue = mutableListOf<Int>()
    for (i in 1..N) {
        if (indegree[i] == 0) {
            queue.add(i)
        }
    }

    val order = mutableListOf<Int>()
    while (queue.isNotEmpty()) {
        val cur = queue.removeFirst()
        order += cur

        digraph[cur].forEach { next ->
            if (--indegree[next] == 0) {
                queue.add(next)
            }
        }
    }

    // 사이클이 존재하면 0 출력
    for (i in 1..N) {
        if (indegree[i] != 0) {
            println(0)
            return
        }
    }
    order.forEach { bw.write("$it\n") }
    bw.flush()
    bw.close()
}