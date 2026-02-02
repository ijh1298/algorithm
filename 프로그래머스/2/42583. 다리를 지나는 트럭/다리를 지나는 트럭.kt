data class Truck(
    val weight: Int, 
    var time: Int = 0,
) {
    // 도달했는지 확인 메서드
    fun isComplete(bridgeLength: Int): Boolean {
        return if (bridgeLength <= time) true else false
    }
    
    fun increase() {
        time++
    }
}

class Solution {
    fun solution(bridge_length: Int, weight: Int, truck_weights: IntArray): Int {
        // 다리 (큐)
        val bridge = mutableListOf<Truck>()
        var bridgeWeight = 0
        // 대기 트럭 (큐)
        val waitingTrucks = truck_weights.toMutableList()
        
        // 경과 시간
        var answer = 0
        
        while (true) {
            if (waitingTrucks.isEmpty() && bridge.isEmpty()) break
            
            // 도착한 트럭은 다리에서 제외
            while (bridge.isNotEmpty() &&
                    bridge.first().isComplete(bridge_length)) {
                val removed = bridge.removeFirst()
                bridgeWeight -= removed.weight
            }
            
            val first = waitingTrucks.firstOrNull()
            if (first != null) {
                // 다리에 오를 수 있으면
                if (weight >= bridgeWeight + first) {
                    waitingTrucks.removeFirst()
                    bridge += Truck(first)
                    bridgeWeight += first
                }
            }
            
            bridge.forEach { it.increase() }
            
            answer++
        }
        
        return answer
    }
}
