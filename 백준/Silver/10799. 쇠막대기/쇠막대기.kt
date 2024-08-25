fun main() {
    val br = System.`in`.bufferedReader()
    val input = br.readLine()

    var ans = 0

    val stk = ArrayDeque<Char>()
    var prev : Char = 'X'
    input.forEach {
        if (!stk.isEmpty() && stk.last() == '(' && it == ')') {
            // 직전에 ( 였으면 레이저
            if (prev == '(') {
                stk.removeLast()
                ans += stk.size
            }
            // 아니면 막대기 하나 제거
            else {
                stk.removeLast()
                ans++
            }
        }
        else
            stk.add(it)

        prev = it
    }

    println(ans)
}