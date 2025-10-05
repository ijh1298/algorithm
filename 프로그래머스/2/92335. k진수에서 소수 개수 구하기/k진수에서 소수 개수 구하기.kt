class Solution {
    fun solution(n: Int, k: Int): Int {
        val kString = n.toString(k)
        val numbers = kString.splitZeros()
        val answer = numbers.count { it.isPrime() }
        
        return answer
    }
    
    // k 진수로 바꾼 수 문자열 반환
    fun getKstring(number: Int, k: Int): String {
        var cur = number
        var list = mutableListOf<Int>()
        
        while (cur != 0) {
            list += cur % k
            cur /= k
        }
        return list.reversed().joinToString("")
    }
    
    // 0을 기준으로 숫자를 split한 List<Int> 반환
    fun String.splitZeros(): List<Long> {
        return split('0').filter { it.isNotBlank() }.map { it.toLong() }
    }
    
    // 소수인지 판단
    fun Long.isPrime(): Boolean {
        if (this == 1L) return false
        if (this == 2L) return true
        if (this % 2L == 0L) return false
        
        // 2..sqrt(N)에서 나누어 떨어지는 값이 있는지 판단 
        var i = 3L
        while (i * i <= this) {
            if (this % i == 0L) {
                return false
            }
            i += 2L
        }
        return true
    }
}