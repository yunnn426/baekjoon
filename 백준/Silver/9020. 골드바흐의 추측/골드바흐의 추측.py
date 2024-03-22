import math

n = int(input())

# 소수 계산 - 에라토스테네스의 체
isPrime = [1 for i in range(10010)] # 0~10000까지 소수 여부를 저장하는 배열: 1으로 초기화
isPrime[0] = 0
isPrime[1] = 0 # 0, 1은 소수 아님
for i in range(2, int(math.sqrt(10001))):
    j = 2
    while (i * j <= 10001):
        isPrime[i * j] = 0
        j += 1

for _ in range(n):
    num = int(input())
    
    ## 차이가 가장 작은 두 수를 찾아야함
    ## num // 2부터 출발해서 하나씩 감소시키며 찾음
    for i in range(num // 2, 0, -1): 
        if isPrime[i] == 1:
            diff = num - i
            if isPrime[diff] == 1:
                print(i, diff, sep=" ")
                break