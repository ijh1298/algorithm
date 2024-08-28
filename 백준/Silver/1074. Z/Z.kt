var answer: Int = 0

fun recur(n: Int, r: Int, c: Int) {
    // 종료 조건 : 크기가 1인 경우
    if (n == 1) {
        answer += 2 * r + c
        return
    }
    // half : 현재 사각형 크기의 반 == 2^(N-1)
    val half = 2 shl (n - 2)
    val halfSquare = half * half
    // 제1사분면일 때
    if (r < half && c < half) recur(n - 1, r, c)
    // 제2사분면일 때
    else if (r < half && c >= half) {
        answer += halfSquare
        recur(n - 1, r, c - half)
    }
    // 제3사분면일 때
    else if (r >= half && c < half) {
        answer += halfSquare * 2
        recur(n - 1, r - half, c)
    }
    // 제4사분면일 때
    else {
        answer += halfSquare * 3
        recur(n - 1, r - half, c - half)
    }
}

fun main() {
    val br = System.`in`.bufferedReader()
    val (n, r, c) = br.readLine().split(' ').map { it.toInt() }

    recur(n, r, c)
    println(answer)
}