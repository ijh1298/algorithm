val br = System.`in`.bufferedReader()
val bw = System.`out`.bufferedWriter()

val printList = mutableListOf<Int>()
val used = BooleanArray(9)

fun bt(n: Int, m: Int) {
    // m == 0 일 때 모두 출력
    if (m == 0) {
        printList.forEach {
            bw.write("$it ")
        }
        bw.newLine()
        return
    }

    for (i in 1..n) {
        if (!used[i]) {
            used[i] = true
            printList.add(i)
            bt(n, m - 1)

            used[i] = false
            printList.removeLast()
        }
    }
}

fun main() {
    val (n, m) = br.readLine().split(' ').map { it.toInt() }
    bt(n, m)
    bw.flush()
    bw.close()
}