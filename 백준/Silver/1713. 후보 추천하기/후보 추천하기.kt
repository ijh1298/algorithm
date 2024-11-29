data class Student(val number: Int, var recommendNumber: Int)

val nums = mutableListOf<Student>()

fun recommend(limit: Int, n: Int) {
    nums.forEach {
        if (it.number == n) {
            it.recommendNumber++
            return
        }
    }

    // 비어있는 사진 틀이 없는 경우
    if (nums.size == limit) {
        var minValue = Int.MAX_VALUE
        var minIdx = 0
        nums.forEachIndexed { idx, num ->
            if (minValue > num.recommendNumber) {
                minValue = num.recommendNumber
                minIdx = idx
            }
        }
        nums.removeAt(minIdx)
    }

    // 공간이 생긴 경우 추가
    nums.add(Student(n, 1))
}

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    val limit = br.readLine().toInt()
    val N = br.readLine().toInt()
    val input = br.readLine().split(' ').map { it.toInt() }

    input.forEach {
        recommend(limit, it)
    }

    nums.sortBy { it.number }
    nums.forEach { bw.write("${it.number} ") }
    bw.flush()
    bw.close()
}