class Solution {
    fun solution(cap: Int, n: Int, deliveries: IntArray, pickups: IntArray): Long {
        var ans = 0L
        
        var deliveryLastPoint = n - 1
        var pickupLastPoint = n - 1
        
        while (deliveryLastPoint >= 0 || pickupLastPoint >= 0) {
            // 이번에 방문해야 하는 집 중 가장 큰 번호를 찾고, 할 수 있는 만큼 배달하기
            var curCap = cap
            var maxDelivery = -1
            while (deliveryLastPoint >= 0) {
                // 배달 할 게 없는 집인 경우 
                if (deliveries[deliveryLastPoint] == 0) {
                    deliveryLastPoint--
                } else {
                    if (maxDelivery == -1) maxDelivery = deliveryLastPoint
                    
                    // 남은 배달 가능 양보다 이 집에 배달해야 하는 양이 적은 경우
                    if (deliveries[deliveryLastPoint] < curCap) {
                        curCap -= deliveries[deliveryLastPoint]
                        deliveries[deliveryLastPoint] = 0
                        deliveryLastPoint--
                    }
                    // 이 집에 배달해야 할 양이 남은 배달 가능 양보다 많은 경우
                    else if (deliveries[deliveryLastPoint] > curCap) {
                        deliveries[deliveryLastPoint] -= curCap
                        curCap = 0
                        break
                    }
                    // 이 집에 배달 가능 양과 배달해야 하는 양이 정확히 같은 경우
                    else {
                        deliveries[deliveryLastPoint] = 0
                        curCap = 0
                        deliveryLastPoint--
                    }
                }
            }

            var curCap2 = cap
            var maxPickup = -1
            while (pickupLastPoint >= 0) {
                // 픽업 할 게 없는 집인 경우 
                if (pickups[pickupLastPoint] == 0) {
                    pickupLastPoint--
                } else {
                    if (maxPickup == -1) maxPickup = pickupLastPoint
                    
                    // 남은 픽업 가능 양보다 이 집에 픽업해야 하는 양이 적은 경우
                    if (pickups[pickupLastPoint] < curCap2) {
                        curCap2 -= pickups[pickupLastPoint]
                        pickups[pickupLastPoint] = 0
                        pickupLastPoint--
                    }
                    // 이 집에 픽업해야 할 양이 남은 픽업 가능 양보다 많은 경우
                    else if (pickups[pickupLastPoint] > curCap2) {
                        pickups[pickupLastPoint] -= curCap2
                        curCap2 = 0
                        break
                    }
                    // 이 집에 픽업 가능 양과 픽업해야 하는 양이 정확히 같은 경우
                    else {
                        pickups[pickupLastPoint] = 0
                        curCap2 = 0
                        pickupLastPoint--
                    }
                }
            }

            val curLastPoint = maxOf(maxDelivery + 1, maxPickup + 1)
            ans += curLastPoint * 2
        }
        return ans
    }
}