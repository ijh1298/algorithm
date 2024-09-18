val bW = System.`out`.bufferedWriter()

fun bt(n: Int, m: Int, nums: List<Int>) {
    if (m == nums.size) {
        nums.forEach {
            bW.write("$it ")
        }
        bW.newLine()
        return
    }

    for (i in 1..n) {
        bt(n, m, nums + i)
    }
}

fun main() {
    val (n, m) = System.`in`.bufferedReader().readLine().split(' ').map { it.toInt() }
    bt(n, m, listOf())
    bW.flush()
}