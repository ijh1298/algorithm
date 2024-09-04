fun star(n: Int, type: Int, baseline: Int, push: Int, printList: MutableList<StringBuilder>) {
    if (n == 3) {
        val frontSpace = " ".repeat(push)

        if (type != 3) {
            for (i in 0..2)
                printList[baseline + i].append(frontSpace)
        }

        printList[baseline].append("  *   ")
        printList[baseline + 1].append(" * *  ")
        printList[baseline + 2].append("***** ")

        return
    }

    star(n / 2, 1, baseline, push + n / 2, printList)
    star(n / 2, 2, baseline + n / 2, push, printList)
    star(n / 2, 3, baseline + n / 2, 0, printList)

    // **하나의 재귀가 끝났을 때 backspace를 채우기**
    for (i in baseline until baseline + n) {
        val bottom = printList[baseline + n - 1].length
        printList[i].append(" ".repeat(bottom - printList[i].length))
    }
}

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    val n = br.readLine().toInt()

    val printList = MutableList(n) { StringBuilder() }

    star(n, 1, 0, 0, printList)

    for (i in printList) {
        bw.write("$i\n")
    }
    bw.flush()
    bw.close()
}
