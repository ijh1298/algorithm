import java.math.BigInteger

val br = System.`in`.bufferedReader()
val bw = System.`out`.bufferedWriter()

fun hanoi(start: Int, temp: Int, end: Int, n: Int) {
    // 종료 조건: 마지막 하나를 옮길 때
    if (n == 1) {
        bw.write("$start $end\n")
        return
    }
    // 재귀 호출
    // 임시 기둥으로 end를 사용해 temp 기둥에 일단 N - 1개 이동
    hanoi(start, end, temp, n - 1)
    bw.write("$start $end\n")
    // 임시 기둥으로 start를 사용해 end 기둥으로 N - 1개 이동
    hanoi(temp, start, end, n - 1)
}

fun main() {
    val N = br.readLine().toInt()

    // 이동 횟수는 2^N - 1
    // Long 최대 2^63이기에 BigInteger를 사용해야 한다.
    var cnt = BigInteger("2").pow(N).minus(BigInteger("1"))
    bw.write(cnt.toString())  // 정수를 문자열로 변환하여 출력
    bw.newLine()

    if (N < 21) {
        hanoi(1, 2, 3, N)
    }

    bw.flush()
    bw.close()
}
