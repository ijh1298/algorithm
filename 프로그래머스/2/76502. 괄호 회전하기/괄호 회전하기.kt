class Solution {
    fun solution(s: String): Int {
        return rotateAndCount(s)
    }
    
    // 문자열 회전
    fun rotateAndCount(str: String): Int {
        val deque = ArrayDeque<Char>()
        str.forEach { deque.addLast(it) }
        
        var count = 0
        if (check(deque)) count++ 
        
        repeat(str.length - 1) {
            val first = deque.removeFirst()
            deque.addLast(first)
            
            if (check(deque)) count++ 
        }
        return count
    }
    
    // 올바른 괄호 문자열인지 반환
    fun check(str: ArrayDeque<Char>): Boolean {
        val stack = ArrayDeque<Char>()
        
        for (s in str) {
            val lastS = stack.lastOrNull() ?: 'a' 
            // 왼쪽 괄호가 들어온 경우 삽입
            if (s == '[' || s == '{' || s == '(') {
                stack.addLast(s)
            }
            // 오른쪽 괄호가 들어온 경우
            else {
                // 짝이 맞으면 왼쪽 괄호 pop
                if ((s == ']' && lastS == '[') || (s == '}' && lastS == '{') || (s == ')' && lastS == '(')) {
                    stack.removeLast()
                }
                // 중단
                else {
                    return false
                }
            }
        }
        return stack.isEmpty()
    }
}