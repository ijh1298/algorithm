class Solution {
    val answer = IntArray(4) { 0 }
    
    val MAX = 1_000_000
    val edges = List(MAX + 1) { mutableListOf<Int>() }
    val vertices = mutableSetOf<Int>()
    
    // 자기(정점)로 들어오는 간선이 있는지 여부
    val hasIncoming = BooleanArray(MAX + 1) { false }
    
    // 방문 여부
    val visit = BooleanArray(MAX + 1) { false }
    
    fun solution(e: Array<IntArray>): IntArray {
        e.forEach {
            val (u, v) = it
            vertices += u
            vertices += v
            edges[u] += v
            hasIncoming[v] = true
        }
        
        val startIdx = findStartIdx()
        answer[0] = startIdx
        
        edges[startIdx].forEach { next ->
            visit[next] = true
            val result = dfs(next, next)
            when (result) {
                GRAPH.DONUT -> answer[1]++
                GRAPH.STICK -> answer[2]++
                GRAPH.EIGHT -> answer[3]++
            }
        }
        return answer
    }
    
    // indegree는 0이고, outdegree가 가장 큰 정점을 찾기
    fun findStartIdx(): Int {
        var idx = 1
        var outdegree = 0
        vertices.forEach {
            if (!hasIncoming[it]) {
                if (edges[it].size > outdegree) {
                    idx = it
                    outdegree = edges[it].size
                }
            }
        }
        return idx
    }
    
    // 시작(생성) 정점은 포함하지 않고 시작하기
    fun dfs(
        start: Int,
        cur: Int,
    ): GRAPH {      
        // 중간 정점의 outdegree가 2개인 경우
        if (edges[cur].size == 2) {
            return GRAPH.EIGHT
        }
        for (next in edges[cur]) {            
            if (!visit[next]) {
                visit[next] = true
                return dfs(start, next)
            }
            // 다음 갈 경로가 시작 지점이고, 시작 지점이 하나로만 진행되는 경우
            else if (next == start && edges[start].size == 1){
                // 도넛 그래프 
                return GRAPH.DONUT
            }
        }
        // 다음 갈 경로가 없는 경우, 막대 그래프
        return GRAPH.STICK
    }
}

enum class GRAPH {
    STICK, DONUT, EIGHT
}