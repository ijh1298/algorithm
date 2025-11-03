class Solution {
    lateinit var d: IntArray
    lateinit var t: IntArray
    
    fun solution(diffs: IntArray, times: IntArray, limit: Long): Int {
        d = diffs
        t = times
        return bSearch(limit)
    }
    
    // 문제 푸는데 걸리는 시간
    fun getTime(diff: Int, level: Int, curTime: Int, prevTime: Int): Int {
        return if (diff <= level) {
            curTime
        } else {
            val failCount = diff - level
            val failTime = (curTime + prevTime) * failCount
            curTime + failTime
        }
    }
    
    // 주어진 level로 시간 limit 내에 풀어지는지 확인
    fun check(level: Int, limit: Long): Boolean {
        var totalTime = 0L
        for (i in 0 until d.size) {
            val prevTime = if (i == 0) 0 else t[i - 1]
            totalTime += getTime(d[i], level, t[i], prevTime)
            
            if (totalTime > limit) { return false }
        }
        return totalTime <= limit
    }
    
    // level을 이진 탐색으로 찾음
    fun bSearch(limit: Long): Int {
        var maxLevel = 0
        d.forEach { maxLevel = maxOf(maxLevel, it) }
        
        var l = 1
        var r = maxLevel
        var mid = (l + r) / 2
        
        var answer = 1
        while (l <= r) {
            mid = (l + r) / 2
            if (check(mid, limit)) {
                answer = mid
                r = mid - 1
            } else {
                l = mid + 1
            }
        }
        return answer
    }
}
