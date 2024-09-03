import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()

    val n = br.readLine().toInt()

    val nList = mutableListOf<Int>()
    val pList = mutableListOf<Int>()

    repeat(n) {
        val input = br.readLine().toInt()
        if (input > 0) pList += input else nList += input
    }

    nList.sort() // 0 이하의 수는 오름차순 정렬
    pList.sortDescending() // 0 보다 큰 수는 내림차순 정렬

    var ans = 0

    val nLen = if (nList.size % 2 == 0) nList.size else nList.size - 1
    val pLen = if (pList.size % 2 == 0) pList.size else pList.size - 1

    // 음수 절댓값이 큰 음수부터 곱하기
    for (i in 0 until nLen step 2)
        ans += nList[i] * nList[i + 1]
    if (nList.size % 2 == 1)
        ans += nList.last()

    // 양수 큰 수부터 곱하기
    for (i in 0 until pLen step 2) {
        // 합이 곱보다 크면 묶지 않기
        if (pList[i] + pList[i + 1] > pList[i] * pList[i + 1]) 
            ans += pList[i] + pList[i + 1]
        else
            ans += pList[i] * pList[i + 1]
    }
    if (pList.size % 2 == 1)
        ans += pList.last()

    println(ans)
}