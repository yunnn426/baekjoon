import sys
input = sys.stdin.readline

casen = 0
while True:
    casen += 1
    l, p, v = map(int, input().split())
    if l == 0 and p == 0 and v == 0:
        break

    answer = 0
    answer += (v // p) * l
    answer += l if v % p > l else v % p
    print(f"Case {casen}: {answer}")

