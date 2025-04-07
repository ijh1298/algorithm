fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readLine().toInt()
    val numbers = MutableList(n) { br.readLine().toInt() }

    var ans = 0
    for (i in n - 2 downTo 0) {
        if (numbers[i + 1] <= numbers[i] && numbers[i + 1] > 0) {
            ans += numbers[i] - (numbers[i + 1] - 1)
            numbers[i] -= numbers[i] - (numbers[i + 1] - 1)
        }
    }
    println(ans)
}