fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()

    val n = br.readLine().toInt()
    val list = br.readLine().split(' ').map { it.toInt() }
    val odd = MutableList<Int>(n) { 0 }
    val even = MutableList<Int>(n) { 0 }

    // Odd-length palindromes centered at each element
    for (i in 0 until n) {
        var bound = 1
        while (i - bound >= 0 && i + bound < n && list[i - bound] == list[i + bound]) {
            odd[i]++
            bound++
        }
    }

    // Even-length palindromes centered between each pair of elements
    for (i in 0 until n - 1) {
        var bound = 0
        while (i - bound >= 0 && i + 1 + bound < n && list[i - bound] == list[i + 1 + bound]) {
            even[i]++
            bound++
        }
    }

    val t = br.readLine().toInt()
    for (i in 0 until t) {
        val (s, e) = br.readLine().split(' ').map { it.toInt() - 1 }

        if (s == e) {
            bw.write("1\n")
            continue
        }

        if (e - s == 1) {
            if (list[s] == list[e])
                bw.write("1\n")
            else
                bw.write("0\n")
            continue
        }

        val mid = (s + e) / 2

        if ((e - s) % 2 == 0) {
            // Odd 확인
            if (odd[mid] >= (e - s) / 2) {
                bw.write("1\n")
            } else {
                bw.write("0\n")
            }
        } else {
            // Even 확인
            if (even[mid] >= (e - s + 1) / 2) {
                bw.write("1\n")
            } else {
                bw.write("0\n")
            }
        }
    }

    bw.flush()
    bw.close()
}
