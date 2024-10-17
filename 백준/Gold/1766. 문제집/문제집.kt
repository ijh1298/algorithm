import java.util.PriorityQueue

fun main() {
    // 입력
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    val (N, M) = br.readLine().split(' ').map { it.toInt() }

    val inDegree = MutableList(N + 1) { 0 }
    val graph = List<MutableList<Int>>(N + 1) { mutableListOf() }
    repeat(M) {
        val (u, v) = br.readLine().split(' ').map { it.toInt() }
        inDegree[v]++
        graph[u] += v
    }

    // 위상 정렬
    val q = PriorityQueue<Int>()
    for (i in 1..N)
        if (inDegree[i] == 0)
            q.add(i)

    val ans = mutableListOf<Int>()
    while (q.isNotEmpty()) {
        val cur = q.poll()
        ans += cur

        for (e in graph[cur])
            if (--inDegree[e] == 0)
                q.add(e)
    }

    // 출력
    for (a in ans)
        bw.write("$a ")
    bw.flush()
    bw.close()
}