class Solution {
    fun solution(id_list: Array<String>, report: Array<String>, k: Int): IntArray {
        val users = id_list.associate { it to Report() }
        
        report.forEach { 
            val (reporter, reportee) = it.split(' ')
            users[reportee]?.let { it.reportBy(reporter) }
        }
        
        users.values.forEach { report ->
            if (report.count >= k) {
                report.reportedBy.forEach { reporter ->
                    users[reporter]?.let { users[reporter]!!.receivedMails++ }
                }
            }
        }
        
        val answer = users.values.map { it.receivedMails }.toIntArray()
        return answer
    }
}

data class Report(
    var count: Int = 0,
    val reportedBy: MutableSet<String> = mutableSetOf(),
    var receivedMails: Int = 0,
) {
    fun reportBy(name: String) {
        if (reportedBy.contains(name) == false) {
            reportedBy.add(name)
            count++
        }
    }
}