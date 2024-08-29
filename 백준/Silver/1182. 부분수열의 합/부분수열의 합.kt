fun main() {
    val br = System.`in`.bufferedReader()
    val (N, goal) = br.readLine().split(' ').map { it.toInt() }
    val list = br.readLine().split(' ').map { it.toInt() }

    // k: 현재 수열의 길이, curIdx: 현재 인덱스, sum: 지금까지 합
    var ans = 0
    fun backtrack(n: Int, k: Int, curIdx: Int, sum: Int, goal: Int) {
        if (n == k) {
            if (sum == goal)
                ans++
            return
        }

        for (i in curIdx until N) {
            backtrack(n, k + 1, i + 1, sum + list[i], goal)
        }
    }

    for (j in 1..N) {
        backtrack(j, 0, 0, 0, goal)
    }
    println(ans)
}