fun main() {
    val br = System.`in`.bufferedReader()
    val (N, M) = br.readLine().split(' ').map { it.toInt() }
    val nums = mutableListOf<Int>()
    repeat(N) {
        nums += br.readLine().toInt()
    }
    nums.sort()

    var min = Int.MAX_VALUE
    var s = 0
    var e = 0
    do {
        if (nums[e] - nums[s] < M) {
            e++
        } else {
            min = minOf(min, nums[e] - nums[s])
            s++
        }
    } while (s < N && e < N)

    println(min)
}