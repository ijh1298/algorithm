N = int(input())
M = int(input())
str = input()

ioi = "IOI"
for i in range(1, N):
    ioi += "OI"

find = str.find(ioi)

cnt = 0
while find != -1:
    cnt += 1
    find = str.find(ioi, find + 1)

print(cnt)
