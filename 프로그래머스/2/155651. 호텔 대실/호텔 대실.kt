import java.util.PriorityQueue

class Solution {
    fun solution(book_time: Array<Array<String>>): Int {
        var answer: Int = 0
        
        fun StringToInt(time: String): Int {
            val (hour, minutes) = time.split(":").map { it.toInt() } // 문자열의 시간을 분 단위로 변경, 변경하지 않을 거면 (50 +10)분을 (1시간 0)분으로 바꾸는 로직이 필요함
            return hour * 60 + minutes
        }
        
        val bookTimes = book_time.map { array ->
            array.map { StringToInt(it) }.toTypedArray()
        }.toTypedArray()
        
        val bookComparator = Comparator<Pair<Int, Int>> { p1, p2 ->
            p1.first.compareTo(p2.first)
        }
        
        val books = PriorityQueue(bookComparator)
        val endTime = PriorityQueue<Int>()
        
        for (book in bookTimes) {
            books.add(Pair(book[0], book[1])) // Pair(시작 시간, 종료 시간)을 우선 순위큐에 삽입
        }
        
        while (!books.isEmpty()) {
            val firstBook = books.poll()
            val end = if (endTime.isEmpty()) 0 else endTime.peek()
            
            if (end == 0)
                answer++
            else if (end <= firstBook.first) {
                endTime.poll()
            }
            else {
                answer++
            }
            endTime.add(firstBook.second + 10)
        }
        return answer
    }
}
// 제일 빠른 시작 시간의 방이, 제일 빨리 종료되는 방에 들어가지 못하면 방이 추가 되어야 함.

// 제일 빠른 시작 시간 하나 선택. 14:10~19:20 (종료 시각 19:30)
// 첫번째 방 배정. 19:30 종료 시각

// 제일 빠른 시작 시간 하나 선택. 14:20~15:20 => 15:30 종료
// 시작 시간이 19:30보다 큰가? => 크면 방 추가 할 필요 없다. but X
// 두번째 방 배정. 15:30 종료 시각

// 제일 빠른 시작 시간 하나 선택. 15:00~17:00 => 17:10 종료
// 시작 시간이 15:30(우선순위큐의 제일 빠른 종료 시각)보다 큰가? => X
// 세번째 방 배정. 17:10 종료 시각

// 제일 빠른 시작 시간 하나 선택. 16:40~18:20 => 18:30 종료
// 시작 시간이 15:30보다 큰가? => O
// 두번째 방 배정. 18:40 종료 시각

// 제일 빠른 시작 시간 하나 선택. 18:20~21:20 => 21:30 종료
// 시작 시간이 17:10보다 큰가? => O
// 세번째 방 배정. 21:30 종료 시각