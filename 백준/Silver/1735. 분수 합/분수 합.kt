fun gcd(first: Int, second: Int): Int {
    if (second == 0)
        return first
    return gcd(second, first % second)
}

fun main() {
    val br = System.`in`.bufferedReader()
    val (a, b) = br.readLine().split(' ').map { it.toInt() }
    val (c, d) = br.readLine().split(' ').map { it.toInt() }

    val ad_cb = a * d + c * b
    val bd = b * d

    val GCD = if (ad_cb < bd) gcd(bd, ad_cb) else gcd(ad_cb, bd)

    println("${ad_cb / GCD} ${bd / GCD}")
}