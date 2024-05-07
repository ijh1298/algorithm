class Solution {
    fun solution(picks: IntArray, minerals: Array<String>): Int {
        var answer: Int = 0
        // Solution : 가장 오래 걸리는 구간을 가장 좋은 곡괭이로 캐자!
        // 가장 오래 걸리는 구간 ? (다이아/철/돌 비중이 높은 순서)
        // 가장 좋은 곡괭이 ? 다이아/철/돌 순서

        class Area(var diamonds: Int, var irons: Int, var stones: Int, var originalIndex: Int, var pick: Char = 'D'): Comparable<Area> {
            override fun compareTo(other: Area): Int {
                return when {
                    this.diamonds != other.diamonds -> other.diamonds - this.diamonds
                    this.irons != other.irons -> other.irons - this.irons
                    else -> other.stones - this.stones
                }
            }
        }

        val numOfPicks = picks.sum()
        var len = numOfPicks * 5
        if (len > minerals.size) len = minerals.size
        val numOfArea = if (len % 5 == 0) len / 5 else len / 5 + 1
        // mineralOrder 다이아/철/돌 비중이 높은 순서로 정렬할 배열
        val mineralOrder = Array<Area>(numOfArea) {i -> Area(0, 0, 0, 0)}

        var cnt = 0
        var curMineralOrderIndex = 0
        var diamonds = 0
        var irons = 0
        var stones = 0
        for (index in 0 until len) {
            if (cnt == 5) {
                mineralOrder[curMineralOrderIndex] = Area(diamonds, irons, stones, curMineralOrderIndex)
                curMineralOrderIndex++
                // init
                diamonds = 0
                irons = 0
                stones = 0
                cnt = 0
            }

            when (minerals[index]) {
                "diamond" -> diamonds++
                "iron" -> irons++
                else -> stones++
            }
            cnt++
        }
        if (cnt != 0)                
            mineralOrder[curMineralOrderIndex] = Area(diamonds, irons, stones, curMineralOrderIndex)
        // 다이아/철/돌 비중이 높은 순서로 정렬
        mineralOrder.sort()

        // 가장 좋은 곡괭이부터 할당
        for (i in mineralOrder) {
            if (picks[0] != 0) {
                picks[0]--
                i.pick = 'D'
            }
            else if (picks[1] != 0) {
                picks[1]--
                i.pick = 'I'
            }
            else {
                picks[2]--
                i.pick = 'S'
            }
        }

        for (i in mineralOrder) {
            answer += when (i.pick) {
                'D' -> i.diamonds + i.irons + i.stones
                'I' -> i.diamonds * 5 + i.irons + i.stones
                else -> i.diamonds * 25 + i.irons * 5 + i.stones
            }
        }

        return answer
    }
}