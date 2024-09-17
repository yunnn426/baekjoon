import sys
input = sys.stdin.readline

l, c = map(int, input().split())
alp = list(map(str, input().split()))
vowel = ['a', 'e', 'i', 'o', 'u'] # 모음
consonant = [] # 자음
for a in alp:
    if a not in vowel:
        consonant.append(a)

answer = []

def dfs(arr, idx):
    if len(arr) >= l:
        hasVow = 0
        hasCons = 0
        for i in arr:
            if i in vowel:
                hasVow += 1
            if i in consonant:
                hasCons += 1
        
        if hasVow >= 1 and hasCons >= 2: # 모음 1개 이상, 자음 2개 이상
            answer.append(sorted(arr))

        return
    
    for i in range(idx + 1, c):
        dfs(arr + [alp[i]], i)

dfs([], -1)

# 사전순
answer = sorted(answer)

for a in answer:
    for i in a:
        print(i, end="")
    print()