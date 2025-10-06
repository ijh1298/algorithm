class Solution {
    fun solution(fees: IntArray, records: Array<String>): IntArray {
        val parkings = records.map {
            val (time, carNumber, type) = it.split(' ')
            val (hour, minute) = time.split(':').map { it.toInt() }
            Parking(hour, minute, carNumber.toInt(), type)
        }
        
        // 입출차 기록
        val carRecords = mutableMapOf<Int, MutableList<Parking>>()
        parkings.forEach { carRecords[it.carNumber] = mutableListOf<Parking>() }
        
        // 삽입
        parkings.forEach { p ->
            carRecords[p.carNumber]!! += p
        }
        
        // List<Pair<차량 번호, 총합 시간>>
        val totalTimes: List<Pair<Int, Int>> = carRecords.keys.map { k ->
            k to getTotalTime(carRecords[k]!!)
        }
        
        val (baseTime, baseFee, unitTime, unitFee) = fees
        // List<차량 번호, 요금>
        val result = totalTimes.map { it.first to getTotalFee(it.second, baseTime, baseFee, unitTime, unitFee) }
        val answer = result.sortedBy { it.first }.map { it.second }.toIntArray()
        
        return answer
    }
    
    fun getTotalTime(parkings: MutableList<Parking>): Int {
        // 마지막 출차 기록이 없는 경우 추가
        if (parkings.size % 2 != 0) {
            parkings += parkings.first().copy(hour = 23, minute = 59)
        }
        
        var totalTime = 0
        for (i in 0 until parkings.size step 2) {
            val IN = parkings[i]
            val OUT = parkings[i + 1]
            val time = OUT.hour * 60 + OUT.minute - IN.hour * 60 - IN.minute
            totalTime += time
        }
        println(totalTime)
        return totalTime
    }
    
    fun getTotalFee(
        totalTime: Int,
        baseTime: Int,
        baseFee: Int,
        unitTime: Int,
        unitFee: Int,
    ): Int {
        if (totalTime <= baseTime) {
            return baseFee
        }
        
        val resTime = totalTime - baseTime
    
        // 나누어 떨어지지 않으면 단위 + 1
        val unit = resTime / unitTime + if (resTime % unitTime != 0) 1 else 0
        
        return baseFee + unit * unitFee
    }
}

data class Parking(
    val hour: Int,
    val minute: Int,
    val carNumber: Int,
    val type: String,
)