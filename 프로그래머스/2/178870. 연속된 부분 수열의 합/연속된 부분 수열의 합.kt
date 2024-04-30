class Solution {
    fun solution(sequence: IntArray, k: Int): IntArray {
        var answer: IntArray = intArrayOf()
    var sumArray = sequence.copyOf()

    val r = sumArray.size
    var len = Int.MAX_VALUE

    for (i in 1..r - 1)
        sumArray[i] += sumArray[i - 1]

    // 투 포인터
    var s = 0
    var e = 0
    var cur = 0
    // 두 포인터가 모두 끝 지점에 갈 때까지
    while (s != r && e != r) {
        if (s == 0)
            cur = sumArray[e]
        else
            cur = sumArray[e] - sumArray[s - 1]

        if (cur == k && len > e - s + 1) {
            answer = intArrayOf(s, e)
            len = e - s + 1
        }
        else if (cur < k)
            e++
        else
            s++
    }
        return answer
    }
}