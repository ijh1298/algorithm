class Solution {
    fun solution(name: Array<String>, yearning: IntArray, photo: Array<Array<String>>): IntArray {
        var answer: IntArray = intArrayOf()

        var answerList : MutableList<Int> = mutableListOf()
        var nameToYearning : HashMap<String, Int> = HashMap()

        for (i in name.indices) {
            nameToYearning[name[i]] = yearning[i]
        }

        for (i in photo.indices) {
            var sum = 0
            val len = photo[i].size
            for (j in 0..len - 1) {
                sum += nameToYearning[photo[i][j]]?.toInt() ?: 0
            }
            answerList.add(sum)
        }
        answer = answerList.toIntArray()
        return answer
    }
}