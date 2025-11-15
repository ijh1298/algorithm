import java.util.PriorityQueue

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    val N = br.readLine().toInt()

    repeat(N) {
        val (n, d, c) = br.readLine().split(' ').map { it.toInt() }

        // Pair<다음 번호, 거리>
        val routes = List(n + 1) { mutableListOf<Pair<Int, Int>>() }
        val visit = BooleanArray(n + 1) { false }
        val dist = IntArray(n + 1) { 1_000_000_000 }

        // 자신까지 거리는 0 초기화
        dist[c] = 0

        // u, v, w 입력 (단방향임에 유의)
        repeat(d) {
            val (u, v, w) = br.readLine().split(' ').map { it.toInt() }
            routes[v] += u to w
        }

        val pq = PriorityQueue<Pair<Int, Int>>(compareBy { it.second })

        // Dijkstra
        visit[c] = true
        routes[c].forEach {
            dist[it.first] = it.second
            pq.add(it)
        }
        
        while (pq.isNotEmpty()) {
            val (cur, d) = pq.poll()
            visit[cur] = true

            if (dist[cur] < d) continue

            routes[cur].forEach { next ->
                if (dist[next.first] > dist[cur] + next.second) {
                    dist[next.first] = dist[cur] + next.second
                    pq.add(next)
                }
            }
        }

        // output
        val counts = visit.count { it }
        var max = 0
        dist.forEach {
            if (it != 1_000_000_000) {
                max = maxOf(max, it)
            }
        }

        bw.write("$counts $max\n")
    }

    bw.flush()
}
