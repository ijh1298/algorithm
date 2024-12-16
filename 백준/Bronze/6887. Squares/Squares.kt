fun main() {
    val N = readln().toInt()

    var max = 0
    for (i in 0..N) {
        if (i * i > N) break
        max = i
    }
    println("The largest square has side length $max.")
}