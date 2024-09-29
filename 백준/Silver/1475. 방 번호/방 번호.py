from collections import Counter
import sys
input = sys.stdin.readline

n = input().rstrip()
c = Counter()

def addCounter(num, cmp):
    if c[num] < c[cmp]:
        c[num] += 1
    else:
        c[cmp] += 1

for i in range(len(n)):
    d = n[i]
    
    if d == '9':
        addCounter('6', '9')
        continue
    if d == '6':
        addCounter('9', '6')
        continue

    c.update(d)

print(max(c.values()))