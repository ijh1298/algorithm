class Solution {
    fun solution(info: Array<IntArray>, n: Int, m: Int): Int { 
        var mCap = m
        
        val items = info.sortedByDescending { it[0].toDouble() / it[1] }
        val itemsAfterB = mutableListOf<IntArray>()
        items.forEach {
            val (A, B) = it
            if (B < mCap) {
                mCap -= B
            } else {
                itemsAfterB += it
            }
        }
        
        // 남은 것을 A가 처리 가능한지 확인
        val left = itemsAfterB.map { it[0] }.sum()
        
        println(left)
        
        if (left >= n)
            return -1
        return left
    }
}

// 1. A 도둑이 모든 것을 훔쳤다고 가정, 훔친 리스트를 A 흔적이 제일 큰 순으로 정렬한다.
// 2. A 흔적이 제일 큰 것부터 차례대로 없앤다. B 도둑이 훔칠 수 있는 흔적이 0이 될 때까지 반복한다.
// 3. 남은 리스트가 A 도둑이 훔칠 수 있는 흔적보다 크면 -1, 작으면 그 값을 출력한다.