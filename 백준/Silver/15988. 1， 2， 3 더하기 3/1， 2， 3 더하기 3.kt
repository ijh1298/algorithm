fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    val N = br.readLine().toInt()

    val dp = MutableList(1000001) { 0 }
    dp[1] = 1
    dp[2] = 2
    dp[3] = 4

    for (i in 4..1000000)
        dp[i] = ((dp[i - 3] + dp[i - 2]) % 1000000009 + dp[i - 1]) % 1000000009

    repeat(N) {
        val input = br.readLine().toInt()
        bw.write("${dp[input]}\n")
    }
    bw.flush()
}