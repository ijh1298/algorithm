import kotlin.math.abs

fun main() {
    val br = System.`in`.bufferedReader()
    val (N, L, R) = br.readLine().split(" ").map { it.toInt() }
    val matrix = Array<IntArray>(N) { intArrayOf() }
    val matrixChanged = Array<IntArray>(N) { intArrayOf() }
    // information : Pair(연결된 나라들의 인구수 총합, 연결된 나라 수) 저장
    val information = Array(N) { Array<Pair<Int, Int>>(N) { _ -> Pair(0, 0)} }
    val visit = Array(N) { BooleanArray(N) } // BFS용 방문 체크 배열

    for (i in 0 until N) {
        matrix[i] = br.readLine().split(" ").map { it.toInt() }.toIntArray()
        matrixChanged[i] = matrix[i].clone()
    }
    for (i in matrix.indices) {
        for (j in matrix[i].indices) {
            information[i][j] = Pair(matrix[i][j], 1)
        }
    }

    data class Info (val row: Int, val col: Int, val root: Pair<Int, Int>)

    val queue = ArrayDeque<Info>()

    fun bfs(searchOrSpread : Boolean) {
        while (!queue.isEmpty()) {
            val (row, col, root) = queue.removeFirst()
            val dir = arrayOf(intArrayOf(-1, 0, 1, 0), intArrayOf(0, 1, 0, -1))

            for (i in 0..3) {
                val nextRow = row + dir[0][i]
                val nextCol = col + dir[1][i]

                if (nextRow < 0 || nextRow > N - 1 || nextCol < 0 || nextCol > N - 1)
                    continue

                if (!searchOrSpread) { // Search
                    val diff = abs(matrix[row][col] - matrix[nextRow][nextCol])
                    val valid = if (diff in L..R) true else false   // L 이상 R 이하 만큼 차이가 나는지

                    if (valid && !visit[nextRow][nextCol]) {
                        visit[nextRow][nextCol] = true
                        val peopleNum = information[root.first][root.second].first + matrix[nextRow][nextCol]
                        val connectionNum = information[root.first][root.second].second + 1
                        information[root.first][root.second] = Pair(peopleNum, connectionNum)
                        queue.addLast(Info(nextRow, nextCol, root))
                    }
                }
                else { // Spread
                    val (peopleNum, connectionNum) = information[root.first][root.second]
                    val spreadValue = peopleNum / connectionNum

                    val diff = abs(matrix[row][col] - matrix[nextRow][nextCol])
                    val valid = if (diff in L..R) true else false   // L 이상 R 이하 만큼 차이가 나는지

                    if (valid && !visit[nextRow][nextCol]) {
                        visit[nextRow][nextCol] = true
                        matrixChanged[nextRow][nextCol] = spreadValue
                        queue.addLast(Info(nextRow, nextCol, root))
                    }
                }
            }
        }
    }
    var answer = 0
    // 로직
    while (true) {
        // 초기화
        visit.forEachIndexed { i, row ->
            row.forEachIndexed { j, one ->
                visit[i][j] = false
            }
        }
        // 1. matrix[0][0]부터 BFS로 국경이 열리는 나라 모두 탐색
        matrix.forEachIndexed { i, row ->
            row.forEachIndexed { j, one ->
                if (!visit[i][j]) {
                    queue.add(Info(i, j, Pair(i, j)))
                    visit[i][j] = true
                    bfs(false)
                }
            }
        }
        var exist = false
        for (i in information.indices) {
            if (exist) break
            for (j in information[i].indices) {
                if (information[i][j].second != 1) {
                    exist = true
                    answer++
                    break
                }
            }
        }
        if (!exist) break
        // 초기화
        visit.forEachIndexed { i, row ->
            row.forEachIndexed { j, one ->
                visit[i][j] = false
            }
        }
        // 2. matrix[0][0]부터 BFS로 국경이 열리는 나라 모두 인원 분배
        matrix.forEachIndexed { i, row ->
            row.forEachIndexed { j, one ->
                if (!visit[i][j]) {
                    queue.add(Info(i, j, Pair(i, j)))
                    visit[i][j] = true
                    matrixChanged[i][j] = information[i][j].first / information[i][j].second
                    bfs(true)
                }
            }
        }
        // matrix 재설정
        for (i in matrix.indices) {
            matrix[i] = matrixChanged[i].clone()
        }
        // information 초기화
        information.forEachIndexed { i, row ->
            row.forEachIndexed { j, one ->
                information[i][j] = Pair(matrix[i][j], 1)
            }
        }
    }
    print(answer)
}