import sys
from collections import Counter
from functools import cmp_to_key
input = sys.stdin.readline

n, m = map(int, input().split())
words = [input().strip() for _ in range(n)]
note = set()

def cmp_func(x, y):
    # 1. 자주 나오는 단어 앞에
    if counter[x] != counter[y]:
        if counter[x] < counter[y]:
            return 1
        else: 
            return -1
    # 2. 단어가 길수록 앞에
    if len(x) != len(y):
        if len(x) < len(y):
            return 1
        else:
            return -1
    # 3. 알파벳 사전 순으로 앞에
    if x > y:
        return 1
    else:
        return -1

# 길이 m 미만 제외
for w in words:
    if len(w) < m:
        continue
    note.add(w)

# 카운터 생성
counter = Counter(words)

# 기준에 따라 정렬
note = sorted(note, key=cmp_to_key(cmp_func))

for n in note:
    print(n)