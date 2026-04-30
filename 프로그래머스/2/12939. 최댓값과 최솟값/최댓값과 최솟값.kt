class Solution {
    fun solution(s: String): String {
        val sorted = s.split(' ').map { it.toInt() }.sorted()
        return "${sorted[0]} ${sorted.last()}"
    }
}