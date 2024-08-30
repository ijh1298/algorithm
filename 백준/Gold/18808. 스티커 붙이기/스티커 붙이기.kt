val paper = Array(41) { BooleanArray(41) }

// 스티커 회전 함수
fun rotate(sticker: Array<IntArray>, type: Int): Array<IntArray> {
    val r = sticker.size
    val c = sticker[0].size

    val arr = if (type == 2) Array(r) { IntArray(c) } else Array(c) { IntArray(r) }
    // 90도
    if (type == 1) {
        for (i in 0 until r)
            for (j in 0 until c)
                arr[j][r - 1 - i] = sticker[i][j]
    }
    // 180도
    else if (type == 2) {
        for (i in 0 until r)
            for (j in 0 until c)
                arr[r - 1 - i][c - 1 - j] = sticker[i][j]
    }
    // 270도
    else {
        for (i in 0 until r)
            for (j in 0 until c)
                arr[c - 1 - j][i] = sticker[i][j]
    }
    return arr
}

// stick(스티커, 현재 focus할 모눈종이의 좌상단 좌표) : 스티커 붙이기 함수
fun stick(sticker: Array<IntArray>, x: Int, y: Int): Boolean {
    val r = sticker.size
    val c = sticker[0].size

    for (i in 0 until r)
        for (j in 0 until c)
        // 붙일 수 없으면
            if (paper[x + i][y + j] && sticker[i][j] == 1)
                return false

    for (i in 0 until r)
        for (j in 0 until c)
        // 붙일 수 있으면 paper 갱신
            if (!paper[x + i][y + j] && sticker[i][j] == 1)
                paper[x + i][y + j] = true

    return true
}

// 확인 함수
fun check(sticker: Array<IntArray>, N: Int, M: Int) {
    var rotationNum = 0 // 몇 번 회전했는지
    var cur = sticker

    while (rotationNum < 4) {
        // 현재 스티커의 가로, 세로 길이
        val r = cur.size
        val c = cur[0].size

        for (i in 0..N - r)
            for (j in 0..M - c)
                // 스티커 붙으면 return
                if (stick(cur, i, j))
                    return

        // 안 붙으면 회전
        if (++rotationNum < 4)
            cur = rotate(sticker, rotationNum)
    }
}

fun main() {
    val br = System.`in`.bufferedReader()
    val (N, M, K) = br.readLine().split(' ').map { it.toInt() }

    repeat(K) {
        val (r, c) = br.readLine().split(' ').map { it.toInt() }
        val sticker = Array<IntArray>(r) { _ -> intArrayOf() }
        for (i in 0 until r)
            sticker[i] = br.readLine().split(' ').map { it.toInt() }.toIntArray()

        // 시뮬레이션
        check(sticker, N, M)
    }

    var ans = 0
    paper.forEach { row ->
        row.forEach {
            if (it) ans++
        }
    }
    println(ans)
}