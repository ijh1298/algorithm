class Solution {
    fun solution(players: IntArray, m: Int, k: Int): Int {
        var answer = 0
        val servers = IntArray(25) { 0 }
        
        players.forEachIndexed { idx, p ->
            val curServer = servers[idx]
            val curLimit = (curServer + 1) * m
            
            if (p >= curLimit) {
                val minimumServer = p / m
                val gap = minimumServer - curServer
                answer += gap
                
                for (i in 0 until k) {
                    if (idx + i < 25) {
                        servers[idx + i] += gap
                    }
                }
            }
        }
        return answer
    }
}
