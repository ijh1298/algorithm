fun main() {
    val br = System.`in`.bufferedReader()
    val (N, M) = br.readLine().split(' ').map { it.toInt() }

    val matrix = List(N) {
        br.readLine().split(' ').map { it.toLong() }
    }

    var ans = 0L
    for (i in 1..<N - 1) {
        for (j in 1..<M - 1) {
            ans += minOf(matrix[i - 1][j], matrix[i + 1][j], matrix[i][j - 1], matrix[i][j + 1], maxOf(matrix[i][j] - 1, 0))
        }
    }
    println(ans)
}