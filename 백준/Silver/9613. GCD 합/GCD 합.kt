// 최대공약수 유클리드 호제법
fun gcd(a: Long, b: Long): Long {
    if (b == 0L) return a
    return gcd(b, a % b)
}

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    val T = br.readLine().toInt()
    repeat(T) {
        val nums = br.readLine().split(' ').map { it.toLong() }
        val N = nums[0].toInt()

        var ans = 0L
        for (i in 1..N)
            for (j in i + 1..N)
                ans += gcd(nums[i], nums[j])
        bw.write("$ans\n")
    }
    bw.flush()
    bw.close()
}