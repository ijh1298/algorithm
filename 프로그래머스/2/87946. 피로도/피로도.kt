class Solution {
    var answer = 0
    var fatigue = 0
    lateinit var dg: Array<IntArray>
    lateinit var visit: BooleanArray
    
    fun solution(k: Int, dungeons: Array<IntArray>): Int {
        fatigue = k
        dg = dungeons
        visit = BooleanArray(dg.size) { false }
        backtrack(dg.size, mutableListOf<Int>())
        return answer
    }
    
    // backtrack으로 순열 순서 만들기
    fun backtrack(dungeonSize: Int, list: MutableList<Int>) {
        // 순서 완성 시 탐험
        if (list.size == dungeonSize) {
            explore(list)
        }
        for (i in 0 until dungeonSize) {
            if (!visit[i]) {
                visit[i] = true
                list += i
                backtrack(dungeonSize, list)
                list.removeLast()
                visit[i] = false
            }
        }
    }
    
    fun explore(list: MutableList<Int>) {
        var count = 0
        var cur = fatigue
        for (i in list) {
            val (min, cost) = dg[i]
            if (cur >= min) {
                cur -= cost
                count++
            }
        }
        answer = maxOf(answer, count)
    }
}
