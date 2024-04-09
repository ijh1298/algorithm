fun main() {
    val br = System.`in`.bufferedReader()
    val (str, notation) = br.readLine().split(' ')
    val not = notation.toInt()

    var ans = 0
    var mult = 1
    val len = str.length

    for (i in len - 1 downTo 0) {
        // 알파벳이라면
        if (str[i] >= 'A') {
            ans += (str[i] - 'A' + 10) * mult
        }
        // 숫자라면
        else
            ans += (str[i] - '0') * mult

        mult *= not
    }
    print(ans)
}