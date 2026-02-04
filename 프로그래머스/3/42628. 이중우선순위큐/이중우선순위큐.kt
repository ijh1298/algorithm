import java.util.PriorityQueue

class Solution {
    fun solution(operations: Array<String>): IntArray {
        val maxHeap = PriorityQueue<Int>(compareByDescending { it })
        val minHeap = PriorityQueue<Int>(compareBy { it })
        
        operations.forEach { operation ->
            val (op, num) = operation.split(" ")
            val number = num.toInt()
            
            when (op) {
                "I" -> {
                    maxHeap.add(number)
                    minHeap.add(number)
                }
                "D" -> {
                    if (maxHeap.isNotEmpty()) {
                        if (number == 1) {
                            // 최댓값 제거
                            val max = maxHeap.poll()
                            minHeap.remove(max)
                        } else {
                            // 최솟값 제거
                            val min = minHeap.poll()
                            maxHeap.remove(min)
                        }
                    }
                }
            }
        }
        
        return if (maxHeap.isEmpty()) {
            intArrayOf(0, 0)
        } else {
            intArrayOf(maxHeap.peek(), minHeap.peek())
        }
    }
}
