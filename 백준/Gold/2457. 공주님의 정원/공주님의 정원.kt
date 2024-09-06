import kotlin.math.max

data class Flower(
    val sMonth: Int, val sDay: Int, val eMonth: Int, val eDay: Int
)

// 날짜를 x일로 계산하여 반환
fun calculateDay(month: Int, day: Int): Int {
    var days = day
    for (i in 1 until month) {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
            days += 31
        } else if (i == 2) {
            days += 28
        } else
            days += 30
    }
    return days
}

fun main() {
    val br = System.`in`.bufferedReader()
    val n = br.readLine().toInt()

    val flowers = mutableListOf<Flower>()
    repeat(n) {
        val (sMonth, sDay, eMonth, eDay) = br.readLine().split(' ').map { it.toInt() }
        // 범위에 벗어나는 입력 제외
        if (eMonth > 2 && sMonth != 12) {
            flowers += Flower(sMonth, sDay, eMonth, eDay)
        }
    }
    // 시작 날짜가 가장 빠른 순, 종료 날짜가 가장 느린 순으로 정렬
    flowers.sortWith(compareBy<Flower> { it.sMonth }.thenBy { it.sDay }.thenByDescending { it.eMonth }
        .thenByDescending { it.eDay })

    val marchFirst = calculateDay(3, 1)
    var firstDayCheck = false
    var lastStartDays = 0
    var lastEndDays = 0

    var ans = 0
    for (f in flowers) {
        val curStartDays = calculateDay(f.sMonth, f.sDay)
        val curEndDays = calculateDay(f.eMonth, f.eDay) - 1

        // 종료 조건 달성시 break
        if (lastEndDays >= calculateDay(11, 30))
            break

        // 다음 가장 빠른 꽃이 지금 꽃의 종료 시기보다 크면 종료 (이어지지 않으면 안 됨)
        if (lastEndDays != 0 && curStartDays > lastEndDays + 1) {
            println("0")
            return
        }
        // 현재 기간에 이미 꽃이 있다면 skip
        else if (curEndDays <= lastEndDays) {
            continue
        }
        // 이어지는 꽃으로 기간 갱신
        else {
            if (curStartDays <= marchFirst)
                firstDayCheck = true
            // 대체 가능한 경우
            if (lastStartDays != 0 && max(lastStartDays, marchFirst) >= curStartDays) {
                lastEndDays = curEndDays
            }
            // 이어야 하는 경우
            else {
                lastStartDays = lastEndDays + 1
                lastEndDays = curEndDays
                ans++
            }
        }
    }
    if (firstDayCheck && lastEndDays >= calculateDay(11, 30))
        println(ans)
    else
        println("0")
}