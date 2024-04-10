import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    score1 = []
    for i in range(n):
        a, b = map(int, input().split())
        score1.append((a, b, i)) # 서류-면접-번호 
    
    score1.sort()
    
    answer = 0
    a, b, tmp = score1[0]
    answer += 1
    # 서류 등수가 낮으면서 동시에 면접 등수도 낮을 수 없다
    for i in range(1, len(score1)):
        s1, s2, idx = score1[i]
        if a < s1 and b < s2:
            continue
        answer += 1
        a = min(a, s1)
        b = min(b, s2)

    print(answer)