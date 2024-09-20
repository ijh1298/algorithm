fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.`out`.bufferedWriter()
    val n = br.readLine().toInt()

    val hashMap = hashMapOf<String, Boolean>()

    repeat(n) {
        val (name, operation) = br.readLine().split(' ').map { it }
        if (operation == "enter")
            hashMap[name] = true
        else
            hashMap[name] = false
    }

    val ml = mutableListOf<String>()
    hashMap.forEach {
        if (it.value) ml += it.key
    }
    ml.sortedDescending().forEach {
        bw.write("$it\n")
    }
    bw.flush()
}