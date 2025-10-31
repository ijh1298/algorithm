class Solution {
    fun solution(genres: Array<String>, plays: IntArray): IntArray {
        val map = mutableMapOf<String, MutableList<Song>>()
        
        // map<장르, 노래> 생성
        for (i in 0 until genres.size) {
            if (map[genres[i]] == null) {
                map[genres[i]] = mutableListOf()
            } 
            map[genres[i]]?.let { it += Song(i, plays[i]) }
        }
        
        // 인기 많은 장르 순 정렬
        val order = map.keys.map { 
            val songs: MutableList<Song> = map[it]!!
            it to songs.map{ it.plays }.sum()
        }.sortedByDescending { it.second }
        
        
        // 장르 당 최대 두 개씩 추출
        val answer = mutableListOf<Int>()
        order.forEach { it ->
            val songs = map[it.first]!!.sortedByDescending { it.plays }
            if (songs.size >= 1) { answer += songs[0].idx }
            if (songs.size >= 2) { answer += songs[1].idx }
        }
        
        return answer.toIntArray()
    }
}

data class Song(
    val idx: Int,
    val plays: Int,
)