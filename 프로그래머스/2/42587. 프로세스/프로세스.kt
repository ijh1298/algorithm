data class Process(val prio: Int, val idx: Int)

class Solution {
    fun solution(priorities: IntArray, location: Int): Int {
        val descOrder = priorities.sortedDescending().toMutableList()
        
        val p = priorities.mapIndexed { idx, prio -> Process(prio, idx) }.toMutableList()
        
        var answer = 0
        var cnt = 1
        while (p.isNotEmpty()) {
            val first = p.removeFirst()
            if (first.prio == descOrder.first()) {
                descOrder.removeFirst()
                
                if (first.idx == location) { 
                    answer = cnt
                    break
                }
                cnt++
            } else {
                p += first
            }
        }
        
        return answer
    }
}
