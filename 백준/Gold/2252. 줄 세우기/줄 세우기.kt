fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    val (N, M) = br.readLine().split(' ').map { it.toInt() }

    val digraph = List<MutableList<Int>>(32001) { mutableListOf() }
    val indegree = IntArray(32001) { _ -> 0 }

    repeat(M) {
        val (u, v) = br.readLine().split(' ').map { it.toInt() }
        digraph[u] += v
        indegree[v]++
    }

    // 위상 정렬 구현
    val ans = mutableListOf<Int>()
    val queue = mutableListOf<Int>()
    for (i in 1..N) {
        if (indegree[i] == 0) // indegree가 0인 정점 q에 insert
            queue.add(i)
    }

    while (queue.isNotEmpty()) {
        val cur = queue.removeFirst()
        ans += cur

        // 연결된 정점들 방문
        digraph[cur].forEach {
            if (--indegree[it] == 0) { // indegree를 하나 줄이고, 0이 되면 q에 insert
                queue.add(it)
            }
        }
    }

    ans.forEach {
        bw.write("$it ")
    }
    bw.flush()
    bw.close()
}