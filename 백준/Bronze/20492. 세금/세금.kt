fun main() {
    val n = System.`in`.bufferedReader().readLine().toInt()
    println("${(n * 0.78).toInt()} ${n - (n * 0.2 * 0.22).toInt()}")
}