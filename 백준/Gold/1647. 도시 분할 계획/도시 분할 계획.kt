import java.util.PriorityQueue

const val MAX = 100001
val visit = BooleanArray(MAX) { false }
val cost = mutableListOf<Int>()
val graph = List<MutableList<Pair<Int, Int>>>(MAX) { mutableListOf() }
val pq = PriorityQueue<Pair<Int, Int>>(compareBy { it.first }) // Pair(유지비, 다음 경로)

fun getMST() {
    while (pq.isNotEmpty()) {
        val next = pq.poll()

        if (!visit[next.second]) {
            visit[next.second] = true
            cost += next.first

            for (e in graph[next.second]) {
                if (!visit[e.second])
                    pq.add(e)
            }
        }
    }
}

fun main() {
    val br = System.`in`.bufferedReader()
    val (N, M) = br.readLine().split(' ').map { it.toInt() }

    // 입력 & 최소 edge 찾기
    var minU = 0
    var minV = 0
    var minW = Int.MAX_VALUE
    repeat(M) {
        val (u, v, w) = br.readLine().split(' ').map { it.toInt() }
        if (w < minW) {
            minU = u
            minV = v
            minW = w
        }
        graph[u].add(w to v)
        graph[v].add(w to u)
    }

    // MST 구하기
    cost += minW
    visit[minU] = true
    visit[minV] = true
    for (fromU in graph[minU])
        pq.add(fromU)
    for (fromV in graph[minV])
        pq.add(fromV)

    getMST()

    // MST에서 제일 큰 비용의 길 제거(마을 분리)하고 출력
    println(cost.sum() - cost.max())
}