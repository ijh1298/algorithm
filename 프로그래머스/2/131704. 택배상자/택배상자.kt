import java.util.ArrayDeque

class Solution {
    fun solution(order: IntArray): Int {
        var answer: Int = 0
        
        var curPackage = 1
        val stack : ArrayDeque<Int> = ArrayDeque<Int>()
        val max = order.maxOrNull() ?: 1
        var flag = false
        
        for (o in order) {
            if (flag) break
            
            while (true) {
                val stackLast = if (stack.isEmpty()) -1 else stack.getLast()
                if (curPackage > max && stackLast != o) {
                    flag = true
                    break
                }
                                    
                if (o == curPackage) {
                    answer++
                    curPackage++
                    break
                }
                else {
                    if (stackLast == o) {
                        answer++
                        stack.pollLast()
                        break
                    }
                    else {
                        stack.add(curPackage)
                        curPackage++
                    }
                }
            }
        }
        return answer
    }
}