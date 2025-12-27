import java.util.PriorityQueue

class Solution {
    fun solution(jobs: Array<IntArray>): Int {
        // 우선 순위 큐
        val pq = PriorityQueue<Job>(compareBy<Job> { it.size }.thenBy { it.requestTime }.thenBy { it.number })
        
        // 작업 큐
        val q = ArrayDeque<Job>()
        jobs.mapIndexed { idx, job -> Job(idx, job[0], job[1]) }.sortedBy { it.requestTime }.forEach { q.addLast(it) }
        
        var list = mutableListOf<Int>()
        
        var cur: Job? = pq.poll()
        var time = 0
        
        while (q.isNotEmpty() || pq.isNotEmpty()) {
            while (q.isNotEmpty() && q.first().requestTime <= time) {
                pq.add(q.removeFirst())
            }
            if (pq.isNotEmpty()) {
                val cur = pq.poll()
                time += cur.size
                list += time - cur.requestTime
            } else {
                // 다음 첫 작업 시간으로 이동
                time = q.first().requestTime
            }
        }
        var answer: Int = list.sum() / list.size
        return answer
    }
}

data class Job(
    val number: Int,
    val requestTime: Int,
    val size: Int
)