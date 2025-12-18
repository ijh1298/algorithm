class Solution {
    // 앞에서 세었을 때 i번째까지 topping 개수는 fromStart[i] 
    lateinit var fromStart: IntArray
    lateinit var fromEnd: IntArray
    
    fun solution(topping: IntArray): Int {
        fromStart = IntArray(topping.size) { 0 }
        fromEnd = IntArray(topping.size) { 0 }
        
        checkToppingCounts(topping)
        return getAnswer(topping.size)
    }
    
    fun checkToppingCounts(topping: IntArray) {
        // 앞에서부터 세기
        val visit1 = BooleanArray(10001) { false }
        var count1 = 0
        topping.forEachIndexed { idx, t ->
            if (!visit1[t]) {
                count1++
                visit1[t] = true
            }
            fromStart[idx] = count1
        }
        
        // 뒤에서부터 세기
        val visit2 = BooleanArray(10001) { false }
        var count2 = 0
        for (i in topping.size - 1 downTo 0) {
            val t = topping[i]
            if (!visit2[t]) {
                count2++
                visit2[t] = true
            }
            fromEnd[i] = count2
        }
    }
    
    fun getAnswer(size: Int): Int {
        var count = 0
        for (i in 0 until size - 1) {
            if (fromStart[i] == fromEnd[i + 1]) count++
        }
        return count
    }
}
