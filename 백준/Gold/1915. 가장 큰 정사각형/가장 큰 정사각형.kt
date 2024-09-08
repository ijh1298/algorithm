fun main() {
    val br = System.`in`.bufferedReader()
    val (n, m) = br.readLine().split(' ').map { it.toInt() }
    val matrix = MutableList(n) { br.readLine() }

    val dp = List(n) { IntArray(m) { 0 } }
    var maxSize = 0

    for (i in 0 until n) {
        for (j in 0 until m) {
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0) {
                    // 첫 번째 행이나 열에서는 정사각형 크기가 1
                    dp[i][j] = 1
                } else {
                    // 현재 칸을 오른쪽 아래 꼭짓점으로 하는 정사각형의 최대 크기 계산
                    dp[i][j] = minOf(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1
                }
                // 최대 크기 갱신
                maxSize = maxOf(maxSize, dp[i][j])
            }
        }
    }

    // 최대 정사각형의 넓이 출력
    println(maxSize * maxSize)
}
