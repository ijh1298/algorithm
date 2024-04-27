import java.util.LinkedList
import java.util.Queue

class Solution {
    fun solution(n: Int, m: Int, section: IntArray): Int {
        var answer: Int = 0
        var queue : Queue<Int> = LinkedList()

        section.forEach {
            queue.add(it)
        }

        while (!queue.isEmpty()) {
            val cur = queue.first()
            queue.remove()

            val cutLine = cur + m - 1
            while (!queue.isEmpty() && queue.first() <= cutLine) {
                queue.remove()
            }
            answer++
        }

        return answer
    }
}