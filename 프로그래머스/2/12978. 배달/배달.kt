class Solution {
    lateinit var dist: Array<IntArray>
    
    fun solution(N: Int, road: Array<IntArray>, k: Int): Int {
        dist = Array(N + 1) { IntArray(N + 1) { 1_000_000_000 } }
        
        // 도로 시간 설정
        road.forEach {
            val (u, v, w) = it
            // 길이 여러 개면 더 짧은 길 선택
            dist[u][v] = minOf(dist[u][v], w)
            dist[v][u] = minOf(dist[v][u], w)
        }
        
        // 자기 자신은 0으로 초기화
        for (i in 1..N) {
            dist[i][i] = 0
        }
        
        // 플로이드 워셜
        for (m in 1..N) {
            for (i in 1..N) {
                for (j in 1..N) {
                    // 거쳐가는 게 바로 가는 것보다 짧은 경우 갱신
                    if (dist[i][m] + dist[m][j] < dist[i][j]) {
                        dist[i][j] = dist[i][m] + dist[m][j]
                    }
                }
            }
        }
        
        var answer = 0
        for (i in 1..N) {
            if (dist[1][i] <= k) {
                answer++
            }
        }
        return answer
    }
}