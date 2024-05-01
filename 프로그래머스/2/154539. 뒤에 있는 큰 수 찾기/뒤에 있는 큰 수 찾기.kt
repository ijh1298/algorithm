import java.util.Stack

class Solution {
    fun solution(numbers: IntArray): IntArray {
        var answer: IntArray = IntArray(numbers.size) { i -> 0 }
        var stk = Stack<Pair<Int, Int>>()   // Pair(value, index)
        
        // Stack
        // peek 보다 작은 값이 들어오면 push
        // peek 보다 큰 값이 들어오면 pop 해주면서 뒷큰수로서 설정
        for ((index, number) in numbers.withIndex()) {
            while (!stk.isEmpty() && stk.peek().first < number) {
                answer[stk.peek().second] = number
                stk.pop()
            }
            stk.add(Pair(number, index))
        }
        for (i in answer.indices) {
            if (answer[i] == 0) answer[i] = -1
        }

        return answer
    }
}