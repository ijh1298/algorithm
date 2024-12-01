val matrix = mutableListOf<List<Int>>()
val numbersFrequency = MutableList<Int>(3) { 0 }

fun recursive(size: Int, row: Int, col: Int): Int {
    if (size == 1)
        return matrix[row][col]

    val recurs = listOf(
        recursive(size / 3, row, col),
        recursive(size / 3, row, col + size / 3),
        recursive(size / 3, row, col + size / 3 * 2),
        recursive(size / 3, row + size / 3, col),
        recursive(size / 3, row + size / 3, col + size / 3),
        recursive(size / 3, row + size / 3, col + size / 3 * 2),
        recursive(size / 3, row + size / 3 * 2, col),
        recursive(size / 3, row + size / 3 * 2, col + size / 3),
        recursive(size / 3, row + size / 3 * 2, col + size / 3 * 2)
    )

    if (recurs.all { it == 0 })
        return 0
    if (recurs.all { it == -1 })
        return -1
    if (recurs.all { it == 1 })
        return 1

    val papers = recurs.filter { it in (-1..1) }
    papers.forEach {
        numbersFrequency[it + 1]++ // numbersFrequency[0] : -1의 개수, [1] : 0의 개수, [2] : 1의 개수
    }
    return -10
}

fun main() {
    val br = System.`in`.bufferedReader()
    val N = br.readLine().toInt()

    repeat(N) { matrix += br.readLine().split(' ').map { it.toInt() } }
    val result = recursive(N, 0, 0)
    if (result != -10)
        numbersFrequency[result + 1]++

    for (i in 0.. 2)
        println(numbersFrequency[i])
}