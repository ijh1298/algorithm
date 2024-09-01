import java.util.PriorityQueue

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readLine().toInt()
    val list = mutableListOf<Pair<Int, Int>>()

    repeat(n) {
        val (a, b) = br.readLine().split(' ').map { it.toInt() }
        list.add(a to b)
    }

    // 시작 시간이 빠른 순, 동일하면 종료 시간이 빠른 순으로 정렬
    list.sortWith(compareBy<Pair<Int, Int>> { it.first }.thenBy { it.second })

    // **마지막 상태의 우선 순위 큐의 size가 강의실 개수**
    val pq = PriorityQueue<Int>()
    for (e in list) {
        if (pq.isEmpty()) {
            pq.add(e.second)
            continue
        }
        // 시작 시간 >= 우선 순위 큐의 top (가장 빨리 끝나는 강의실 시간)이면 pq 갱신
        if (e.first >= pq.first()) {
            pq.poll()
            pq.add(e.second)
        }
        // else 새로운 종료 시간 push
        else
            pq.add(e.second)
    }
    println(pq.size)
}