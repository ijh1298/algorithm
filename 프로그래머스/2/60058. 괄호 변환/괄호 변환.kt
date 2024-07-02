class Solution {
    data class Info(val u: String, val v: String, val valid: Boolean) {}
    
    fun divide(str: String): Info {
        var lp = 0
        var rp = 0
        val valid = if (str[0] == ')') false else true  // u가 올바른 문자열인가?
        
        var cur = ""
        for (i in str.indices) {
            cur += str[i]
            if (str[i] == '(') lp++ else rp++
            if (lp == rp)
                break
        }    
        return Info(cur, str.substring(lp + rp), valid) // u, v, validity 반환
    }
    
    fun remake(str: String): String {
        if (str == "") return str                       // 1.
        
        val (u, v, validity) = divide(str)              // 2.
        var cur = "("                                   // 4-1.
            
        if (validity) {                                 // 3.
            return u + remake(v)                        // 3-1
        }
        else {
            cur += remake(v) + ")"                      // 4-3.
            for (i in 1..u.length - 2) {
                cur += if (u[i] == ')') "(" else ")"    // 4-4.
            }
            return cur                                  // 4-5.
        } 
    }
    
    fun solution(p: String): String {
        return remake(p)
    }
}