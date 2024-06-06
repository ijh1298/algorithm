import java.util.Stack

class Solution {
    fun solution(number: String, k: Int): String {
        var answer = ""
        var cnt = k
        // 스택을 이용하여 해결
        var stack = Stack<Char> ()
        number.forEach { // 이번에 들어오는 수보다 작은 값이 stack에 있으면 제거할 수 있는 만큼 제거
            while (!stack.isEmpty() && stack.peek() < it && cnt > 0) {
                stack.pop()
                cnt--
            }
            stack.push(it)
        }
        while (!stack.isEmpty() && cnt > 0) { // 남은 cnt만큼 제거
            stack.pop()
            cnt--
        }
        stack.forEach { answer += it }
        return answer
    }
}