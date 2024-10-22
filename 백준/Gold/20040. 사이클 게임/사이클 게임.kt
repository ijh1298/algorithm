val parent = MutableList(500001) { i -> i }

// 둘 중 작은 루트를 가진 수로 묶기
fun union(i: Int, j: Int) {
    val rootI = unionFind(i)
    val rootJ = unionFind(j)
    if (rootI < rootJ)
        parent[rootJ] = rootI
    else
        parent[rootI] = rootJ
}

// 유니온 파인드
fun unionFind(i: Int): Int {
    if (i == parent[i])
        return i

    val topParent = unionFind(parent[i])
    if (parent[i] != topParent)
        parent[i] = topParent
    return topParent
}

fun main() {
    val br = System.`in`.bufferedReader()
    val (n, m) = br.readLine().split(' ').map { it.toInt() }
    val input = mutableListOf<List<Int>>()
    repeat(m) {
        input += br.readLine().split(' ').map { it.toInt() }
    }

    // 유니온 파인드로 사이클 유무 확인
    var ans = 0
    var flag = false
    for (i in 0 until m) {
        ++ans
        val (u, v) = input[i]
        if (unionFind(u) == unionFind(v)) {
            flag = true
            break
        } else
            union(u, v)
    }
    // 출력
    if (!flag) ans = 0
    println(ans)
}