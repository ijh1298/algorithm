class Solution {
    fun solution(s: String): Int {
        var answer = s.length
        for (i in 1..s.length) { // i : 자를 개수
            var ptr = 0
            var cur = ""
            var prev = ""
            var cnt = 1 // 압축 누적 횟수
            var total = 0
            var flag = false // 종료 Flag

            while (true) {
                for (r in 1..i) {
                    if (ptr != s.length)
                        cur += s[ptr++] // 자를 개수만큼 단어를 선택하여 cur에 저장
                    else { // 범위를 넘었으면 탈출
                        total += if (cnt > 1) i + cnt.toString().length else i
                        total += s.length % i
                        flag = true
                        break
                    }
                }
                if (flag) break

                if (prev == "") { // 첫 단어면 넘어가기
                    prev = cur
                    cur = ""
                    continue
                }
                else if (cur == prev)
                    cnt++
                else {
                    total += if (cnt > 1) i + cnt.toString().length else i
                    cnt = 1
                }
                prev = cur
                cur = ""
            }
            if (answer > total) answer = total
        }
        return answer
    }
}