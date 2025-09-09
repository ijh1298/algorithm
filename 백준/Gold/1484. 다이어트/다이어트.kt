fun main() {
    val g = readln().toInt()

    var current = 2
    var expected = 1

    val answers = mutableListOf<Int>()
    while (true) {
        if (current == expected) {
            break
        }
        val result = current * current - expected * expected
        when {
            result == g -> {
                answers += current
                ++current
            }
            result < g -> ++current
            result > g -> ++expected
        }
    }

    val bw = System.`out`.bufferedWriter()
    if (answers.isEmpty()) {
        bw.write("-1\n")
    } else {
        answers.forEach {
            bw.write("$it\n")
        }
    }
    bw.close()
}
