import java.util.LinkedList
import java.util.Queue

class Solution {
    fun solution(cards1: Array<String>, cards2: Array<String>, goal: Array<String>): String {
        var answer: String = ""
        var q1: Queue<String> = LinkedList()
        var q2: Queue<String> = LinkedList()

        q1.addAll(cards1)
        q2.addAll(cards2)
        
        answer = "Yes"
        for (i in goal) {
            if (i == q1.peek())
                q1.remove()
            else if (i == q2.peek())
                q2.remove()
            else {
                answer = "No"
                break
            }
        }
        return answer
    }
}