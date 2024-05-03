import java.util.*

class Solution {
    fun solution(maps: Array<String>): Int {
        var answer: Int = 0
        var visit = Array<Array<Boolean>>(maps.size) { Array(maps[0].length) { false } }

        // 1. Find start and end point
        var start = Triple(0, 0, 0)
        var lever = Triple(0, 0, 0)
        var end = Triple(0, 0, 0)
        for ((row, x) in maps.withIndex()) {
            for ((col, y) in x.withIndex()) {
                when (y) {
                    'S' -> start = Triple(row, col, 0)
                    'L' -> lever = Triple(row, col, 0)
                    'E' -> end = Triple(row, col, 0)
                }
            }
        }

        var queue : Queue<Triple<Int, Int, Int>> = LinkedList<Triple<Int, Int, Int>>()
        queue.add(start)

        // 2. BFS until Lever
        val startToLever = bfs(queue, maps, visit, 'L')
        if (startToLever == Int.MAX_VALUE) {
            answer = -1
            return answer
        }

        // 3. BFS until Exit
        queue.add(lever)
        visit.forEach { it.fill(false) } // visit init

        val leverToExit = bfs(queue, maps, visit, 'E')
        if (leverToExit == Int.MAX_VALUE) {
            answer = -1
            return answer
        }

        answer = startToLever + leverToExit
        return answer
    }
    
    fun bfs(queue: Queue<Triple<Int, Int, Int>>, maps: Array<String>, visit: Array<Array<Boolean>>, destination: Char): Int {
        var distance = Int.MAX_VALUE
        // Direction for up, right, down, left
        var dx = arrayOf(-1, 0, 1, 0)
        var dy = arrayOf(0, 1, 0, -1)

        while (queue.isNotEmpty()) {
        val cur = queue.remove()
        if (maps[cur.first][cur.second] == destination && distance > cur.third)
            distance = cur.third

        for (i in 0 until 4) {
            val nextRow = cur.first + dx[i]
            val nextCol = cur.second + dy[i]

            if (nextRow < 0 || nextCol < 0 || nextRow >= maps.size || nextCol >= maps[nextRow].length)
                continue

            if (!visit[nextRow][nextCol] && maps[nextRow][nextCol] != 'X') {
                visit[nextRow][nextCol] = true
                queue.add(Triple(nextRow, nextCol, cur.third + 1))
            }
        }
    }
        return distance
    }
}