class Solution {
    fun solution(s: String): IntArray {
        var str = s
        var whileCount = 0
        var zerosCount = 0
        while (str != "1") {
            whileCount++
            val zeros = str.count { it == '0' }
            zerosCount += zeros
            str = (str.length - zeros).toString(2)
        }
        return intArrayOf(whileCount, zerosCount)
    }
}