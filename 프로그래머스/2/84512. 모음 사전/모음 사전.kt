class Solution {
    var string = mutableListOf<Char>()
    val alphabet = listOf('A', 'E', 'I', 'O', 'U')
    var isDone = false
    var answer = 0
    
    fun solution(word: String): Int {
        backtrack(0, word)
        return answer
    }
    
    fun backtrack(length: Int, word: String) {
        if (isDone || length == 5) return
        
        for (i in 0..4) {
            string += alphabet[i]
            answer++
            
            if (string.joinToString("") == word) { 
                isDone = true
                return
            }
            backtrack(length + 1, word)
            if (isDone) return
            
            string.removeLast()
        }   
    }
}
