fun main() {
    val br = System.`in`.bufferedReader()
    val ml = mutableListOf<Int>()
    repeat(5) {
        val score = br.readLine().toInt()
        ml += if (score < 40) 40 else score
    }
    println(ml.average().toInt())
}