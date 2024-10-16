import java.util.PriorityQueue

fun main() {
    val br = System.`in`.bufferedReader()
    val N = br.readLine().toInt()

    // 입력
    val homeworks = mutableListOf<Pair<Int, Int>>()
    repeat(N) {
        val (deadline, value) = br.readLine().split(' ').map { it.toInt() }
        homeworks += deadline to value
    }

    // deadline, value 오름차순 정렬
    homeworks.sortBy { it.first }

    // 최소힙 선언
    val pq = PriorityQueue<Int>()

    // 최소힙에 value를 넣으면서, pq size > deadline이 되는 경우 사이즈 조절
    homeworks.forEach { (deadline, value) ->
        pq.add(value)
        if (pq.size > deadline)
            pq.poll()
    }

    // 최소힙의 sum 출력
    println(pq.sum())

    return
}