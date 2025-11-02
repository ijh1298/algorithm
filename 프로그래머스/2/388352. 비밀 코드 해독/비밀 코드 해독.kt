class Solution {
    var answer = 0
    lateinit var used: BooleanArray
    
    fun solution(n: Int, q: Array<IntArray>, ans: IntArray): Int {
        // init
        used = BooleanArray(n + 1) { false }
        backtrack(n, 0, q, ans, 0)
        return answer
    }
    
    fun backtrack(n: Int, length: Int, q: Array<IntArray>, ans: IntArray, last: Int) {
        if (length == 5) {
            // q, ans에 부합하는지 확인
            check(q, ans)
        }
        for (i in (last + 1)..n) {
            if (!used[i]) {
                used[i] = true
                backtrack(n, length + 1, q, ans, i)
                used[i] = false
            }
        }
    }
    
    fun check(q: Array<IntArray>, ans: IntArray) {
        for (i in 0 until q.size) {
            val qCodes: IntArray = q[i]
            val ansCount: Int = ans[i]
            
            var count = 0
            qCodes.forEach { if (used[it]) count++ }
            // 모든 q에 대해 ans가 동일해야 함
            if (ansCount != count) return 
        }
        answer++
    }
}