class Solution {
    fun solution(queue1: IntArray, queue2: IntArray): Int {
        var answer = Int.MAX_VALUE
        
        val aQueue = ArrayDeque(queue1.toList())
        val bQueue = ArrayDeque(queue2.toList())
        
        var aSize = aQueue.sum().toLong()
        var bSize = bQueue.sum().toLong()
        
        for (i in 0 until queue1.size) {
            if (aSize == bSize) {
                answer = minOf(answer, i * 2)
                continue
            }
            
            val firstResult = popAinsertB(aQueue, bQueue, i * 2, aSize, bSize)
            val secondResult = popAinsertB(bQueue, aQueue, i * 2, bSize, aSize)
            
            if (firstResult != -1) answer = minOf(answer, firstResult)
            if (secondResult != -1) answer = minOf(answer, secondResult)
            
            val aFirst = aQueue.removeFirst()
            val bFirst = bQueue.removeFirst()
            aQueue.addLast(bFirst)
            bQueue.addLast(aFirst)
            
            aSize = aSize - aFirst + bFirst
            bSize = bSize - bFirst + aFirst
        }

        if (answer == Int.MAX_VALUE) answer = -1
        return answer
    }
    
    // A 큐를 계속 pop하고, B 큐에 계속 insert 해서 같아지는지 확인
    fun popAinsertB(a: ArrayDeque<Int>, b: ArrayDeque<Int>, count: Int, aSize: Long, bSize: Long): Int {
        var count = count
        
        var aSum = aSize
        var bSum = bSize
        
        var aStart = 0
        // 마지막 idx가 될 때까지
        while (aStart < a.size) {
            aSum -= a[aStart]
            bSum += a[aStart]
            count++
            aStart++
            if (aSum == bSum) {
                return count
            } else if (aSum < bSum) {
                break
            }
        }
        return -1
    }
}