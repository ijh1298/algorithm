import java.util.Stack

class Solution {
    fun solution(plans: Array<Array<String>>): Array<String> {
        var answer: Array<String> = arrayOf<String>()
        
        // 시작 시간 순으로 정렬
        val sortedPlans = plans.sortedWith(compareBy { it[1] })
        var stack : Stack<Pair<String, Int>> = Stack<Pair<String, Int>>()

        var curName = ""
        var curTime : Int = (sortedPlans[0][1][0].toInt() * 10 + sortedPlans[0][1][1].toInt()) * 60 + sortedPlans[0][1][3].toInt() * 10 + sortedPlans[0][1][4].toInt()
        var cost = 0
        var nextTime = 0
        var nextCost = 0
        for (i in 1 .. sortedPlans.size) {
            // 마지막 index 일 때
            if (i == sortedPlans.size) {
                answer += sortedPlans[i - 1][0]
                break
            }
            nextTime = (sortedPlans[i][1][0].toInt() * 10 + sortedPlans[i][1][1].toInt()) * 60 + sortedPlans[i][1][3].toInt() * 10 + sortedPlans[i][1][4].toInt()
            nextCost = nextTime - curTime
            curName = sortedPlans[i - 1][0]
            cost = sortedPlans[i - 1][2].toInt()

            if (nextCost > cost) {
                answer += curName
                var extraTime = nextCost - cost
                while (extraTime > 0 && !stack.empty()) {
                    val top = stack.pop()
                    if (top.second > extraTime) {
                        stack.push(Pair(top.first, top.second - extraTime))
                        extraTime = 0
                    }
                    else if (top.second == extraTime) {
                        answer += top.first
                        extraTime = 0
                    }
                    else {
                        answer += top.first
                        extraTime -= top.second
                    }
                }
            }
            else if (nextCost == cost)
                answer += curName
            else // nextCost < cost 일 때
                stack.push(Pair(curName, cost - nextCost))

            curTime = nextTime
        }
        while (!stack.empty())
            answer += stack.pop().first

        return answer
    }
}