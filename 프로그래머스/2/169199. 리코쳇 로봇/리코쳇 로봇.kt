import java.util.*

class Solution {
    data class Point(val r: Int, val c: Int, val dir: Int, val dist: Int)

    fun solution(board: Array<String>): Int {
        var answer = Int.MAX_VALUE
        lateinit var start: IntArray
        lateinit var goal: IntArray
        val rowSize = board.size
        val colSize = board[0].length
        val map = Array(rowSize) { IntArray(colSize) { Int.MAX_VALUE } } // To store the distance

        board.forEachIndexed { i, row ->
            row.forEachIndexed { j, cell ->
                when (cell) {
                    'R' -> start = intArrayOf(i, j) // Start point
                    'G' -> goal = intArrayOf(i, j)  // Goal point
                    'D' -> map[i][j] = -1           // Obstacle
                }
            }
        }

        val directions = arrayOf(
            intArrayOf(-1, 0), // Up
            intArrayOf(0, 1),  // Right
            intArrayOf(1, 0),  // Down
            intArrayOf(0, -1)  // Left
        )

        val queue: Queue<Point> = LinkedList<Point>()
        for (i in directions.indices) {
            queue.add(Point(start[0], start[1], i, 0))
        }

        while (queue.isNotEmpty()) {
            val point = queue.poll()
            var (r, c, dir, dist) = point

            if (r == goal[0] && c == goal[1]) {
                answer = minOf(answer, dist)
                continue
            }

            val (dr, dc) = directions[dir]
            while (true) {
                val nr = r + dr
                val nc = c + dc
                if (nr !in 0 until rowSize || nc !in 0 until colSize || map[nr][nc] == -1) break
                r = nr
                c = nc
            }

            if (map[r][c] <= dist) continue
            map[r][c] = dist + 1

            for (i in directions.indices) {
                if (i != (dir + 2) % 4) { // Avoid the reverse direction
                    queue.add(Point(r, c, i, dist + 1))
                }
            }
        }
        return if (answer == Int.MAX_VALUE) -1 else answer 
    }
}