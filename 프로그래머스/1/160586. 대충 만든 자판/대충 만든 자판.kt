class Solution {
    fun solution(keymap: Array<String>, targets: Array<String>): IntArray {
        var answer: IntArray = intArrayOf()
        var answerList = arrayListOf<Int>()
        // A~Z 최솟값을 담는 배열
        var arr = Array<Int>(26) { i -> -1 }

        keymap.forEach {
            for (i in it.indices) {
                var cur = it[i] - 'A'

                if (arr[cur] == -1)
                    arr[cur] = i + 1
                else if (arr[cur] > i + 1)
                    arr[cur] = i + 1
            }
        }

        targets.forEach {
            var sum = 0
            for (i in it.indices) {
                var target = it[i] - 'A'

                if (arr[target] == -1) {
                    sum = -1
                    break
                }
                sum += arr[target]
            }
            answerList.add(sum)
        }
        answer = answerList.toIntArray()
        return answer
    }
}