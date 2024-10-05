fun main() {
    val br = System.`in`.bufferedReader()
    val (N, K) = br.readLine().split(' ').map { it.toInt() }

    val ba = BooleanArray(N + 1) { false }

    var cnt = 0

    var curPrime = 2

    while (true) {
        for (i in 2..N)
            if (!ba[i]) {
                curPrime = i
                break
            }

        for (i in curPrime..N step curPrime)
            if (!ba[i]) {
                ba[i] = true
                if (++cnt == K) {
                    println(i)
                    return
                }
            }
    }
}