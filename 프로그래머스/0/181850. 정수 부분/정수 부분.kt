class Solution {
    fun solution(flo: Double): Int {
        var answer: Int = 0
        val str = flo.toString()
        var index = 0
        val len = str.length
        
        for (i in 0..len) {
            if (str[i] == '.') {
                index = i
                break
            }
        }
        answer = str.removeRange(index, len).toInt()
        return answer
    }
}