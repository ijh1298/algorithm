class Solution {
    lateinit var matrix: Array<IntArray>
    lateinit var visit: BooleanArray
    
    fun solution(n: Int, computers: Array<IntArray>): Int {
        matrix = computers
        visit = BooleanArray(n) { false }
        
        var answer = 0
        for (i in 0 until n) {
            if (!visit[i]) {
                println(i)
                answer++
                dfs(i, n)
            }
        }
        return answer
    }
    
    fun dfs(cur: Int, n: Int) {
        visit[cur] = true
        for (next in 0 until n) {
            if (matrix[cur][next] == 1 && !visit[next]) {
                visit[next] = true
                dfs(next, n)
            }
        }
    }
}
