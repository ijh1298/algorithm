class Solution {
    lateinit var matrix: Array<IntArray>
    
    fun solution(rows: Int, columns: Int, queries: Array<IntArray>): IntArray {
        var answer = intArrayOf()
        
        initMatrix(rows, columns)
        queries.forEach {
            val (x1, y1, x2, y2) = it
            answer += rotate(x1 - 1, y1 - 1, x2 - 1, y2 - 1)
        }
        
        return answer
    }
    
    fun initMatrix(rows: Int, columns: Int) {
        matrix = Array(rows) { IntArray(columns) { 0 } }
        var cnt = 1
        for (i in 0 until rows) {
            for (j in 0 until columns) {
                matrix[i][j] = cnt++
            }
        }
    }
    
    fun rotate(x1: Int, y1: Int, x2: Int, y2: Int): Int {
        var minValue = matrix[x1][y1]
        
        val tmp1 = matrix[x1][y2] // 우상단 모서리
        val tmp2 = matrix[x2][y2] // 우하단 모서리
        val tmp3 = matrix[x2][y1] // 좌하단 모서리
        
        minValue = minOf(minValue, tmp1, tmp2, tmp3)
        
        // 상 우 하 좌 순서로 교환
        for (dy in y2 downTo y1 + 1) {
            minValue = minOf(minValue, matrix[x1][dy])
            matrix[x1][dy] = matrix[x1][dy - 1]
        }
        for (dx in x2 downTo x1 + 1) {
            minValue = minOf(minValue, matrix[dx][y2])
            matrix[dx][y2] = matrix[dx - 1][y2]
        }
        for (dy in y1 until y2) {
            minValue = minOf(minValue, matrix[x2][dy])
            matrix[x2][dy] = matrix[x2][dy + 1]
        }
        for (dx in x1 until x2) {
            minValue = minOf(minValue, matrix[dx][y1])
            matrix[dx][y1] = matrix[dx + 1][y1]
        }
        
        matrix[x1 + 1][y2] = tmp1
        matrix[x2][y2 - 1] = tmp2
        matrix[x2 -1][y1] = tmp3
        
        return minValue
    }
}
