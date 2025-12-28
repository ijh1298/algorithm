class Solution {
    var ans = 0
    
    val MAX = 9999999
    val isPrimeNumber = BooleanArray(MAX + 1) { true }
    var isChecked = BooleanArray(MAX + 1) { false }
    lateinit var used: BooleanArray
    
    fun solution(numbers: String): Int {        
        used = BooleanArray(numbers.length) { false }
        
        getPrimeNumbers()
        
        for (i in 1..numbers.length) {
            bruteforce(numbers, i, mutableListOf<Int>())
        }
        
        return ans
    }
    
    // 에라토스테네스의 체
    fun getPrimeNumbers() {
        isPrimeNumber[0] = false
        isPrimeNumber[1] = false
        
        for (i in 2..MAX) {
            if (isPrimeNumber[i]) {
                // 자신을 제외하고 자신의 배수들을 모두 소수가 아님 처리
                var j = 2
                while (j * i <= MAX) {
                    isPrimeNumber[j * i] = false
                    j++
                }
            }
        }
    }
    
    // 모든 경우의 수
    fun bruteforce(numbers: String, length: Int, order: MutableList<Int>) {
        if (order.size == length) {
            check(numbers, order)
            return
        }
        for (i in 0 until numbers.length) {
            if (!used[i]) {
                used[i] = true
                order += i
                bruteforce(numbers, length, order)
                order.removeLast()
                used[i] = false
            }
        }
    }
    
    fun check(numbers: String, order: MutableList<Int>) {
        val int = order.map { numbers[it] }.joinToString("").toInt()
        if (isPrimeNumber[int] && !isChecked[int]) {
            ans++
            isChecked[int] = true
        }
    }
}
