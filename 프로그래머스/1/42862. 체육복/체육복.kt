class Solution {
    fun solution(n: Int, lost: IntArray, reserve: IntArray): Int {
        var answer = n
        val lost = lost.sorted()
        val reserve = reserve.sorted()
        val reserves = BooleanArray(n + 1) { false }
        reserve.forEach { reserves[it] = true }
        // 여분이 있는데 도난 당한 사람 filter
        lost.filter { it in reserve }.forEach { reserves[it] = false }
        
        lost.filter { it !in reserve }.forEach { 
            if (reserves[it - 1]) {
                reserves[it - 1] = false
            } 
            else if (it != n && reserves[it + 1]) {
                reserves[it + 1] = false    
            }
            else {
                answer--
            }
        }
        return answer
    }
}
