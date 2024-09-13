fun main() {
    val br = System.`in`.bufferedReader()
    val (N, K) = br.readLine().split(' ').map { it.toInt() }

    val indexes = List<MutableList<Int>>(101) { mutableListOf() }
    val list = br.readLine().split(' ').map { it.toInt() }
    // 등장하는 순서를 담기
    list.forEachIndexed { index, i ->
        indexes[i] += index
    }

    var ans = 0
    val multiTap = mutableSetOf<Int>()
    for (i in list) {
        if (multiTap.size < N || multiTap.contains(i)) {
            multiTap += i
            indexes[i].removeFirst()
        } else {
            // <현재 꽂혀 있는 제품 이름, 다음 가장 빨리 등장하는 순서>
            val nextOrderList: List<Pair<Int, Int>> = multiTap.map { it to (indexes[it].firstOrNull() ?: Int.MAX_VALUE) }

            var max = -2
            var mostFarIndex = 0 // 현재 꽂힌 제품 중 뺀 후에 가장 나중에 등장하는 제품 이름
            nextOrderList.forEach { order ->
                if (max < order.second) {
                    max = order.second
                    mostFarIndex = order.first
                }
            }

            multiTap -= mostFarIndex
            multiTap += i
            indexes[i].removeFirst()
            ans++
        }
    }
    println(ans)
}