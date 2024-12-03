fun main() {
    var N = readln().toInt()

    if (N == 3) {
        println("SK")
        return
    }

    var turn = true
    while (N != 1) {
        turn = !turn
        if (N > 4)
            --N
        else
            break
    }

    if (turn)
        println("SK")
    else
        println("CY")
}