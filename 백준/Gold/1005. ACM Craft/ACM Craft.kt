fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    val T = br.readLine().toInt()

    repeat(T) {
        val (N, K) = br.readLine().split(' ').map { it.toInt() }
        val digraph = List<MutableList<Int>>(N + 1) { mutableListOf() }
        val inDegree = IntArray(N + 1) { _ -> 0 }
        val buildTime = listOf(0) + br.readLine().split(' ').map { it.toInt() }
        val dp = buildTime.toMutableList()

        // 위상 정렬 구현
        repeat(K) {
            val (u, v) = br.readLine().split(' ').map { it.toInt() }
            inDegree[v]++
            digraph[u] += v
        }

        val queue = mutableListOf<Int>()
        for (i in 1..N) {
            if (inDegree[i] == 0)
                queue.add(i)
        }

        while (queue.isNotEmpty()) {
            val cur = queue.removeFirst()
            digraph[cur].forEach { next ->
                dp[next] = maxOf(dp[next], dp[cur] + buildTime[next])
                if (--inDegree[next] == 0)
                    queue.add(next)
            }
        }
        val W = br.readLine().toInt()
        bw.write("${dp[W]}\n")
    }
    bw.flush()
    bw.close()
}