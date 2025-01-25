val br = System.`in`.bufferedReader()

var n = 0
lateinit var numbers: List<Int>
var x = 0

fun input() {
    n = br.readLine().toInt()
    numbers = br.readLine().split(' ').map { it.toInt() }.sorted()
    x = br.readLine().toInt()
}

fun solve(): Int {
    var ans = 0
    var a = 0
    var b = n - 1

    while (a < b) { // 투포인터
        if (numbers[a] + numbers[b] == x) {
            ++ans
            ++a
        } else if (numbers[a] + numbers[b] > x) {
            --b
        } else
            ++a
    }
    return ans
}

fun main() {
    input()
    println(solve())
}
