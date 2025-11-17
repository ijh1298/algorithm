class Solution {
    lateinit var cards: List<Int>
    val parent = IntArray(101) { 0 }
    val counts = IntArray(101) { 0 }
    
    fun solution(c: IntArray): Int {
        cards = listOf(0) + c.toList()
        
        var max = 1
        cards.forEach { max = maxOf(max, it) }
        
        // union 생성
        for (i in 1..max) {
            visit(i, i)
        }
        
        // union 크기 측정
        parent.forEach { if (it != 0) counts[it]++ }

        // 1등, 2등 크기 구하기
        val order = counts.filter { it != 0 }.sortedDescending()
        
        if (order.size <= 1) {
            return 0
        }
        return order[0] * order[1]
    }
    
    fun visit(startIdx: Int, idx: Int) {
        val card = cards[idx]
        if (parent[card] == 0) {
            parent[card] = cards[startIdx]
            visit(startIdx, card)
        } else {
            return
        }
    }
}