class Solution {
    fun solution(maps: Array<String>): IntArray {
        var answer: IntArray = intArrayOf()
        
        // maps : 맵 정보 2차원 배열
        val rowSize = maps.size
        val colSize = maps[0].length
        // visit : 방문 정보 2차원 배열
        val visit = Array(rowSize) { _ -> Array(colSize) { _ -> false } }
        
        fun dfs(row: Int, col: Int): Int {
            var sum = maps[row][col].digitToInt()   // Char 형은 toInt()가 ASCII를 반환함에 유의!
            val dir = arrayOf(
                intArrayOf(-1, 0, 1, 0),
                intArrayOf(0, 1, 0, -1)
            )
            for (i in 0..3) {
                val nextRow = row + dir[0][i]
                val nextCol = col + dir[1][i]
                
                if (nextRow < 0 || nextRow >= rowSize || nextCol < 0 || nextCol >= colSize)
                    continue
                
                if (maps[nextRow][nextCol] != 'X' && !visit[nextRow][nextCol]) {
                    visit[nextRow][nextCol] = true
                    sum += dfs(nextRow, nextCol)
                }
            }
            return sum
        }
        
        // 2차원 배열 maps를 처음부터 돌아보며, 음식이 있으면서 방문하지 않은 곳을 DFS
        maps.forEachIndexed { i, row ->
            row.forEachIndexed { j, one ->
                if (one != 'X' && !visit[i][j]) {
                    visit[i][j] = true
                    answer = answer.plus(dfs(i, j))
                }
            }
        }
        answer.sort()
        return if (answer.size == 0) intArrayOf(-1) else answer
    }
}