fun main() {
    val br = System.`in`.bufferedReader()
    val N = br.readLine().toInt()
    val nums = br.readLine().split(' ').map { it.toInt() }

    val dp = MutableList<Int>(N + 1) { 0 }

    nums.forEach { num ->
        // 바로 직전 수(-1)가 등장한 적 있으면 수열 길이 추가
        if (dp[num - 1] == 0)
            dp[num]++
        else
            dp[num] += dp[num - 1] + 1
    }

    // 처음부터 제대로 정렬된 수열을 제외한 수들을 맨 앞, 맨 뒤로 보내는 식으로 잘 정렬하면 됨(노트 참조)
    // 답 = 총 길이 - 가장 긴 연속 수열 길이
    println(N - dp.max())
}