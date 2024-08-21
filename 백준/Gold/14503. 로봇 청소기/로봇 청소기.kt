const val UP = 0
const val RIGHT = 1
const val DOWN = 2
const val LEFT = 3

fun main() {
    // 입력
    val br = System.`in`.bufferedReader()
    val (N, M) = br.readLine().split(' ').map { it.toInt() }
    var (r, c, d) = br.readLine().split(' ').map { it.toInt() }

    val matrix = Array(N) { IntArray(M) { _ -> 0 } }
    for (i in 0 until N) {
        matrix[i] = br.readLine().split(' ').map { it.toInt() }.toIntArray()
    }

    // 구현
    var ans = 0
    while (true) {
        // 현재 칸이 청소되지 않았으면 청소
        if (matrix[r][c] == 0) {
            matrix[r][c] = 2
            ans++
        }

        // 주변 칸 청소해야 하는지 검사
        var cnt = 0

        for (i in 0..3) {
            val dx = intArrayOf(1, 0, -1, 0)
            val dy = intArrayOf(0, 1, 0, -1)

            val nextR = r + dx[i]
            val nextC = c + dy[i]

            if (nextR == 0 || nextR == N - 1 || nextC == 0 || nextC == M - 1)
                continue

            if (matrix[nextR][nextC] == 0)
                cnt++
        }
        val clear = if (cnt == 0) true else false

        if (clear) {
            // 후진 가능하면 후진
            if (d == UP && r != N - 1 && matrix[r + 1][c] != 1) r++
            else if (d == RIGHT && c != 0 && matrix[r][c - 1] != 1) c--
            else if (d == DOWN && r != 0 && matrix[r - 1][c] != 1) r--
            else if (d == LEFT && c != M - 1 && matrix[r][c + 1] != 1) c++
            else
                break // 불가능하면 종료
        }
        // 청소 필요하면
        else {
            // 반 시계 방향 90도 회전
            if (d == 0)
                d = 3
            else
                d--

            // 앞이 청소되지 않았으면 전진
            if (d == UP && r != 0 && matrix[r - 1][c] != 1 && matrix[r - 1][c] == 0) r--
            else if (d == RIGHT && c != M - 1 && matrix[r][c + 1] != 1 && matrix[r][c + 1] == 0) c++
            else if (d == DOWN && r != N - 1 && matrix[r + 1][c] != 1 && matrix[r + 1][c] == 0) r++
            else if (d == LEFT && c != 0 && matrix[r][c - 1] != 1 && matrix[r][c - 1] == 0) c--
        }
    }
    // 출력
    println(ans)
}