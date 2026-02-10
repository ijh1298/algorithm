class Solution {
    var ans = 51
    lateinit var visit: BooleanArray
    
    fun solution(begin: String, target: String, words: Array<String>): Int {
        visit = BooleanArray(words.size) { false }
        dfs(begin, 0, target, words)
        return if (ans == 51) 0 else ans
    }
    
    fun dfs(curWord: String, depth: Int, target: String,  words: Array<String>) {
        if (curWord == target) {
            ans = minOf(ans, depth)
        }
        
        words.forEachIndexed { idx, word ->
            if (!visit[idx] && curWord.isOneDiff(word)) {
                visit[idx] = true
                dfs(word, depth + 1, target, words)
                visit[idx] = false
            }
        }
    }
    
    // 하나의 알파벳만 다른지 판별하는 함수
    fun String.isOneDiff(other: String): Boolean {
        var cnt = 0
        this.forEachIndexed { idx, _ ->
            if (this[idx] != other[idx]) cnt++
            if (cnt > 1) return false
        }
        return cnt == 1
    }
}