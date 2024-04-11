var ans : Int = 0
var visit = Array(51) { i -> false }
var tree : List<MutableList<Int>> = List(51) { mutableListOf() }

// DFS 구현
fun dfs(cur : Int, destroy : Int) {
    val len = tree[cur].size
    var cnt = 0
    for (i in 0..<len) {
        val next = tree[cur][i]

        // 다음 노드가 잘린 노드라면 skip
        if (next == destroy)
            continue

        if (!visit[next]) {
            visit[next] = true
            dfs(tree[cur][i], destroy)
            cnt++
        }
    }
    
    // 방문할 수 있는 곳이 없었다면 리프 노드
    if (cnt == 0)
        ans++
}

fun main() {
    val br = System.`in`.bufferedReader()
    val N = br.readLine().toInt()
    val arr = br.readLine().split(' ').map { it.toInt() }
    val destroy = br.readLine().toInt()
    var root : Int = 0

    for (i in 0..<N) {
        if (arr[i] != -1) {
            tree[i].add(arr[i])
            tree[arr[i]].add(i)
        }
        else {
            root = i
        }
    }

    // 루트가 잘리면 개수 == 0
    visit[root] = true
    if (destroy != root)
        dfs(root, destroy)

    print(ans)
}