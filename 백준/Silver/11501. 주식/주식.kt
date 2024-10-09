fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    val T = br.readLine().toInt()

    repeat(T) {
        val n = br.readLine().toInt()
        val stock = br.readLine().split(' ').map { it.toInt() }
        val maxPrice = MutableList<Int>(n) { 0 }
        maxPrice[n - 1] = stock[n - 1]

        for (i in n - 2 downTo 0) {
            maxPrice[i] = maxOf(maxPrice[i + 1], stock[i])
        }

        var ans = 0L
        for (i in 0 until n) {
            if (stock[i] < maxPrice[i])
                ans += maxPrice[i] - stock[i]
        }
        bw.write("$ans\n")
    }
    bw.flush()
}