// a는 밑, b는 지수
// 2^10 = 2^5 * 2^5 로 분할 정복할 수 있다.
// 2^11 = 2^5 * 2^5 * 2 일 것이다.
// 매번 재귀 함수를 호출하는 대신 val half로 저장하고 재사용해야 시간 복잡도를 줄일 수 있음
fun pow(a: Long, b: Long, c: Long): Long {
    if (b == 0L) return 1
    if (b == 1L) return a % c

    val half = pow(a, b / 2, c)
    val halfMod = (half * half) % c
    return if (b % 2 == 0L) {
        halfMod
    } else {
        (halfMod * (a % c)) % c
    }
}

fun main() {
    val br = System.`in`.bufferedReader()
    val (A, B, C) = br.readLine().split(' ').map { it.toLong() }

    println(pow(A, B, C))
}
