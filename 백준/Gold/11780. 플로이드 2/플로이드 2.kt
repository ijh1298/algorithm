fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    val N = br.readLine().toInt()
    val M = br.readLine().toInt()

    // 거리 초기화
    val dist = List(N + 1) { MutableList(N + 1) { Int.MAX_VALUE } }
    for (i in 1..N) {
        dist[i][i] = 0 // 자기 자신은 0
    }
    // next : 경로 저장 배열
    val next = List(N + 1) { MutableList(N + 1) { _ -> 0 } }

    // 입력
    repeat(M) {
        val (u, v, w) = br.readLine().split(' ').map { it.toInt() }
        dist[u][v] = minOf(w, dist[u][v])
        next[u][v] = v
    }

    // 플로이드 워셜 구현
    for (k in 1..N) {
        for (i in 1..N) {
            for (j in 1..N) {
                if (dist[i][k] != Int.MAX_VALUE && dist[k][j] != Int.MAX_VALUE && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j]
                    next[i][j] = next[i][k]
                }
            }
        }
    }

    // 플로이드 워셜로 만들어진 최단 거리 table 출력
    for (i in 1..N) {
        for (j in 1..N) {
            if (dist[i][j] == Int.MAX_VALUE)
                bw.write("0 ")
            else
                bw.write("${dist[i][j]} ")
        }
        bw.newLine()
    }

    // i번 도시에서 j번 도시까지 거쳐가는 길이, 경로 출력
    for (i in 1..N) {
        for (j in 1..N) {
            val route = mutableListOf<Int>()

            var cur = next[i][j]
            if (cur == 0) {
                bw.write("0\n")
                continue
            }

            // j에 도착할 때까지 cur 갱신
            route += i
            while (cur != j) {
                route += cur
                cur = next[cur][j]
            }
            route += j

            bw.write("${route.size} ")
            route.forEach {
                bw.write("$it ")
            }
            bw.newLine()
        }
    }
    bw.flush()
    bw.close()
}
