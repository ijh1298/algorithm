fun main() {
    val br = System.`in`.bufferedReader()
    while (true) {
        val (first, second) = br.readLine().split(' ').map { it.toInt() }
        if (first == 0 && second == 0) break
        if (first > second) println("Yes")
        else println("No")
    }
}