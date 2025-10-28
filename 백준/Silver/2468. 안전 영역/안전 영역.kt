var N = 1
lateinit var matrix: List<MutableList<Int>>
lateinit var visit: List<BooleanArray>

fun main() {
    // 입력
    val br = System.`in`.bufferedReader()
    N = br.readLine().toInt()
    matrix = List(N) {
        br.readLine().split(' ').map { it.toInt() }.toMutableList()
    }
    visit = List(N) { BooleanArray(N) { false } }

    var ans = 0
    var count = 0
    // h는 물에 잠길 현재 높이
    for (h in 0..100) {
        for (i in 0 until N) {
            for (j in 0 until N) {
                if (!visit[i][j] && matrix[i][j] > h) {
                    visit[i][j] = true
                    bfs(i, j, h)
                    count++
                }
            }
        }
        ans = maxOf(ans, count)
        count = 0
        initVisit()
    }

    println(ans)
}

fun bfs(i: Int, j: Int, h: Int) {
    val queue = ArrayDeque<Pair<Int, Int>>()
    queue.add(i to j)

    val dx = intArrayOf(0, 1, 0, -1)
    val dy = intArrayOf(1, 0, -1, 0)

    while (queue.isNotEmpty()) {
        val (x, y) = queue.removeFirst()

        for (i in 0..3) {
            val nextX = x + dx[i]
            val nextY = y + dy[i]

            if (nextX !in 0..<N || nextY !in 0..<N) continue

            if (!visit[nextX][nextY] && matrix[nextX][nextY] > h) {
                visit[nextX][nextY] = true
                queue.add(nextX to nextY)
            }
        }
    }
}

fun initVisit() {
    visit.forEach { array ->
        array.forEachIndexed { idx, _ ->
            array[idx] = false
        }
    }
}
