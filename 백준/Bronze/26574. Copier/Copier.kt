fun main() {
    val br = System.`in`.bufferedReader()
    val N = br.readLine().toInt()
    repeat(N) {
        val temp = br.readLine().toInt()
        println("$temp $temp")
    }
}