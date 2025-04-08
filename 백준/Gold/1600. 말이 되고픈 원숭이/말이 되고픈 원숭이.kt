data class Move(
    val row: Int,
    val col: Int,
    val depth: Int,
    val jump: Int,
)

val directions = listOf(-1 to 0, 0 to 1, 1 to 0, 0 to -1)
val jumpDirections = listOf(-2 to -1, -1 to -2, 1 to -2, 2 to -1, -2 to 1, -1 to 2, 2 to 1, 1 to 2)

fun bfs(
    h: Int,
    w: Int,
    k: Int,
    matrix: List<List<Int>>,
    visit: List<List<BooleanArray>>,
): Int {
    val queue = ArrayDeque<Move>()
    visit[0][0][0] = true
    queue.add(Move(0, 0, 0, k))

    var ans = Int.MAX_VALUE

    while (queue.isNotEmpty()) {
        val (row, col, depth, jump) = queue.removeFirst()
        val jumpCount = k - jump

        if (row == h - 1 && col == w - 1) {
            ans = minOf(ans, depth)
        }

        for (dir in directions) {
            val nextRow = row + dir.first
            val nextCol = col + dir.second

            if (isOutOfMatrix(h, w, nextRow, nextCol) || matrix[nextRow][nextCol] == 1 || visit[jumpCount][nextRow][nextCol]) {
                continue
            }
            visit[jumpCount][nextRow][nextCol] = true
            queue.add(Move(nextRow, nextCol, depth + 1, jump))
        }

        if (jump > 0) {
            for (dir in jumpDirections) {
                val nextRow = row + dir.first
                val nextCol = col + dir.second

                if (isOutOfMatrix(h, w, nextRow, nextCol) || matrix[nextRow][nextCol] == 1 || visit[jumpCount + 1][nextRow][nextCol]) {
                    continue
                }
                visit[jumpCount + 1][nextRow][nextCol] = true
                queue.add(Move(nextRow, nextCol, depth + 1, jump - 1))
            }
        }
    }
    if (ans == Int.MAX_VALUE) {
        return -1
    }
    return ans
}

fun isOutOfMatrix(
    h: Int,
    w: Int,
    row: Int,
    col: Int,
): Boolean = row < 0 || row >= h || col < 0 || col >= w

fun main() {
    val br = System.`in`.bufferedReader()
    val K = br.readLine().toInt()
    val (M, N) = br.readLine().split(' ').map { it.toInt() }
    val matrix: List<List<Int>> = List(N) { br.readLine().split(' ').map { it.toInt() } }
    val visit: List<List<BooleanArray>> = List(K + 1) { List(N) { BooleanArray(M) { false } } }

    println(bfs(N, M, K, matrix, visit))
}
