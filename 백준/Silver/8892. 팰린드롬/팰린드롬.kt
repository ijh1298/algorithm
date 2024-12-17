fun isPalindrome(str: String): Boolean {
    var s = 0
    var e = str.length - 1

    while (s < e) {
        if (str[s] != str[e])
            return false
        ++s
        --e
    }
    return true
}

fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()

    val T = br.readLine().toInt()
    for (t in 0 until T) {
        val K = br.readLine().toInt()
        val inputs = List(K) { br.readLine() }

        val words = mutableListOf<String>()
        for (i in 0..inputs.size - 2)
            for (j in i + 1..<inputs.size) {
                words += inputs[i] + inputs[j]
                words += inputs[j] + inputs[i]
            }

        var isDone = false
        for (w in words) {
            if (isPalindrome(w)) {
                bw.write(w + '\n')
                isDone = true
                break
            }
        }
        if (!isDone)
            bw.write("0" + '\n')
    }
    bw.flush()
    bw.close()
}