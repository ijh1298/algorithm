// 길이 될 수 있는지 체크하는 함수
fun check(l: Int, line: IntArray): Boolean {
    var flag = true // 가능 여부
    var isDescending = false // 하향 중인지
    var fallingCnt = 0
    var prev = 0 // 이전 칸의 높이
    var stk = 1 // 현재까지 이어진 같은 높이의 칸 수

    for (cur in line) {
        // 첫 번째 칸 검사
        if (prev == 0) {
            prev = cur
            continue
        }

        // 하향 경사로를 설치하고 있다면
        if (isDescending) {
            if (prev != cur) {
                flag = false
                break
            }
            // 같은 높이만 와야 한다.
            else {
                if (--fallingCnt == 0) {
                    isDescending = false // 설치 끝
                    stk = 0
                }
            }
            prev = cur
            continue
        }

        if (prev == cur) {
            stk++
            prev = cur
        }
        // 상향 체크
        else if (prev + 1 == cur && stk >= l) {
            stk = 1 // 초기화
            prev = cur
        }
        // 하향 체크
        else if (prev - 1 == cur) {
            if (l != 1) {
                isDescending = true
                fallingCnt = l - 1
            }
            else
                stk = 0
            prev = cur
        } else {
            flag = false
            break
        }
    }
    return if (isDescending) false else flag
}

fun main() {
    // 입력
    val br = System.`in`.bufferedReader()
    val (N, L) = br.readLine().split(' ').map { it.toInt() }
    val matrix = Array(N) { IntArray(N) { _ -> 0 } }
    for (i in 0 until N) {
        matrix[i] = br.readLine().split(' ').map { it.toInt() }.toIntArray()
    }

    var ans = 0

    // 행부터 체크
    for (i in 0 until N) {
        val line = matrix[i]

        if (check(L, line))
            ans++
    }

    // 열 체크
    for (i in 0 until N) {
        var list = mutableListOf<Int>()
        for (j in 0 until N) {
            list.add(matrix[j][i])
        }
        val line = list.toIntArray()

        if (check(L, line))
            ans++
    }

    // 출력
    println(ans)
}