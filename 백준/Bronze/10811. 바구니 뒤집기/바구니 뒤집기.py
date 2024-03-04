n, m = map(int, input().split())
list = [i for i in range(1, n + 1)]

for _ in range(m):
    a, b = map(int, input().split())
    list[a-1:b] = reversed(list[a-1:b])

for i in list:
    print(i, end=" ")