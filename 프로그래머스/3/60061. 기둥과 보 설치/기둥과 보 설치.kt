class Solution {
    fun solution(n: Int, build_frame: Array<IntArray>): Array<IntArray> {
        val structure = Array(n + 1) { Array(n + 1) { Pair(0, 0) } } // Pair(기둥, 보)

        // 유효성 검사
        fun isValid(): Boolean {
            for (x in 0..n) {
                for (y in 0..n) {
                    val (pillar, beam) = structure[x][y]

                    if (pillar == 1) {
                        // 기둥 조건
                        if (!(y == 0 || (x > 0 && structure[x - 1][y].second == 1) || structure[x][y].second == 1 || (y > 0 && structure[x][y - 1].first == 1))) {
                            return false
                        }
                    }
                    if (beam == 1) {
                        // 보 조건
                        if (!(y > 0 && (structure[x][y - 1].first == 1 || (x < n && structure[x + 1][y - 1].first == 1)) || (x > 0 && x < n && structure[x - 1][y].second == 1 && structure[x + 1][y].second == 1))) {
                            return false
                        }
                    }
                }
            }
            return true
        }

        build_frame.forEach {
            val (x, y, a, b) = it

            if (a == 0) {       // 기둥
                if (b == 1) {   // 설치
                    if (y == 0 || (x > 0 && structure[x - 1][y].second == 1) || structure[x][y].second == 1 || (y > 0 && structure[x][y - 1].first == 1)) {
                        structure[x][y] = Pair(1, structure[x][y].second)
                    }
                } else {        // 제거
                    structure[x][y] = Pair(0, structure[x][y].second)
                    // 제거한 후 유효성 검사 -> 실패 시 복원
                    if (!isValid()) {
                        structure[x][y] = Pair(1, structure[x][y].second)
                    }
                }
            } else {            // 보
                if (b == 1) {   // 설치
                    // 인덱스 조건 추가
                    if (y > 0 && ((x > 0 && structure[x - 1][y].second == 1 && x < n && structure[x + 1][y].second == 1) || structure[x][y - 1].first == 1 || (x < n && structure[x + 1][y - 1].first == 1))) {
                        structure[x][y] = Pair(structure[x][y].first, 1)
                    }
                } else {        // 제거
                    structure[x][y] = Pair(structure[x][y].first, 0)
                    // 제거한 후 유효성 검사 -> 실패 시 복원
                    if (!isValid()) {
                        structure[x][y] = Pair(structure[x][y].first, 1)
                    }
                }
            }
        }

        val result = mutableListOf<IntArray>()
        for (x in 0..n) {
            for (y in 0..n) {
                if (structure[x][y].first == 1)
                    result.add(intArrayOf(x, y, 0))
                if (structure[x][y].second == 1)
                    result.add(intArrayOf(x, y, 1))
            }
        }
        return result.sortedWith(compareBy({ it[0] }, { it[1] }, { it[2] })).toTypedArray()
    }
}
