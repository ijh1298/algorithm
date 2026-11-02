class Solution {
    fun getNumber(array: IntArray, i: Int, j: Int, k: Int): Int {
        val list = mutableListOf<Int>()
        
        for (idx in i - 1 until j) {
            list += array[idx]
        }
        list.sort()
        
        return list[k - 1]
    }
    
    fun solution(array: IntArray, commands: Array<IntArray>): IntArray {
        var answer = mutableListOf<Int>()
        
        commands.forEach {
            val (i, j, k) = it
            answer += getNumber(array, i, j, k)
        }
        
        return answer.toIntArray()
    }
}
