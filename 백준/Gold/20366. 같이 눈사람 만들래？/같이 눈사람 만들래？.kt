fun main() {
    val br = System.`in`.bufferedReader()
    val N = br.readLine().toInt()
    val snowball = br.readLine().split(' ').map { it.toInt() }

    val height = mutableListOf<Triple<Int, Int, Int>>()
    for (i in 0 until N)
        for (j in i + 1 until N) {
            height += Triple(snowball[i] + snowball[j], i, j)
        }
    height.sortBy { it.first } // 눈사람 높이 오름차순 정렬

    var min = Int.MAX_VALUE
    for (i in 1 until height.size) {
        val set = mutableSetOf<Int>()
        set.add(height[i].second)
        set.add(height[i].third)
        set.add(height[i - 1].second)
        set.add(height[i - 1].third)

        if (set.size != 4) continue // 같은 눈덩이를 사용했다면

        min = minOf(min, height[i].first - height[i - 1].first)
    }
    println(min)
}