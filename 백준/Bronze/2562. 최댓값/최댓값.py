maxn = 0
maxi = -1
for i in range(0, 9):
    num = int(input())
    if num > maxn:
        maxn = num
        maxi = i + 1

print(maxn)
print(maxi)