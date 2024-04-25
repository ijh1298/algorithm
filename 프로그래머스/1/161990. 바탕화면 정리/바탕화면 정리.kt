class Solution {
    fun solution(wallpaper: Array<String>): IntArray {
        var answer: IntArray = intArrayOf()

        var line = 0
        var leftMost = wallpaper[0].length - 1
        var rightMost = 0
        var top = wallpaper.size - 1
        var bottom = 0

        wallpaper.forEach {
            for (i in it.indices) {
                if (it[i] == '#') {
                    if (i < leftMost) leftMost = i
                    if (i > rightMost) rightMost = i
                    if (top > line) top = line
                    if (bottom < line) bottom = line
                }
            }
            line++
        }
        answer = intArrayOf(top, leftMost, bottom + 1, rightMost + 1)
        return answer
    }
}