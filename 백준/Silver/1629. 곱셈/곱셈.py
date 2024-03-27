import sys

a, b, c = map(int, sys.stdin.readline().split())

# 반복
# answer = 1
# while b > 0:
#     if b % 2 == 1:
#         answer = answer * a % c
#     a *= a
#     b //= 2

# print(answer)

#재귀
def power(y):
    if y == 1:
        return a % c
    if y % 2 == 1:
        n = power((y - 1) // 2)

        return n * n * a % c
    else:
        n = power(y // 2)

        return n * n % c
    
answer = power(b)
print(answer)