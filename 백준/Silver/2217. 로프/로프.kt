fun main() {
    val br = System.`in`.bufferedReader()
    val N = br.readLine().toInt()

    var arr = Array<Int>(N) { i -> 0 }
    for (i in 0..<N) {
        arr[i] = br.readLine().toInt()
    }
    arr.sort()

    var max = 0
    for (i in 0..<N) {
        if (arr[i] * (N - i) > max)
            max = arr[i] * (N - i)
    }

    print(max)
}