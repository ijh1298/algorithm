fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()

    val N = br.readLine().toInt()
    val input = br.readLine().split(' ').map { it.toInt() }
    val ans = MutableList(N) { 0 }

    val arrayDeque = ArrayDeque<Pair<Int, Int>>() // Pair(value, index)

    for (i in 0 until N) {
        while (arrayDeque.isNotEmpty() && arrayDeque.last().first <= input[i]) {
            arrayDeque.removeLast()
        }

        if (arrayDeque.isNotEmpty()) {
            ans[i] = arrayDeque.last().second + 1
        }

        arrayDeque.addLast(input[i] to i)
    }

    ans.forEach {
        bw.write("$it ")
    }
    bw.flush()
    bw.close()
}
