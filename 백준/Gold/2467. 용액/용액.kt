import kotlin.math.abs

fun main() {
    val br = System.`in`.bufferedReader()
    val N = br.readLine().toInt()
    val liquid = br.readLine().split(' ').map { it.toInt() }

    var l = 0
    var r = 0
    var min = Int.MAX_VALUE

    fun binarySearch(pivot: Int, s: Int, e: Int) {
        if (s > e)
            return

        val mid = (s + e) / 2
        if (abs(pivot + liquid[mid]) <= abs(min)) {
            min = pivot + liquid[mid]
            l = pivot
            r = liquid[mid]
        }

        if (pivot + liquid[mid] < 0)
            binarySearch(pivot, mid + 1, e)
        else
            binarySearch(pivot, s, mid - 1)
    }

    // i번째 용액을 선택하고, 남은 용액을 이분 탐색하여 절대값의 최소를 찾기
    for (i in 0 until N - 1) {
        val liq = liquid[i]
        binarySearch(liq, i + 1, N - 1)
    }
    println("$l $r")
}