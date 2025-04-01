var n: Int = 0
lateinit var forest: List<List<Int>>
lateinit var dp: List<MutableList<Int>>

val dx = listOf(0, 1, 0, -1)
val dy = listOf(1, 0, -1, 0)

fun dfs(row: Int, col: Int) {
    for (i in 0..3) {
        val nextRow = row + dx[i]
        val nextCol = col + dy[i]

        if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= n)
            continue

        if (forest[nextRow][nextCol] > forest[row][col]) {
            if (dp[nextRow][nextCol] == 1) {
                dfs(nextRow, nextCol)
            }
            dp[row][col] = maxOf(dp[row][col], dp[nextRow][nextCol] + 1)
        }
    }
}

fun main() {
    val br = System.`in`.bufferedReader()
    n = br.readLine().toInt()
    forest = List(n) { br.readLine().split(' ').map { it.toInt() } }
    dp = List(n) { MutableList(n) { 1 } }

    for (row in 0..<n) {
        for (col in 0..<n) {
            dfs(row, col)
        }
    }
    println(dp.maxOf { it.max() })
}