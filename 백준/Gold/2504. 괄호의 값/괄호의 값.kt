fun main() {
    val br = System.`in`.bufferedReader()
    val input = br.readLine()

    var ans = 0
    var flag = false // 올바르지 못한 괄호쌍인지

    val stk = ArrayDeque<String>()
    for (c in input) {
        // 여는 괄호면
        if (c == '(' || c == '[')
            stk.add(c.toString())
        // 닫는 괄호면
        else if (c == ')') {
            if (stk.isEmpty() || stk.last() == "[") {
                flag = true
                break
            }
            // 괄호 짝이면
            if (stk.last() == "(") {
                stk.removeLast()
                // 앞에 값도 숫자면 더해서 push
                if (stk.isNotEmpty() && (stk.last() != "(" && stk.last() != "[")) {
                    val sum = stk.removeLast().toInt() + 2
                    stk.add(sum.toString())
                } else {
                    stk.add("2")
                }
            }
            // 숫자면
            else {
                val temp = stk.removeLast().toInt() * 2
                if (stk.isNotEmpty() && stk.last() == "(") {
                    stk.removeLast()
                    // 앞에 값도 숫자면 더해서 push
                    if (stk.isNotEmpty() && (stk.last() != "(" && stk.last() != "[")) {
                        val sum = stk.removeLast().toInt() + temp
                        stk.add(sum.toString())
                    } else {
                        stk.add(temp.toString())
                    }
                } else {
                    flag = true
                    break
                }
            }
        } else if (c == ']') {
            if (stk.isEmpty() || stk.last() == "(") {
                flag = true
                break
            }
            // 괄호 짝이면
            if (stk.last() == "[") {
                stk.removeLast()
                // 앞에 값도 숫자면 더해서 push
                if (stk.isNotEmpty() && (stk.last() != "(" && stk.last() != "[")) {
                    val sum = stk.removeLast().toInt() + 3
                    stk.add(sum.toString())
                } else {
                    stk.add("3")
                }
            }
            // 숫자면
            else {
                val temp = stk.removeLast().toInt() * 3
                if (stk.isNotEmpty() && stk.last() == "[") {
                    stk.removeLast()
                    // 앞에 값도 숫자면 더해서 push
                    if (stk.isNotEmpty() && (stk.last() != "(" && stk.last() != "[")) {
                        val sum = stk.removeLast().toInt() + temp
                        stk.add(sum.toString())
                    } else {
                        stk.add(temp.toString())
                    }
                } else {
                    flag = true
                    break
                }
            }
        }
    }

    // 수정 : 반례 '((()' 같은 경우, stk size가 1이 아니면서 마지막 값이 존재하기 때문에 size == 1 체크 필요
    if (flag || stk.size != 1 || stk.last() == "(" || stk.last() == ")" || stk.last() == "[" || stk.last() == "]")
        ans = 0
    else
        ans = stk.last().toInt()

    println(ans)
}
