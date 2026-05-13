import java.util.PriorityQueue

class Solution {    
    val pq = PriorityQueue<Pair<Int, Int>>(compareBy { it.second })
    
    fun solution(n: Int, costs: Array<IntArray>): Int {
        var answer = 0
        
        val visit = BooleanArray(n) { false }
        val edges = Array<MutableList<Pair<Int, Int>>>(n) { mutableListOf() }
        costs.forEach {
            val (u, v, w) = it
            edges[u] += v to w
            edges[v] += u to w
        }
        
        // MST 찾기
        pq += 0 to 0
        while (pq.isNotEmpty()) {
            val (v, w) = pq.poll()
            
            if (visit[v]) continue
            
            visit[v] = true
            answer += w
            
            edges[v].forEach {
                if (!visit[it.first]) {
                    pq += it
                }
            }
        }
        return answer
    }
}
