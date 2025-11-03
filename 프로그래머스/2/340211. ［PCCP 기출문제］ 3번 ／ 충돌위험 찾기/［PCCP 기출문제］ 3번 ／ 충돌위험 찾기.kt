val visit = Array(101) { IntArray(101) { 0 } }
lateinit var points: Array<IntArray>
lateinit var routes: Array<IntArray>

class Solution {
    var answer = 0
    lateinit var robots: MutableList<Robot>
    
    fun solution(p: Array<IntArray>, r: Array<IntArray>): Int {
        points = p
        routes = r
        
        initRobots()
        run()
        
        return answer
    }
    
    fun run() {
        while (!robots.all { it.isDone }) {
            for (robot in robots) { 
                if (!robot.isDone) {
                    robot.move()
                }
            }
            checkConflict()
        }
    }
    
    fun initRobots() {
        robots = mutableListOf<Robot>()
        for (i in 0 until routes.size) {
            val startPoint = routes[i][0] - 1
            val (startR, startC) = points[startPoint]
            robots += Robot(startR, startC, routes[i])
            visit[startR][startC]++
        }
        checkConflict()
    }
    
    fun checkConflict() {
        for(robot in robots) {
            if (visit[robot.r][robot.c] > 1) {
                answer++
            }
            visit[robot.r][robot.c] = 0
        }
    }
}

data class Robot(
    var r: Int,
    var c: Int,
    val dests: IntArray,
    var curDestIdx: Int = 1,
    var isDone: Boolean = false
) {
    fun move() {
        val (dR, dC) = points[dests[curDestIdx] - 1]
        
        if (dR > r) { r++ }
        else if (dR < r) { r-- }
        else if (dC > c) { c++ }
        else if (dC < c) { c-- }
        else { 
            // 다음 목적지가 있는 경우
            if (curDestIdx < dests.size - 1) {
                curDestIdx++
                val (nDr, nDc) = points[dests[curDestIdx] - 1]
                if (nDr > r) { r++ }
                else if (nDr < r) { r-- }
                else if (nDc > c) { c++ }
                else if (nDc < c) { c-- }
            }
            // 모든 목적지 방문한 경우
            else {
                isDone = true
                return
            }
        }
        visit[r][c]++
    }
}