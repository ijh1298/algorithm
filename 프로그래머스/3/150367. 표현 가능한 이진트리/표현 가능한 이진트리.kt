class Solution {
    fun solution(numbers: LongArray): IntArray {
        // 좌우가 분할되었을 때의 충족해야 하는 길이
        val possibleLengths = listOf(1, 3, 7, 15, 31, 63)
        
        // 숫자를 이진수의 문자열로 만들기
        // 길이가 짝수일 경우 맨 앞에 0을 붙여준다
        val binaries = numbers.map { 
            val binary = it.toString(2)
            val targetLength = possibleLengths.first { it >= binary.length }
            // 필요한 만큼 0 패딩
            "0".repeat(targetLength - binary.length) + binary
        }
        
        val answer = binaries.map { 
            if (it.length in possibleLengths && isPossible(it, 0, it.length - 1)) {
                1    
            }
            else {
                0
            }
        }
        return answer.toIntArray()
    }
    
    // 분할 정복
     fun isPossible(str: String, start: Int, end: Int): Boolean {
        val mid = start + (end - start) / 2
        
        // 단일 노드일 경우
        if (start == end) {
            return true
        }
        
        // 세 글자 길이고 중간이 1인 경우
        if (end - start == 2 && str[mid] == '1') {
            return true
        }
        // 세 글자 길이고 중간이 0인 경우 - 모두 더미
        if (end - start == 2) {
            return str[start] == '0' && str[mid] == '0' && str[end] == '0'
        }
        
        // 중간이 1일 경우 좌우를 분할 정복
        if (str[mid] == '1') {
            return isPossible(str, start, mid - 1) && isPossible(str, mid + 1, end)
        }
        // 중간이 0이면 전체가 0인지 확인(중간이 더미면 자식도 모두 더미여야함)
        else {
            for (i in start..end) {
                if (str[i] == '1') return false
            }
            return true
        }
    }
}
