class Solution {
    lateinit var exp: String
    var answer = 0L

    fun solution(expression: String): Long {
        exp = expression
        // 실제 존재하는 연산자만 추출
        val ops = expression.filter { !it.isDigit() }.toSet().toList()
        backtrack(ops, emptyList(), BooleanArray(ops.size))
        return answer
    }

    fun backtrack(ops: List<Char>, list: List<Char>, used: BooleanArray) {
        if (list.size == ops.size) {
            check(list)
            return
        }
        for (i in ops.indices) {
            if (!used[i]) {
                used[i] = true
                backtrack(ops, list + ops[i], used)
                used[i] = false
            }
        }
    }

    fun check(prio: List<Char>) {
        val filtered = mutableListOf<String>()
        var stack = ""
        exp.forEach {
            if (it.isDigit()) {
                stack += it
            } else {
                filtered.add(stack)
                filtered.add(it.toString())
                stack = ""
            }
        }
        if (stack.isNotEmpty()) filtered += stack

        var calculated = filtered.toList()
        // 실제 연산자 문자로 순서대로 계산
        prio.forEach { op ->
            calculated = calculate(calculated, op.toString())
        }

        val result = calculated.first().toLong()
        answer = maxOf(answer, Math.abs(result))
    }

    fun calculate(list: List<String>, op: String): List<String> {
        var nextSkip = false
        val newList = mutableListOf<String>()
        list.forEachIndexed { idx, it ->
            when {
                nextSkip -> nextSkip = false
                it == op -> {
                    val prev = newList.last().toLong()
                    val next = list[idx + 1].toLong()
                    newList.removeLastOrNull()
                    val result = when (op) {
                        "*" -> prev * next
                        "-" -> prev - next
                        else -> prev + next
                    }
                    newList += result.toString()
                    nextSkip = true
                }
                else -> newList += it
            }
        }
        return newList
    }
}
