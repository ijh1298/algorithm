fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    val n = br.readLine().toInt()

    val dp = IntArray(n + 1)
    val prev = IntArray(n + 1)

    // DP로 풀면서 이전 경로를 저장
    for (i in 1..n) {
        // 1 더하기
        if (i + 1 <= n && (dp[i + 1] == 0 || (dp[i + 1] != 0 && dp[i] + 1 < dp[i + 1]))) {
            dp[i + 1] = dp[i] + 1
            prev[i + 1] = i
        }
        // 2 곱하기
        if (i * 2 <= n && (dp[i * 2] == 0 || (dp[i * 2] != 0 && dp[i] + 1 < dp[i * 2]))) {
            dp[i * 2] = dp[i] + 1
            prev[i * 2] = i
        }
        // 3 곱하기
        if (i * 3 <= n && (dp[i * 3] == 0 || (dp[i * 3] != 0 && dp[i] + 1 < dp[i * 3]))) {
            dp[i * 3] = dp[i] + 1
            prev[i * 3] = i
        }
    }
    // 출력
    var cur = n
    bw.write("${dp[cur]}\n$cur ")
    while (cur != 1) {
        bw.write("${prev[cur]} ")
        cur = prev[cur]
    }
    bw.flush()
    bw.close()
}