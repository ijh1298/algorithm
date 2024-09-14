fun main() {
    val br = System.`in`.bufferedReader()
    val (N, S) = br.readLine().split(' ').map { it.toInt() }
    val list = br.readLine().split(' ').map { it.toInt() }
    val nums = listOf(0) + list // 편의를 위해 시작을 0으로 설정

    // 누적합 List 생성
    val accumulatedNums = mutableListOf(0)
    for (i in 1..N) {
        accumulatedNums += accumulatedNums[i - 1] + nums[i]
    }

    // 투포인터로 체크
    var s = 1
    var e = 1
    var ans = N + 1
    while (s <= N && e <= N) {
        val cur = accumulatedNums[e] - accumulatedNums[s - 1]

        if (cur >= S) {
            ans = minOf(ans, e - s + 1)
            s++
        } else {
            e++
        }
    }

    if (ans == N + 1) println(0)
    else println(ans)
}