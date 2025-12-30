class Solution {
    var ans = Int.MAX_VALUE
    
    lateinit var edges: List<MutableList<Int>>
    
    fun solution(n: Int, wires: Array<IntArray>): Int {
        edges = List(n + 1) { mutableListOf<Int>() }
        wires.forEach {
            val (u, v) = it
            edges[u] += v
            edges[v] += u
        }
        bruteforce(n, wires)
        
        return ans
    }
    
    fun bruteforce(n: Int, wires: Array<IntArray>) {
        // u와 v를 끊음
        for (wire in wires) {
            val visit = BooleanArray(n + 1) { false }
            
            val (u, v) = wire
            
            val queue = ArrayDeque<Int>()
            
            // u에 연결된 정점 삽입, v 제외
            edges[u].forEach {
                if (it != v) {
                    queue.addLast(it)
                }
            }
            
            // u와 연결된 정점 개수
            var cnt1 = 1
            visit[u] = true
            while (queue.isNotEmpty()) {
                val cur = queue.removeFirst()
                cnt1++
                
                visit[cur] = true
                
                edges[cur].forEach {
                    if (!visit[it]) {
                        queue.addLast(it)
                    }
                }
            }
            
            // v에 연결된 정점 삽입, u 제외
            edges[v].forEach {
                if (it != u) {
                    queue.addLast(it)
                }
            }
            
            // v와 연결된 정점 개수
            var cnt2 = 1
            visit[v] = true
            while (queue.isNotEmpty()) {
                val cur = queue.removeFirst()
                cnt2++
                
                visit[cur] = true
                
                edges[cur].forEach {
                    if (!visit[it]) {
                        queue.addLast(it)
                    }
                }
            }
            
            val result = if (cnt1 > cnt2) { cnt1 - cnt2 } else { cnt2 - cnt1 }
            
            ans = minOf(ans, result)
        }
    }
}
