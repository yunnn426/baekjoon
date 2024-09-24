import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))

st = []
answer = [-1 for _ in range(n)]

# 입력 뒤에서부터 확인
for i in range(n - 1, -1, -1):
    # 스택에서 a[i]보다 큰 값이 나오기 전까지 pop
    while st and st[-1] <= a[i]:
        st.pop()
    
    # 스택이 비어있지 않으면 top이 오큰수
    if st: 
        answer[i] = st.pop()
        st.append(answer[i])
    
    st.append(a[i])

print(*answer)