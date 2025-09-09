fun main() {
    val br = System.`in`.bufferedReader()

    val n = br.readLine()
    val cranes = br.readLine().split(' ').map { it.toInt() }.sortedDescending()
    val m = br.readLine()
    val boxes = br.readLine().split(' ').map { it.toInt() }.sortedDescending()

    if (boxes.first() > cranes.first()) {
        println(-1)
        return
    }

    val leftBoxes = boxes.toMutableList()

    var count = 0

    while (leftBoxes.isNotEmpty()) {
        var boxIdx = 0
        for (crane in cranes) {
            while (boxIdx < leftBoxes.size) {
                if (leftBoxes[boxIdx] <= crane) {
                    leftBoxes.removeAt(boxIdx)
                    break
                }
                boxIdx++
            }
        }
        count++
    }
    println(count)
}
