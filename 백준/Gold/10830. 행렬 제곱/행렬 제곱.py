import sys, copy

n, b = map(int, sys.stdin.readline().split())

def multiply(res, arr):
    result = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            tmp = 0
            for k in range(n):
                tmp += (res[i][k] * arr[k][j]) % 1000
            result[i][j] = tmp % 1000

    return result

def arr_mul(y):
    if y == 1:
        return matrix
    
    if y % 2 == 0:
        tmp = arr_mul(y // 2)
        return multiply(tmp, tmp)
    
    else:
        tmp = arr_mul((y - 1) // 2)
        return multiply(multiply(tmp, tmp), matrix)


# main 
matrix = []
for _ in range(n):
    lst = list(map(int, sys.stdin.readline().split()))
    for i in range(n):
        lst[i] %= 1000
    matrix.append(lst)

ans = arr_mul(b)

for i in range(n):
    for j in range(n):
        print(ans[i][j], end=" ")
    print()