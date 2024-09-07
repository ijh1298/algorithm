val br = System.`in`.bufferedReader()
val bw = System.`out`.bufferedWriter()
val used = HashMap<String, Boolean>()
var str = ""

fun bt(n: Int, curLen: Int, curIdx: Int, characters: List<String>) {
    if (n == curLen) {
        var consonant = 0
        var vowel = 0
        str.forEach {
            if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u')
                vowel++
            else
                consonant++
        }

        // 모음 1개, 자음 2개 이상인 경우
        if (vowel > 0 && consonant > 1)
            bw.write("$str\n")

        return
    }

    for (c in curIdx until characters.size) {
        if (used[characters[c]] != true) {
            str += characters[c]
            used[characters[c]] = true

            bt(n, curLen + 1, c + 1, characters)
            str = str.dropLast(1)
            used[characters[c]] = false
        }
    }
}

fun main() {
    val (l, c) = br.readLine().split(' ').map { it.toInt() }
    val characters = br.readLine().split(' ').map { it }.sorted()

    bt(l, 0, 0, characters)
    bw.flush()
    bw.close()
}