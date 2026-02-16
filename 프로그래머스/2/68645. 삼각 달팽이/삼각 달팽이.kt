class Solution {
    fun solution(n: Int): IntArray {
        val matrix = Array(n) { Array(n) {0} }
        
        var cur = 1
        var N = n
        var x = 0
        var y = 0
        
        while (N > 0) {
            // 1. 밑으로
            repeat (N) {
                matrix[x++][y] = cur++
            }
            N--; x--; y++;

            // 2. 오른쪽으로
            repeat (N) {
                matrix[x][y++] = cur++
            }
            N--; y--; y--; x--;
            

            // 3. 위로
            repeat (N) {
                matrix[x--][y--] = cur++
            }
            N--; x++; y++; x++;
        }
        
        val answer = matrix.flatten().filter { it != 0 }.toIntArray()
        return answer
    }
}
