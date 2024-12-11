fun main() {
    val br = System.`in`.bufferedReader()
    val (N, M) = br.readLine().split(' ').map { it.toInt() }

    // HashMap의 값으로 MutableList를 사용
    val nameToGroup = HashMap<String, String>()
    val groupToName = HashMap<String, MutableList<String>>()

    // 그룹과 멤버를 입력받아 저장
    repeat(N) {
        val groupName = br.readLine()
        val headCount = br.readLine().toInt()

        groupToName[groupName] = mutableListOf()

        repeat(headCount) {
            val name = br.readLine()
            nameToGroup[name] = groupName // 멤버 -> 그룹 매핑
            groupToName[groupName]?.add(name) // 그룹 -> 멤버 추가
        }
    }

    repeat(M) {
        val query = br.readLine()
        val type = br.readLine().toInt()

        if (type == 0) {
            groupToName[query]?.sorted()?.forEach { println(it) }
        } else {
            println(nameToGroup[query])
        }
    }
}
