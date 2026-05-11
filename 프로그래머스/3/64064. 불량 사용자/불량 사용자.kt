class Solution {
    var uids = arrayOf<String>()
    var bids = arrayOf<String>()
    val resultSet = mutableSetOf<Set<Int>>()
    
    fun solution(user_id: Array<String>, banned_id: Array<String>): Int {
        uids = user_id
        bids = banned_id
        
        backtrack(0, setOf<Int>())
        return resultSet.size
    }
    
    fun matches(str1: String, str2: String): Boolean {
        if (str1.length != str2.length) return false
        for (i in str1.indices) {
            if (str1[i] == '*' || str2[i] == '*') continue
            if (str1[i] != str2[i]) return false
        }
        return true
    }
    
    fun backtrack(bid_idx: Int, idx_set: Set<Int>) {
        if (idx_set.size == bids.size) {
            resultSet.add(idx_set)
            return
        }
        
        if (bid_idx >= bids.size) return
        
        val curBid = bids[bid_idx]
        
        uids.forEachIndexed { idx, uid ->
            if (idx !in idx_set && matches(curBid, uid)) {
                backtrack(bid_idx + 1, idx_set + idx)
            }
        }
    }
}
