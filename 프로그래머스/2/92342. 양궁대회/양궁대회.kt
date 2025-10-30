class Solution {
    var totalScore = Int.MIN_VALUE
    var answer = intArrayOf(-1)
    
    // t점 과녁에 k발 맞춘 경우 점수: score[k][t]
    val scores = List(11) { IntArray(11) { 0 } }
    
    fun solution(n: Int, info: IntArray): IntArray {
        setScores(n, info.reversed())
        backtrack(n, n, 0, 0, intArrayOf())
        
        if (totalScore <= 0) {
            return intArrayOf(-1)
        }
        return answer.reversed().toIntArray()
    }
    
    fun setScores(n: Int, info: List<Int>) {
        for (i in 0..10) {
            for (k in 0..n) {
                val appeachCount = info[i]
                if (k > appeachCount) {
                    scores[i][k] = i
                } else if (appeachCount == 0 && k == 0) {
                    scores[i][k] = 0
                } else {
                    scores[i][k] = -i
                }
            }
        }
    }
    
    // n: 주어진 화살 수
    // res: 남은 화살 수
    // t: 현재 계산 중인 과녁 점수
    fun backtrack(
        n: Int,
        res: Int,
        t: Int,
        score: Int,
        result: IntArray
    ) {
        if (t > 10) {
            if (res == 0 && score > totalScore) {
                totalScore = score
                answer = result
            }
            return
        }
        
        for (i in minOf(n, res) downTo 0) {
            val curScore = score + scores[t][i]
            val resArrow = res - i
            val curResult = result + i
            backtrack(n, resArrow, t + 1, curScore, curResult)
        }
    }
}