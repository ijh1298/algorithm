class Solution {
    fun solution(today: String, terms: Array<String>, privacies: Array<String>): IntArray {
        val todayDate = today.toDate()
        
        var answer: IntArray = intArrayOf()
        
        val typeToPeriod = terms.map {
            val (type, period) = it.split(' ')
            type to period.toInt()
        }
        // {A=6, B=12, ...} Pair 가지는 Map
        val typeMap = typeToPeriod.associate { it.first to it.second }
        
        // 계산 완료된 날짜 Array
        val calculatedDates = privacies.map { p ->
            val (rawDate, type) = p.split(' ')
            val date = rawDate.toDate()
            val calculatedDate = date.after(typeMap[type] ?: 0)
            calculatedDate
        }
        
        // 현재 날짜보다 이전인 날짜들의 idx 저장
        var count = 1
        calculatedDates.forEach { 
            if (it.isBeforeOrSame(todayDate)) {
                answer += count
            }
            count++
        }
        
        return answer
    }
    
    fun String.toDate(): Date {
        val (year, month, day) = split('.').map { it.toInt() }
        return Date(year, month, day)
    }
}

class Date(
    val year: Int,
    val month: Int,
    val day: Int
) {
    fun after(periodMonth: Int): Date {
        val totalMonths = month + periodMonth
        val newYear = year + (totalMonths - 1) / 12
        val newMonth = (totalMonths - 1) % 12 + 1
        return Date(newYear, newMonth, day)
    }
    
    fun isBeforeOrSame(otherDate: Date): Boolean {
        return if (year < otherDate.year) {
            true
        } else if (year == otherDate.year) {
            if (month < otherDate.month) {
                true
            } else if (month == otherDate.month) {
                day <= otherDate.day
            } else {
                false
            }
        } else {
            false
        }
    }
}