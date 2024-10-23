class NM6(val n: Int, val m: Int, nums: List<Int>) {
    private val bw = System.`out`.bufferedWriter()

    private val sortedNums = nums.sorted()
    private val visit = BooleanArray(sortedNums.size) { false }

    private fun backtrack(curIdx: Int, result: List<Int>) {
        if (result.size == m) {
            result.forEach { bw.write("$it ") }
            bw.write("\n")
        }

        for (i in curIdx until n)
            if (!visit[i]) {
                visit[i] = true
                backtrack(i + 1, result + sortedNums[i])
                visit[i] = false
            }
    }

    fun printAnswer() {
        backtrack(0, emptyList())
        bw.flush()
        bw.close()
    }
}

fun main() {
    val br = System.`in`.bufferedReader()
    val (N, M) = br.readLine().split(' ').map { it.toInt() }
    val nums = br.readLine().split(' ').map { it.toInt() }

    NM6(N, M, nums).printAnswer()
}