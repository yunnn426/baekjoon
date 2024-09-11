import sys
input = sys.stdin.readline

n = int(input())
fs = {}
for _ in range(n):
    file = input().rstrip()
    idx = 0
    for i in range(len(file)):
        if file[i] == '.':
            idx = i
            break
    
    ext = file[idx + 1:]
    if ext in fs:
        fs[ext] += 1
    else:
        fs[ext] = 1

fs = sorted(fs.items())
for k, v in fs:
    print(k, v)