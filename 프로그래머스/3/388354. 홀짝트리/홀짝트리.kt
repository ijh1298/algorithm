enum class Result {
    none, oddEven, rOddEven
}

class Solution {
    var answer = intArrayOf(0, 0)
    val uv = List(1000001) { mutableListOf<Int>() }
    val visit = BooleanArray(1000001) { false }
    
    fun solution(nodes: IntArray, edges: Array<IntArray>): IntArray {
        // init
        edges.forEach { 
            val (u, v) = it
            uv[u] += v
            uv[v] += u
        }
        
        nodes.forEach { start ->
            visit[start] = true
            val result = dfs(start, start, Type.root)
            visit[start] = false
            when (result) {
                Result.oddEven -> answer[0]++
                Result.rOddEven -> answer[1]++
                else -> Unit
            }
        }
        return answer
    }
    
    fun dfs(start: Int, cur: Int, parentType: Type): Result {
        val isEven = if (cur % 2 == 0) true else false
        val childSize = if (start != cur) uv[cur].size - 1 else uv[cur].size
        val type = Type(isEven, childSize)
        
        var result = Result.none
        if (type.isSameKindWith(parentType)) {
            for (child in uv[cur]) {
                if (!visit[child]) {                    
                    visit[child] = true
                    result = dfs(start, child, type)
                    visit[child] = false
            
                    // 자식으로 받은 result가 현재 노드 타입과 다르면 none 반환
                    if (result == Result.none || !type.isSameKindWith(result)) {
                        return Result.none
                    }
                }
            }   
        }
        
        if (childSize == 0) {
            if (type == Type.odd || type == Type.even)
                return Result.oddEven
            else {
                return Result.rOddEven
            }
        }
        return result
    }
    
    fun Type(isEven: Boolean, childSize: Int): Type {
        return if (isEven && childSize % 2 == 0) {
            Type.even
        } else if (isEven && childSize % 2 != 0) {
            Type.rEven
        } else if (!isEven && childSize % 2 != 0) {
            Type.odd
        } else {
            Type.rOdd
        }
    }
}

// 노드 타입
enum class Type {
    root, odd, even, rOdd, rEven
}

fun Type.isSameKindWith(target: Type): Boolean {
    return if (target == Type.root) {
        true
    } else if ((this == Type.odd || this == Type.even) && (target == Type.odd || target == Type.even)) {
        true
    } else if ((this == Type.rOdd || this == Type.rEven) && (target == Type.rOdd || target == Type.rEven)) {
        true
    } else {
        false
    }
}

// 자식으로부터 받은 결과가 내 것과 같은지 판단
fun Type.isSameKindWith(target: Result): Boolean {
    return if ((this == Type.odd || this == Type.even) && (target == Result.oddEven)) {
        true
    } else if ((this == Type.rOdd || this == Type.rEven) && (target == Result.rOddEven)) {
        true
    } else {
        false
    }
}
