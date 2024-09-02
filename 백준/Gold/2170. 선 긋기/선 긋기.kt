import kotlin.math.max
import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readLine().toInt()

    val list = mutableListOf<Pair<Int, Int>>()
    repeat(n) {
        val (start, end) = br.readLine().split(' ').map { it.toInt() }
        list.add(start to end)
    }
    // 시작 점이 빠른 순, 같다면 종료 점이 빠른 순 정렬
    list.sortWith(compareBy<Pair<Int, Int>> { it.first }.thenBy { it.second })
    var ans = 0
    var prevS = 0
    var prevE = 0

    for (line in list) {
        val (curS, curE) = line

        // 범위 안에 있다면 직선을 연장
        if (curS in prevS..prevE || curE in prevS..prevE) {
            prevS = min(prevS, curS)
            prevE = max(prevE, curE)
        }
        // 범위 벗어나면 ans에 선 길이 추가
        else {
            ans += prevE - prevS
            prevS = curS
            prevE = curE
        }
    }
    ans += prevE - prevS
    println(ans)
}