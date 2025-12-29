class Solution {
    fun solution(brown: Int, yellow: Int): IntArray {
        var answer = intArrayOf()
        
        // 총 넓이
        val total = brown + yellow
        
        // h는 가로 길이
        for (h in 3..total) {
            // 나누어 떨어지는 경우
            if (total % h == 0) {
                // v는 세로 길이
                val v = total / h
                if (h * 2 + v * 2 - 4 == brown) {
                    answer = intArrayOf(v, h)
                    break
                }
            }
        }
        return answer
    }
}
