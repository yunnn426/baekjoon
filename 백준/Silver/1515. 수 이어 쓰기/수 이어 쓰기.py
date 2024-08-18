import sys
input = sys.stdin.readline

seq = input().rstrip()

n = 0
idx = 0

while idx < len(seq):
    n += 1

    lst = list(str(n))

    # n에 해당 숫자가 있으면
    if seq[idx] in lst:
        # n과 숫자가 일치하는 동안 idx++
        for i in lst:
            if idx < len(seq) and i == seq[idx]:
                idx += 1

print(n)