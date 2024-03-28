import sys

n, s = map(int, sys.stdin.readline().split())
seq = list(map(int, sys.stdin.readline().split()))
answer = 0

def search(sum, i):
    if i == n:
        if sum == s:
            global answer
            answer += 1
        return
    
    search(sum + seq[i], i + 1)
    search(sum, i + 1)

search(0, 0)
if s == 0:
    answer -= 1

print(answer)