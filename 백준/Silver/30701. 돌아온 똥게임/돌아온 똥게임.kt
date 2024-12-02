fun main() {
    val br = System.`in`.bufferedReader()
    val (N, D) = br.readLine().split(' ').map { it.toInt() }

    // 입력
    val monsters = mutableListOf<Int>()
    val shields = mutableListOf<Int>()
    repeat(N) {
        val (type, power) = br.readLine().split(' ').map { it.toInt() }
        if (type == 1) monsters += power
        else shields += power
    }
    monsters.sort()
    shields.sort()

    // 그리디
    var stage = 0
    var curD = D.toLong()
    while (monsters.isNotEmpty()) {
        if (monsters.first() >= curD) {
            if (shields.isEmpty())
                break
            curD *= shields.removeFirst()
            stage++
            continue
        }
        curD += monsters.removeFirst()
        stage++
    }

    // 남은 방어구 사용
    for (s in shields)
        stage++

    println(stage)
}