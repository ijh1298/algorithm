import java.util.*

val PQ = PriorityQueue<Long>()

fun solve(N: Int) {
    var cnt = 0
    while (!PQ.isEmpty() && cnt <= 1000000) {
        val cur = PQ.poll()
        if (cnt == N) {
            println(cur)
            return
        }

        val s = getFirstNumber(cur) + 1
        for (i in s..9)
            PQ.add("$i$cur".toLong())

        cnt++
    }
    println(-1)
}

fun getFirstNumber(num: Long): Long {
    if (num == 0L)
        return 0

    var n = num
    while (n >= 10) { n /= 10 }
    return n
}

fun main() {
    val br = System.`in`.bufferedReader()
    val N = br.readLine().toInt()

    for (i in 0..9) PQ.add(i.toLong())

    solve(N)
}