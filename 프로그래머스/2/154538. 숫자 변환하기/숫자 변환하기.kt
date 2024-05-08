import java.util.*

class Solution {
    fun solution(x: Int, y: Int, n: Int): Int {
    var answer: Int = Int.MAX_VALUE
    var queue : Queue<Pair<Int, Int>> = LinkedList()
    var visit = Array<Boolean>(1000001) { i -> false }

    // BFS
    queue.add(Pair(x, 0))
    while (!queue.isEmpty()) {
        val cur = queue.remove()
        var next = 0
        
        if (cur.first == y && answer > cur.second) 
            answer = cur.second
        
        next = cur.first * 3
        if (y >= next && !visit[next]) {
            visit[next] = true
            queue.add(Pair(next, cur.second + 1))
        }
        next = cur.first * 2
        if (y >= next && !visit[next]) {
            visit[next] = true
            queue.add(Pair(next, cur.second + 1))
        }
        next = cur.first + n
        if (y >= next && !visit[next]) {
            queue.add(Pair(next, cur.second + 1))
        }
    }
        return if (answer == Int.MAX_VALUE) -1 else answer
    }
}