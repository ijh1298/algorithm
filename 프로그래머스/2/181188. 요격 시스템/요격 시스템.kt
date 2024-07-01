import kotlin.math.min

class Solution {
    fun solution(targets: Array<IntArray>): Int {
        var answer: Int = 1
        // 오름차순 정렬
        val sortedArray = targets.sortedWith(compareBy<IntArray>{it[0]}.thenBy{it[1]})
        
        var (prevS, prevE) = sortedArray[0]
        
        for (i in 1 until sortedArray.size) {
            val (curS, curE) = sortedArray[i]
            
            if (prevE > curS) { // 범위가 겹치면, 새로운 미사일 쏠 필요가 없음
                prevE = min(prevE, curE)
            }
            else {              // 새로운 범위면, 새로운 미사일 발사
                answer++
                prevE = curE
            }
            prevS = curS
        }
        return answer
    }
}