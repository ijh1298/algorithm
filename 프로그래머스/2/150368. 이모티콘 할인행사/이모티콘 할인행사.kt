class Solution {
    var maxPlusUsers = 0
    var maxTotalAmount = 0
    
    fun solution(users: Array<IntArray>, emoticons: IntArray): IntArray {
        for (i in 1..4) {
            backtrack(i * 10, mutableListOf<Int>(), users, emoticons)
        }  
        
        return intArrayOf(maxPlusUsers, maxTotalAmount)
    }
    
    // 이번 계산에 필요한 이모티콘 별 할인율 경우의 수를 구하기
    // 예) [10%, 10%, 10%], [10%, 10%, 20%], ...
    fun backtrack(
        thisSale: Int,
        sales: MutableList<Int>,
        users: Array<IntArray>,
        emoticons: IntArray,
    ) {
        sales += thisSale
        
        if (sales.size == emoticons.size) {
            updateResult(sales, users, emoticons)
        } else {
            for (i in 1..4) {
                backtrack(i * 10, sales, users, emoticons)
                sales.removeLast()
            }  
        }
    }
    
    fun updateResult(
        sales: MutableList<Int>,
        users: Array<IntArray>,
        emoticons: IntArray,
    ) {
        val result = getResult(sales, users, emoticons)
        val (plusUsers, amount) = result
        
        if (plusUsers > maxPlusUsers) {
            maxPlusUsers = plusUsers
            maxTotalAmount = amount
        } else if (plusUsers == maxPlusUsers) {
            maxTotalAmount = maxOf(maxTotalAmount, amount)
        }
    }
    
    // 할인율에 따른 <플러스 가입 유저, 총 이익> IntArray 반환
    fun getResult(
        sales: MutableList<Int>,
        users: Array<IntArray>,
        emoticons: IntArray,
    ): IntArray {
        var resultPlusUsers = 0
        var resultAmount = 0
        
        // 현재 할인율(sales)에 따른 모든 유저의 구매 결과 구하기
        users.forEach { u ->
            val (percentBottomLine, plusBottomLine) = u
            
            var totalAmount = 0
            sales.forEachIndexed { index, s ->
                if (s >= percentBottomLine) {
                    totalAmount += (100 - s) * emoticons[index] / 100
                    // 나누기 100을 마지막에 하는 것에 유의
                }
            }
            
            // 임티플 유저 분기 처리
            if (totalAmount >= plusBottomLine) {
                resultPlusUsers++
            } else {
                resultAmount += totalAmount
            }
        }
        
        return intArrayOf(resultPlusUsers, resultAmount)
    }
}