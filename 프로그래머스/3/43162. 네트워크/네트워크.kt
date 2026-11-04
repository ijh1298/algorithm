class Solution {
    fun solution(n: Int, computers: Array<IntArray>): Int {
        val visit = BooleanArray(n) { false }
        
        fun dfs(start: Int) {
            visit[start] = true
            computers[start].forEachIndexed { i, it ->
                if (!visit[i] && it == 1) {
                    visit[i] = true
                    dfs(i)
                }
            }
        }
        
        var answer = 0
        for (i in 0 until n) {
            if (!visit[i]) {
                answer++
                dfs(i)
            }
        }
        
        return answer
    }
}
