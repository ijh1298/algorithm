class Solution {
    lateinit var edges: Array<MutableList<Int>>
    // dist: 1번 노드로부터 최단 거리를 담은 배열
    lateinit var dist: IntArray
    
    val queue = mutableListOf<Int>()
    
    fun solution(n: Int, edge: Array<IntArray>): Int {
        edges = Array(n + 1) { mutableListOf<Int>() }
        
        edge.forEach {
            val (u, v) = it
            edges[u] += v
            edges[v] += u
        }
        
        dist = IntArray(n + 1) { 100_000_000 }
        // 1번 노드 삽입
        queue.add(1)
        dist[0] = 0
        dist[1] = 0
        
        dijkstra()
        
        val max = dist.max()
        val answer = dist.count { it == max }
        
        return answer
    }
    
    fun IntArray.max(): Int {
        var max = 0
        this.forEach { if (it > max) max = it }
        return max
    }
    
    fun dijkstra() {
        while (queue.isNotEmpty()) {
            val cur = queue.removeFirst()
            
            edges[cur].forEach { next ->
                val curDist = dist[cur]
                if (curDist + 1 < dist[next]) {
                    dist[next] = curDist + 1
                    queue += next
                }
            }
        }
    }
}
