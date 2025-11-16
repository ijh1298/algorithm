import java.util.PriorityQueue

class Solution {
    fun solution(k: Int, tangerine: IntArray): Int {
        val map = mutableMapOf<Int, Int>()
        
        tangerine.forEach {
            if (map[it] == null) {
                map[it] = 1
            } else {
                map[it]?.let { v -> map[it] = v + 1 }
            }
        }
        
        val pq = PriorityQueue(compareByDescending<Pair<Int, Int>> { it.second })
        map.entries.forEach { 
            val (key, value) = it
            pq.add(key to value)
        }
        
        var ans = 0
        var count = 0
        while (k > count) {
            val (key, value) = pq.poll()
            count += value
            ans++
        }
        
        return ans
    }
}
