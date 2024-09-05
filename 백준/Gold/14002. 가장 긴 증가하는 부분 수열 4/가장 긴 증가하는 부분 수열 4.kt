fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    
    val n = br.readLine().toInt()
    val list = br.readLine().split(' ').map { it.toInt() }

    val dp = MutableList<Int>(n) { _ -> 0 }
    val prev = MutableList<Int>(n) { i -> i } // 이전 dp 갱신 때 index를 저장

    // dp[k] = dp[0] ~ dp[k -1] 중 가장 큰 값 + 1
    for (i in 1 until list.size)
        for (j in 0 until i)
            if (list[j] < list[i])
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1
                    prev[i] = j
                }

    var max = 0
    var maxIndex = 0
    for (i in dp.indices) {
        if (max < dp[i]) {
            max = dp[i]
            maxIndex = i
        }
    }

    val printList = mutableListOf<Int>()

    var cur = maxIndex
    while (true) {
        printList += list[cur]
        if (cur == prev[cur])
            break
        cur = prev[cur]
    }

    bw.write("${max + 1}\n")
    printList.reversed().forEach {
        bw.write("$it ")
    }
    bw.flush()
    bw.close()
}