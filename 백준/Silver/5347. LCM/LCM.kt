fun gcd(a: Long, b: Long): Long {
    if (b == 0L) return a
    return gcd(b, a % b)
}


fun lcm(a: Long, b: Long): Long {
    return a * b / gcd(a, b)
}

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    val N = br.readLine().toInt()
    repeat(N) {
        val (a, b) = br.readLine().split(' ').map { it.toLong() }
        bw.write("${lcm(a, b)}\n")
    }
    bw.flush()
    bw.close()
}