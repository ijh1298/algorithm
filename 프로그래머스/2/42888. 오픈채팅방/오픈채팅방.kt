class Solution {
    fun solution(record: Array<String>): Array<String> {
        val answer = mutableListOf<String>()
        val map = mutableMapOf<String, String>()
        
        record.forEach { r ->
            val strings = r.split(' ').map { it }
            
            // Leave 명령은 볼 필요 X
            if (strings.size == 3) {
                val (cmd, uid, name) = strings
                map[uid] = name
            }
        }
        
        record.forEach { r ->
            val strings = r.split(' ').map { it }
            
            if (strings.size == 2) {
                val (cmd, uid) = strings
                answer += "${map[uid]}님이 나갔습니다."
            } else {
                val (cmd, uid, name) = strings
                if (cmd == "Enter") answer += "${map[uid]}님이 들어왔습니다."
            }
        }
        
        return answer.toTypedArray()
    }
}
