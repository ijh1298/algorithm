class Solution {
    fun solution(maps: Array<String>): IntArray {
        val row = maps.size
        val col = maps[0].length
        
        val visit = Array(row) { BooleanArray(col) { _ -> false } }
        
        val dx = listOf(1, 0, -1, 0)
        val dy = listOf(0, 1, 0, -1)
        
        fun dfs(r: Int, c: Int): Int {
            var sum = 0
            if (maps[r][c] != 'X') sum = maps[r][c].digitToInt()
            
            for (i in 0..3) {
                val nR = r + dx[i]
                val nC = c + dy[i]

                if (nR < 0 || nR >= row || nC < 0 || nC >= col) continue
                if (visit[nR][nC] || maps[nR][nC] == 'X') continue

                visit[nR][nC] = true
                sum += dfs(nR, nC)
            }
            return sum
        }
        
        val answer = mutableListOf<Int>()
        
        // DFS
        maps.forEachIndexed { r, row ->
            row.forEachIndexed { c, land ->
                if (!visit[r][c] && land != 'X') {
                    visit[r][c] = true
                    answer += dfs(r, c)
                }
            }
        }
        
        if (answer.isEmpty()) return intArrayOf(-1)

        return answer.sorted().toIntArray()
    }
}
