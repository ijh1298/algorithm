lateinit var numbers: List<Int>
lateinit var operators: IntArray
var minValue: Int = Int.MAX_VALUE
var maxValue: Int = Int.MIN_VALUE

fun backtrack(curIndex: Int, length: Int, result: Int) {
    if (curIndex == length) {
        minValue = minOf(minValue, result)
        maxValue = maxOf(maxValue, result)
        return
    }

    for (i in operators.indices) {
        if (operators[i] == 0) continue

        val curResult = when (i) {
            0 -> result + numbers[curIndex]
            1 -> result - numbers[curIndex]
            2 -> result * numbers[curIndex]
            else -> result / numbers[curIndex]
        }

        --operators[i]
        backtrack(curIndex + 1, length, curResult)
        ++operators[i]
    }
}

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readLine().toInt()

    numbers = br.readLine().split(' ').map { it.toInt() }
    operators = br.readLine().split(' ').map { it.toInt() }.toIntArray()
    backtrack(1, n, numbers.first())
    print("$maxValue\n$minValue")
}
