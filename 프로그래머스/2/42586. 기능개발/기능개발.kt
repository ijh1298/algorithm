class Solution {
    fun solution(progresses: IntArray, speeds: IntArray): IntArray {
        // 남은 퍼센티지 계산
        val leftWorks = progresses.map { 100 - it }
        
        // 남은 날짜로 매핑
        val leftDays = leftWorks.mapIndexed { idx, work ->
            val result = work / speeds[idx]
            // 올림 적용
            if (work % speeds[idx] != 0) {
                result + 1
            } else {
                result
            }
        }.toMutableList()
    
        val answer = mutableListOf<Int>()

        // 첫날보다 작거나 같은 날을 제거하며 카운트 계산
        // 첫날보다 많이 남아있는 날을 발견하면 카운트 초기화
        while (true) {
            val std = leftDays.firstOrNull()
            if (std == null) break
            
            var cnt = 0
            while (true) {
                val first = leftDays.firstOrNull()
                if (first == null) {
                    if (cnt > 0) answer += cnt
                    break
                }
                
                if (std >= first) {
                    cnt++
                    leftDays.removeFirst()
                } else {
                    if (cnt > 0) answer += cnt
                    break
                }
            }
        }
        return answer.toIntArray()
    }
}