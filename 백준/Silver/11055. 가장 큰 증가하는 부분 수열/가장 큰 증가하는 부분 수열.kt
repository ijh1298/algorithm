import kotlin.math.max

fun main() {
    val br = System.`in`.bufferedReader()
    val N = br.readLine().toInt()
    val arr = br.readLine().split(" ").map { it.toInt() }
    var dp = MutableList(N) { i -> 1 }
    var sum = MutableList(N) { i -> arr[i] }

    for (i in 1..<N) {
        for (j in 0..<i) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i] + 1, dp[j] + 1)
                sum[i] = max(sum[i], sum[j] + arr[i])
            }
        }
    }
    var ans = 0
    for (i in 0..<N) {
        if (ans < sum[i])
            ans = sum[i]
    }
    print(ans)
}