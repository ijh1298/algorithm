fun main() {
    val br = System.`in`.bufferedReader()
    val T = br.readLine().toInt()

    repeat (T) {
        var pairList : MutableList<Pair<Int, Int>> = mutableListOf()
        val N = br.readLine().toInt()

        for (i in 0..<N) {
            val (a, b) = br.readLine().split(" ").map { it.toInt() }
            pairList.add(Pair(a, b))
        }
        // 서류 점수를 기준으로 정렬
        pairList.sortWith(compareBy { it.first })

        var ans = 1
        var standard = pairList[0].second
        // 서류 점수 1등 지원자의 면접 순위보다 낮은 지원자들을 고르기
        for (i in 1..<N) {
            if (pairList[i].second < standard) {
                ans++
                // 더 잘 본 면접 순위라면 갱신
                standard = pairList[i].second
            }
        }
        println(ans)
    }
}