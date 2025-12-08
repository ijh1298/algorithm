class Solution {
    val visit = BooleanArray(100_001) { false }
    
    fun solution(s: String): IntArray {
        // 파싱 후 짧은 리스트부터 정렬
        val lists = parse(s).sortedBy { it.size }
        
        // 방문하지 않은 원소면 추가
        var answer = mutableListOf<Int>()
        lists.forEach { list ->
            list.forEach { e ->
                if (!visit[e]) {
                    visit[e] = true
                    answer += e
                }
            }
        }
        return answer.toIntArray()
    }
    
    fun parse(s: String): MutableList<MutableList<Int>> {
        val list = mutableListOf<MutableList<Int>>()
        
        var tempList = mutableListOf<Int>()
        var tempNum = ""
        for (i in 0 until s.length) {
            if (i == 0) continue
            if (i == s.length - 1) tempList += tempNum.toInt()
            
            if (s[i] == '{') tempList = mutableListOf<Int>()
            else if (s[i] == '}') list += tempList
            else if (s[i] == ',' && tempNum.isNotBlank()) {
                tempList += tempNum.toInt()
                tempNum = ""
            }
            else tempNum += s[i]
        }
        return list
    }
}
