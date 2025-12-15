class Solution {
    fun solution(want: Array<String>, number: IntArray, discount: Array<String>): Int { 
        val wants = want.toSet()
        val wantsMap = mutableMapOf<String, Int>()
        for (i in 0 until want.size) {
            wantsMap += want[i] to number[i]
        }
        
        val total = number.sum()
        var answer = 0
        for (i in 0..(discount.size - total)) {
            if (checkFrom(i, total, wants, discount, wantsMap.toMutableMap())) {
                answer++
            }
        }
        return answer
    }
    
    fun checkFrom(idx: Int, total: Int, wants: Set<String>, discount: Array<String>, count: MutableMap<String, Int>): Boolean {
        for (i in 0 until total) {
            if (count[discount[idx + i]] == null) return false
            count[discount[idx + i]]?.let { it ->
                if (it == 0) return false
                count[discount[idx + i]] = it - 1
            }
        }
        return true
    }
}
