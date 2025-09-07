val matrix: MutableList<IntArray> = MutableList(9) { intArrayOf() }
val rowUsed = Array(9) { BooleanArray(10) { false } }
val colUsed = Array(9) { BooleanArray(10) { false } }
val zoneUsed = Array(9) { BooleanArray(10) { false } }
var isFound: Boolean = false

fun printAnswer() {
    if (!isFound) {
        matrix.forEach {
            println(it.joinToString(""))
        }
        isFound = true
    }
}

fun backtrack(i: Int, j: Int) {
    if (isFound) {
        return
    }
    if (i == 9) {
        printAnswer()
        return
    }

    if (matrix[i][j] == 0) {
        val zoneIdx = i / 3 * 3 + j / 3
        for (number in 1..9) {
            if (rowUsed[i][number] || colUsed[j][number] || zoneUsed[zoneIdx][number]) {
                continue
            }
            matrix[i][j] = number
            rowUsed[i][number] = true
            colUsed[j][number] = true
            zoneUsed[zoneIdx][number] = true

            if (j == 8) {
                backtrack(i + 1, 0)
            } else {
                backtrack(i, j + 1)
            }
            if (isFound) return

            matrix[i][j] = 0
            rowUsed[i][number] = false
            colUsed[j][number] = false
            zoneUsed[zoneIdx][number] = false
        }
    } else {
        if (j == 8) {
            backtrack(i + 1, 0)
        } else {
            backtrack(i, j + 1)
        }
    }
}

fun main() {
    val br = System.`in`.bufferedReader()
    repeat(9) { index ->
        matrix[index] = br.readLine().map { it.digitToInt() }.toIntArray()
    }

    for (i in 0..8) {
        for (j in 0..8) {
            val zoneIdx = i / 3 * 3 + j / 3
            if (matrix[i][j] != 0) {
                val number = matrix[i][j]
                rowUsed[i][number] = true
                colUsed[j][number] = true
                zoneUsed[zoneIdx][number] = true
            }
        }
    }
    backtrack(0, 0)
}
