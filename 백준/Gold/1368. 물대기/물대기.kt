import java.util.PriorityQueue

fun main() {
    val br = System.`in`.bufferedReader()
    val N = br.readLine().toInt()
    val cost = mutableListOf<Int>()
    repeat(N) { cost += br.readLine().toInt() }

    val graph = List(N) { mutableListOf<Int>() }
    for (i in 0 until N) {
        graph[i] += br.readLine().split(' ').map { it.toInt() }
    }

    val visit = BooleanArray(N) { _ -> false }
    val pq = PriorityQueue<Triple<Int, Int, Int>>(compareBy<Triple<Int, Int, Int>> { it.first })

    // 가장 낮은 비용 가진 우물을 첫 정점으로 선택
    var min = Int.MAX_VALUE
    var minIndex = 0
    cost.forEachIndexed { index, i ->
        if (i < min) {
            min = i
            minIndex = index
        }
    }
    var ans = 0
    pq.add(Triple(min, minIndex, minIndex))

    // MST 구현
    while (pq.isNotEmpty()) {
        val cur = pq.poll()
        // 방문한 지점 skip
        if (visit[cur.third])
            continue
        visit[cur.third] = true
        ans += cur.first

        // 모두 방문했다면 break
        var isCompleted = true
        for (v in visit) {
            if (v == false) {
                isCompleted = false
                break
            }
        }
        if (isCompleted) break

        graph[cur.third].forEachIndexed { index, i ->
            if (!visit[index]) {
                if (cost[index] < graph[cur.third][index]) // 논 건축 비용이 더 싸면
                    pq.add(Triple(cost[index], index, index))
                else // 간선 비용이 더 싸면
                    pq.add(Triple(graph[cur.third][index], cur.third, index))
            }
        }
    }
    println(ans)
}