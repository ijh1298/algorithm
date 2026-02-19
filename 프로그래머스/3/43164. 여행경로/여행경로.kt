data class Airport(
    val name: String,
    var visit: Boolean = false,
)

class Solution {
    val map = mutableMapOf<String, List<Airport>>()
    val path = mutableListOf<String>("ICN")
    val places = mutableSetOf<String>("ICN")
    var answer = arrayOf<String>()
    
    fun solution(tickets: Array<Array<String>>): Array<String> {
        val total = mutableSetOf<String>()
        for (t in tickets) {
            val (u, v) = t
            total += u
            total += v
            if (map[u] == null) {
                map[u] = listOf(Airport(v))
            } else {
                map[u] = map[u]!! + listOf(Airport(v))
            }
        }
        
        // 알파벳 순 정렬
        map.keys.forEach { key ->
            map[key]?.let {
                map[key] = it.sortedBy { it.name }
            }
        }
        
        // DFS
        dfs("ICN", total.size, 1 + tickets.size)
        return answer
    }
    
    var isDone = false
    fun dfs(cur: String, totalSize: Int, totalLength: Int) {
        if (isDone) return
        
        if (places.size == totalSize && path.size == totalLength) {
            answer = path.toTypedArray()
            isDone = true
            return
        }
        
        if (map[cur] != null) {
            for (next in map[cur]!!) {
                if (isDone) return
                
                if (!next.visit) {
                    next.visit = true
                    path += next.name
                    places += next.name

                    dfs(next.name, totalSize, totalLength)

                    next.visit = false
                    path.removeLast()
                    places -= next.name
                }
            }
        }
    }
}
