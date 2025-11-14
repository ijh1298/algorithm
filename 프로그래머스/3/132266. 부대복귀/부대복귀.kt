class Solution {
    // dist: destination -> source 거리
    lateinit var dist: IntArray
    lateinit var routes: List<MutableList<Int>>
    
    fun solution(n: Int, roads: Array<IntArray>, sources: IntArray, destination: Int): IntArray {
        dist = IntArray(n + 1) { 1_000_000_000 }
        dist[destination] = 0
        
        routes = List(n + 1) { mutableListOf() }
        roads.forEach { 
            val (u, v) = it
            routes[u] += v
            routes[v] += u
        }
        
        shortestPath(destination)
        
        val answer = 
            sources.map {
                val value = dist[it]
                if (value == 1_000_000_000) -1 else value
            }.toIntArray()
        
        return answer
    }
    
    fun shortestPath(start: Int) {
        // Pair<누적 거리, 현재 번호>
        val queue = ArrayDeque<Pair<Int, Int>>()
        routes[start].forEach { 
            dist[it] = 1
            queue.addLast(1 to it)
        }
        
        while (queue.isNotEmpty()) {
            val (totalDist, cur) = queue.removeFirst()
            
            routes[cur].forEach { next ->
                if (dist[next] > totalDist + 1) {
                    dist[next] = totalDist + 1
                    queue.addLast(totalDist + 1 to next)
                }
            }
        }
    }
}