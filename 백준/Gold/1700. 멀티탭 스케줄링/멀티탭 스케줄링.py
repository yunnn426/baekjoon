import sys, copy
input = sys.stdin.readline

n, k = map(int, input().split())
order = list(map(int, input().split()))

plug = set()
answer = 0
for i in range(len(order)):
    # 자리 비었거나 이미 꽂혀있는 경우
    if len(plug) != n or order[i] in plug:
        plug.add(order[i])
        continue

    # 가장 먼 미래에 사용하는 아이템의 플러그를 뽑음
    temp = copy.deepcopy(plug)
    for j in range(i + 1, len(order)):
        # 뺄거 찾음
        if len(temp) == 1:
            break
        if order[j] in temp:
            temp.remove(order[j])
    plug.remove(list(temp)[0])
    answer += 1
    plug.add(order[i])

print(answer)