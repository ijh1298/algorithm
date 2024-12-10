fun main() {
    val br = System.`in`.bufferedReader()
    repeat(br.readLine().toInt()) {
        println(br.readLine().split(' ').sumOf { it.toInt() })
    }
}