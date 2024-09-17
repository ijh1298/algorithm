import java.util.PriorityQueue

fun main() {
    val br = System.`in`.bufferedReader()
    val (n, m) = br.readLine().split(' ').map { it.toInt() }
    val nums = br.readLine().split(' ').map { it.toLong() }

    val pq = PriorityQueue<Long>()
    nums.forEach { pq += it }

    repeat(m) {
        if (pq.size >= 2) {
            val first = pq.poll()
            val second = pq.poll()
            pq += first + second
            pq += first + second
        }
    }

    println(pq.sum())
}