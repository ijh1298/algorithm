fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()

    val difficulty = MutableList<Int>(100001) { _ -> 0 }
    val ss = sortedSetOf<Int>(compareByDescending<Int> { difficulty[it] }.thenByDescending { it })

    val N = br.readLine().toInt()
    repeat(N) {
        val (num, d) = br.readLine().split(' ').map { it.toInt() }
        difficulty[num] = d
        ss.add(num)
    }

    val P = br.readLine().toInt()
    repeat(P) {
        val line = br.readLine().split(' ').map { it.toString() }
        val op = line[0]
        val num = line[1].toInt()
        if (op == "add") {
            val d = line[2].toInt()
            difficulty[num] = d
            ss.add(num)
        }
        else if (op == "recommend") {
            if (num == 1)
                bw.write("${ss.first()}\n")
            else
                bw.write("${ss.last()}\n")
        }
        else { // solved
            ss.remove(num)
        }
    }
    bw.flush()
    bw.close()
}