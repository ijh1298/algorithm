// 삼성 노트 그림 참조
// 0 뒤에는 0, 1이 올 수 있고, 1 뒤에는 0 만 올 수 있다.
// 점화식 dp[n] = dp[n-1] + dp[n-2]
fun main() {
    val br = System.`in`.bufferedReader()
    val N = br.readLine().toInt()
    var dp = Array<Long>(91) { i -> 0 }
    dp[1] = 1
    dp[2] = 1

    for (i in 3..N)
        dp[i] = dp[i - 1] + dp[i - 2]

    print(dp[N])
}